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

Pd p[200000];
int n;
double T;
bool ok(double kk)
{
	double res = 0, k = kk;
	fup(i, 0, n - 1, 1)
	{
		if (k == 0)break;
		double x = p[i].X, t = p[i].Y;
		if (k >= x)
		{
			res += x*t;
			k -= x;
		}
		else
		{
			res += k*t;
			k = 0;
		}
	}
	return res <= T*kk;
}
bool ok2(double kk)
{
	double res = 0, k = kk;
	fup(i, 0, n - 1, 1)
	{
		if (k == 0)break;
		double x = p[i].X, t = p[i].Y;
		if (k >= x)
		{
			res += x*t;
			k -= x;
		}
		else
		{
			res += k*t;
			k = 0;
		}
	}
	return res >= T*kk;
}
int main()
{
	double wsum = 0, wmul = 0;
	double mm = 987654321.0, MM = -1;
	scanf("%d%lf", &n, &T);
	fup(i, 0, n - 1, 1)
	{
		scanf("%lf", &p[i].X);
		wsum += p[i].X;
	}
	fup(i, 0, n - 1, 1)
	{
		scanf("%lf", &p[i].Y);
		wmul += p[i].X*p[i].Y;
		mm = min(mm, p[i].Y);
		MM = max(MM, p[i].Y);
	}
	if (T > MM || T < mm)return puts("0");
	if (T*wsum < wmul)
	{
		sort(p, p + n, [&](Pd p1, Pd p2) {return p1.Y < p2.Y; });
		double l = 0, r = wsum;
		fup(kk, 1, 80, 1)
		{
			double k = (l + r) / 2;
			if (ok(k))l = k;
			else r = k;
		}
		return !printf("%.8f", r);
	}
	else
	{
		sort(p, p + n, [&](Pd p1, Pd p2) {return p1.Y > p2.Y; });
		double l = 0, r = wsum;
		fup(kk, 1, 80, 1)
		{
			double k = (l + r) / 2;
			if (ok2(k))l = k;
			else r = k;
		}
		return !printf("%.8f", r);
	}
}