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

ll a[300001];
VPll v[300001];
ll ans;
ll go(int N, int p)
{
	if (N != 1 && v[N].size() == 1)
	{
		ans = max(ans, a[N]);
		return a[N];
	}
	Vll vv;
	for (Pll next : v[N])
	{
		if (next.X == p)continue;
		ll t = go(next.X,N);
		if (t >= next.Y)vv.pb(t - next.Y);
	}
	sort(vv.rbegin(), vv.rend());
	if (vv.size() >= 2)ans = max(ans, vv[0] + vv[1] + a[N]);
	if (vv.empty())return a[N];
	ans = max(ans, vv[0] + a[N]);
	return vv[0]+a[N];
}
int main() {
	int n;
	scanf("%d", &n);
	fup(i, 1, n, 1)scanf("%lld", a + i);
	if (n == 1)return !printf("%lld", a[1]);
	fup(i, 2, n, 1)
	{
		ll x, y, z;
		scanf("%lld%lld%lld", &x, &y,&z);
		v[x].pb(mp(y, z));
		v[y].pb(mp(x, z));
	}
	go(1, -1);
	printf("%lld", ans);
}