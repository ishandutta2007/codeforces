#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#define mp make_pair
#define X first
#define Y second
#define INF 987654321
#define PI 3.14159265358979323846264
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
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
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM){ll ret = 1;for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret;}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if(a==0||b==0)return a+b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

ll fac[5001];
ll inv[5001];
ll nCr(int n, int r)
{
	ll c = fac[n];
	c = (c*inv[r]) % MOD;
	c = (c*inv[n - r]) % MOD;
	return c;
}
ll d[5001][5001];
int n, k;
ll go(int K, int a)
{
	ll &ret = d[K][a];
	if (ret != -1)return ret;
	int b = n - a;
	if (K == 0)return ret = POW(2, b, MOD);
	return ret = ((a > 0 ? (go(K - 1, a)*a) % MOD : 0LL) + (b > 0 ? ((go(K - 1, a + 1)*b) % MOD) : 0LL)) % MOD;
}
int main()
{
	scanf("%d%d", &n, &k);
	if (k >= n)
	{
		fac[0] = 1, inv[0] = 1;
		fup(i, 1, 5000, 1)
		{
			fac[i] = (fac[i - 1] * i) % MOD;
			inv[i] = POW(fac[i], MOD - 2, MOD);
		}
		ll ans = 0;
		fup(x, 1, n, 1)ans = (ans + (nCr(n, x)*POW(x, k, MOD)) % MOD) % MOD;
		return !printf("%I64d", ans);
	}
	MEM_1(d);
	printf("%I64d", go(k, 0));
}