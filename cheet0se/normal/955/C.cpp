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
#define INF 987654321987654321
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
int MOD = 20000303;
//ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll POW(ll a, ll b) { ll ret = 1; for (; b; b >>= 1, a = (a*a))if (b & 1)ret = (ret*a); return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

bool prime[101];
int mu[101];
void get_mu()
{
	int i, j;
	for (i = 1; i <= 100; i++)
	{
		mu[i] = 1;
		prime[i] = 1;
	}
	prime[1] = 0;
	for (i = 2; i <= 100; i++)
	{
		if (prime[i] == 1)
		{
			mu[i] = -mu[i];
			for (j = 2; i*j <= 100; j++)
			{
				prime[i*j] = 0;
				if (j%i == 0)
				{
					mu[i*j] = 0;
				}
				else
				{
					mu[i*j] = -mu[i*j];
				}
			}
		}
	}
}
ll pow_(ll x, ll k)
{
	ll t = (ll)pow(x, 1.0 / k);
	if (POW(t + 1, k) == x)return t + 1;
	return t;
}
VPll v[64];
ll cnt(ll x)
{
	if (x == 0)return 0;
	ll res = (ll)sqrt(x);
	ll tot = 2;
	fup(i, 3, 63, 1)
	{
		if (!prime[i])continue;
		ll t = pow_(x, i);
		if (t == 1)break;
		res += t-1;
		for(const auto& p:v[i])
		{
			ll j = p.X;
			ll tt = pow_(t, j);
			if (tt == 1)break;
			res += p.Y*(tt-1);
		}
	}
	return res;
}
int main()
{
	get_mu();
	v[3].push_back(mp(2, -1));
	int prev=3, vsz = 1;
	fup(i, 4, 63, 1)
	{
		if (!prime[i])continue;
		fup(j, 0, vsz - 1, 1)
		{
			v[i].push_back(mp(v[prev][j].X, v[prev][j].Y));
			ll next = v[prev][j].X*prev;
			if (next > 63)continue;
			v[i].push_back(mp(next, -v[prev][j].Y));
		}
		v[i].push_back(mp(prev, -1));
		sort(ALL(v[i]));
		prev = i, vsz = v[i].size();
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		ll x, y;
		scanf("%lld%lld", &x, &y);
		printf("%lld\n", cnt(y) - cnt(x - 1));
	}
}