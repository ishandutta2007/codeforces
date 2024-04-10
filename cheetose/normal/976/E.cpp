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
#define INF 1987654321
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
ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Pll p[200000];
int n, a, b;
int main() {
	scanf("%d%d%d", &n,&a,&b);
	ll ans = 0;
	fup(i, 0, n - 1, 1)
	{
		scanf("%lld%lld", &p[i].X, &p[i].Y);
		ans += p[i].Y;
	}
	if (b == 0)return !printf("%lld", ans);
	sort(p, p + n, [&](Pll p1, Pll p2) {
		return p1.X - p1.Y > p2.X - p2.Y;
	});
	b = min(b, n);
	ll res = ans;
	fup(i, 0, b - 1, 1)if (p[i].X > p[i].Y)ans += p[i].X - p[i].Y;
	fup(i, 0, n - 1, 1)
	{
		ll temp = ans;
		if (i < b)
		{
			temp += max(p[i].X << a, p[i].Y) - p[i].Y;
			temp -= max(0LL, p[i].X - p[i].Y);
		}
		else
		{
			temp += max(p[i].X << a, p[i].Y) - p[i].Y;
			temp -= max(0LL, p[b - 1].X - p[b - 1].Y);
		}
		res = max(res, temp);
	}
	printf("%lld", res);
}