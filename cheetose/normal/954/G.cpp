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
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

ll a[500000], t[500000];
int n, r;
ll k;
bool ok(ll K)
{
	ll res = 0, now = 0;
	fup(i, 0, n - 1, 1)t[i] = a[i];
	fup(i, 0, r - 1, 1)now += t[i];
	fup(i, 0, n - 1, 1)
	{
		if (i + r < n)now += t[i + r];
		if (i - r - 1>= 0)now -= t[i - r - 1];
		if (now < K)
		{
			ll tt = K - now;
			res += tt;
			if (res > 1100000000000000000)return 0;
			now = K;
			t[min(i + r, n - 1)] += tt;
		}
	}
	return res <= k;
}
int main()
{
	scanf("%d%d%lld", &n, &r, &k);
	fup(i, 0, n - 1, 1)
		scanf("%lld", a + i);
	ll L = 0, R = 1100000000000000000;
	while (L <= R)
	{
		ll K = (L + R) / 2;
		if (ok(K))L = K + 1;
		else R = K - 1;
	}
	printf("%lld", R);
}