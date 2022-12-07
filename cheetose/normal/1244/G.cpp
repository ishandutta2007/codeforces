#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
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
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
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
typedef vector<double> Vd;
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
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int ans[1000001];
int main() {
	int n;
	ll k;
	scanf("%d%lld", &n, &k);
	ll mn = 1LL * n*(n + 1) / 2;
	if (k < mn)return !printf("-1");
	ll tmp = 0;
	fup(i, 1, n, 1)tmp += max(i, n + 1 - i);
	if (k >= tmp)
	{
		printf("%lld\n", tmp);
		fup(i, 1, n, 1)printf("%d ", i);
		puts("");
		fdn(i, n, 1, 1)printf("%d ", i);
		puts("");
		return 0;
	}
	printf("%lld\n", k);
	k -= mn;
	int t = (n + 1) / 2;
	fup(i, (n + 3) / 2, n, 1)
	{
		int c = (int)min((ll)t, k);
		ans[i - c] = i;
		k -= c;
	}
	t = 1;
	fup(i, 1, (n + 1) / 1, 1)
	{
		while (t <= n&&ans[t])t++;
		ans[t] = i;
	}
	fup(i, 1, n, 1)printf("%d ", ans[i]);
	puts("");
	fup(i, 1, n, 1)printf("%d ", i);
	puts("");
}