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
#include<cassert>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define INF 2100000000
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
int MOD = 10000;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

ll d[61];
int lev(ll N)
{
	int c = -1;
	while (N)
	{
		c++;
		N /= 2;
	}
	return c;
}
inline ll num(int lev, ll k)
{
	return (((1LL << (lev + 1)) + k-d[lev])%(1LL<<lev)) +(1LL<<lev);
}
int main() {
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int c;
		scanf("%d", &c);
		if (c == 1)
		{
			ll x, y;
			scanf("%lld%lld", &x, &y);
			int t = lev(x);
			y %= (1LL << t);
			d[t] = (d[t] + y + (1LL << t)) % (1LL << t);
		}
		else if (c == 2)
		{
			ll x, y;
			scanf("%lld%lld", &x, &y);
			int t = lev(x);
			y %= (1LL << t);
			fup(z, t, 60, 1)
			{
				int tt = z - t;
				d[z] = (d[z] + y*(1LL << tt)+(1LL<<z)) % (1LL << z);
			}
		}
		else
		{
			ll x;
			scanf("%lld", &x);
			int t = lev(x);
			ll tt = ((x - (1LL << t)) + d[t]) % (1LL << t);
			for (; t >= 0; t--, tt /= 2)
			{
				printf("%lld ", num(t, tt));
			}
			puts("");
		}
	}
}