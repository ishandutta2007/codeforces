#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define COMPRESS(a) sort(ALL(a));a.resize(unique(ALL(a))-a.begin())
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a * a) % MMM)if (b & 1)ret = (ret * a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Vi v[500005];
int a[1000005], n;
bool chk[1000005], cc[500005];
void dfs(int N) {
	cc[a[N]] = 1;
	chk[N] = 1;
	int next = N <= n ? N + n : N - n;
	int rn = v[a[next]][0];
	if (next == rn)rn = v[a[next]][1];
	if (!cc[a[rn]])dfs(rn);
}
int main() {
	scanf("%d", &n);
	if (n & 1) {
		printf("Second\n");
		fflush(stdout);
		fup(i, 1, 2 * n, 1) {
			int x;
			scanf("%d", &x);
			v[x].pb(i);
			a[i] = x;
		}
		fup(i, 1, 2 * n, 1) {
			if (!cc[a[i]])dfs(i);
		}
		ll sum = 0;
		fup(i, 1, 2 * n, 1)if (chk[i])sum += i;
		bool ok = 0;
		if (sum % (2 * n) == 0)ok = 1;
		if (ok) {
			fup(i, 1, 2 * n, 1)if (chk[i])printf("%d ", i);
		}
		else {
			fup(i, 1, 2 * n, 1)if (!chk[i])printf("%d ", i);
		}
		puts("");
		fflush(stdout);
		int x;
		scanf("%d", &x);
		return 0;
	}
	else {
		printf("First\n");
		fup(i, 1, 2 * n, 1) {
			if (i <= n)printf("%d ", i);
			else printf("%d ", i - n);
		}
		puts("");
		fflush(stdout);
		int x;
		scanf("%d", &x);
		return 0;
	}
}