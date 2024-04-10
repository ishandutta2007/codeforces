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
#define INF 987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

ll d[100001][3][11];
ll a[3][11], b[3][11];
Vi v[100001];
int n, m, k, x;
void dfs(int N, int p)
{
	bool ok = 0;
	for (int next : v[N])
	{
		if (next == p)continue;
		ok = 1;
		dfs(next, N);
	}
	if (!ok)
	{
		d[N][0][0] = k - 1;
		d[N][1][1] = 1;
		d[N][2][0] = m - k;
		return;
	}
	MEM0(a);
	MEM0(b);
	fup(i, 0, 2, 1)a[i][0] = 1;
	for (int next : v[N])
	{
		if (next == p)continue;
		fup(l,0,x,1)
			fup(r, 0, x, 1)
		{
			if (l + r > x)continue;
			ll t = (d[next][0][r] + d[next][1][r] + d[next][2][r]) % MOD;
			b[0][l + r] = (b[0][l + r] + a[0][l] * t) % MOD;

			t = d[next][0][r];
			b[1][l + r] = (b[1][l + r] + a[1][l] * t) % MOD;

			t = (d[next][0][r] + d[next][2][r]) % MOD;
			b[2][l + r] = (b[2][l+r] + a[2][l] * t) % MOD;
		}
		fup(i, 0, 2, 1)fup(j, 0, x, 1)a[i][j] = b[i][j], b[i][j] = 0;
	}
	fup(l, 0, x, 1)
	{
		d[N][0][l] = (a[0][l] * (k - 1)) % MOD;
		if (l > 0)d[N][1][l] = a[1][l - 1];
		d[N][2][l] = (a[2][l] * (m - k)) % MOD;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	fup(i, 2, n, 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].pb(y);
		v[y].pb(x);
	}
	scanf("%d%d", &k, &x);
	dfs(1, -1);
	ll ans = 0;
	fup(i, 0, 2, 1)fup(j, 0, x, 1)ans = (ans + d[1][i][j]) % MOD;
	printf("%lld", ans);
}