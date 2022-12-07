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

bool isprime(int x) {
	for (int i = 2;i * i <= x;i++) {
		if (x % i == 0)return 0;
	}
	return 1;
}
bool chk[100001];
int main() {
	fill(chk, chk + 100001, true);
	int n;
	scanf("%d", &n);
	Vi v;
	fup(i, 2, n, 1)if (isprime(i))v.pb(i);
	int N = v.size();
	int ans = 1;
	bool ok = 0;
	Vi vv;
	int i, j;
	for (i = 0;i < N;i++) {
		printf("B %d\n", v[i]);
		fflush(stdout);
		int real = 0;
		for (j = v[i];j <= n;j += v[i]) {
			real += chk[j];
			chk[j] = 0;
		}
		int x;
		scanf("%d", &x);
		if (real != x) {
			vv.pb(v[i]);
			break;
		}
		if (i % 100 == 99) {
			printf("A 1\n");
			fflush(stdout);
			int real = 0;
			for (int k = 1;k <= n;k++) {
				real += chk[k];
			}
			int x;
			scanf("%d", &x);
			if (real != x) {
				for (j = i / 100 * 100;j <= i;j++) {
					printf("A %d\n", v[j]);
					fflush(stdout);
					int x;
					scanf("%d", &x);
					if (x) {
						vv.pb(v[j]);
						ok = 1;
						break;
					}
				}
			}
		}
		if (ok)break;
	}
	if (!ok || i==N) {
		for (j = (i - 1) / 100 * 100;j < i;j++) {
			printf("A %d\n", v[j]);
			fflush(stdout);
			int x;
			scanf("%d", &x);
			if (x) {
				vv.pb(v[j]);
				break;
			}
		}
	}
	for (j = i + 1;j < N;j++) {
		printf("B %d\n", v[j]);
		fflush(stdout);
		int real = 0;
		for (int k = v[j];k <= n;k += v[j]) {
			real += chk[k];
			chk[k] = 0;
		}
		int x;
		scanf("%d", &x);
		if (real != x)vv.pb(v[j]);
	}
	for (int x : vv) {
		ans *= x;
		int c = x;
		while (1) {
			if (c > n / x)break;
			c *= x;
			printf("A %d\n", c);
			fflush(stdout);
			int y;
			scanf("%d", &y);
			if (y)ans *= x;
			else break;
		}
	}
	printf("C %d\n",ans);
	fflush(stdout);
	return 0;
}