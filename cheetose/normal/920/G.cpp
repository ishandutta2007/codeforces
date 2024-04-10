#include<cstdio>
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
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#define mp make_pair
#define X first
#define Y second
#define INF 987654321
#define PI 3.14159265358979323846264
#define MOD 900528LL
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
typedef vector<iii> Viii;
typedef complex<double> base;
ll POW(ll a, ll b, ll p) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1, p)) % p; ll t = POW(a, b / 2, p); return (t*t) % p; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0)return b; if (b == 0)return a; return a*b / gcd(a, b); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };
int DX[] = { 1,1,-1,-1 }, DY[] = { 1,-1,-1,1 };

Vi divs[1000001];
bool prime[1000001];
VPll v;
ll cnt(ll x)
{
	ll res = 0;
	for (const Pll& p : v)
	{
		res += x / p.X*p.Y;
	}
	return res;
}
int main()
{
	fill(prime + 2, prime + 1000001, true);
	fup(i, 2, 1000000, 1)
	{
		if (!prime[i])continue;
		fup(j, i + i, 1000000, i)prime[j] = 0;
		fup(j, i, 1000000, i)divs[j].push_back(i);
	}
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		ll x, p, k;
		scanf("%lld%lld%lld", &x, &p, &k);
		v.clear();
		int n = divs[p].size();
		fup(i, 0, (1 << n) - 1, 1)
		{
			int c = 0;
			ll t = 1;
			fup(k, 0, n - 1, 1)
			{
				if (i&(1 << k))
				{
					t *= divs[p][k];
					c++;
				}
			}
			if (c & 1)v.push_back(Pll(t, -1));
			else v.push_back(Pll(t, 1));
		}
		k += cnt(x);
		ll l = 1, r = 1000000000000;
		while (l <= r)
		{
			ll m = (l + r) / 2;
			if (cnt(m) >= k)r = m - 1;
			else l = m + 1;
		}
		printf("%lld\n", l);
	}
}