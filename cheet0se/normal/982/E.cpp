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
int MOD = 1000000;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Pll exgcd(ll a, ll b) 
{
	if (!b) return{ 1, 0 };
	ll x, y;
	tie(x, y) = exgcd(b, a%b);
	return{ y, x - (a / b)*y };
}

ll n, m, x, y;
int vx, vy;
int res()
{

	if (vx == 0)
	{
		if (x != 0 && x != n)return -1;
		if (x == 0)
		{
			if (vy == 1)return 2;
			else return 0;
		}
		else
		{
			if (vy == 1)return 3;
			else return 1;
		}
	}
	if (vy == 0)
	{
		if (y != 0 && y != m)return -1;
		if (y == 0)
		{
			if (vx == 1)return 1;
			else return 0;
		}
		else
		{
			if (vx == 1)return 3;
			else return 2;
		}
	}
	int par = 0;
	if (vx == -1)
	{
		x = n - x;
		par ^= 1;
	}
	if (vy == 1)
	{
		y = m - y;
		par ^= 2;
	}
	ll A = n, B = m, C = x + y;
	ll g = gcd(n, m);
	if (C % g != 0)return -1;
	ll t = C / g;
	Pll p = exgcd(A, B);
	A /= g, B /= g;
	p.X *= t, p.Y *= t;
	if (p.X > B) {
		ll tt = p.X / B;
		p.X -= tt * B;
		p.Y += tt * A;
	}
	if (p.X <= 0) {
		ll tt = -p.X / B + 1;
		p.X += tt * B;
		p.Y -= tt * A;
	}
	return ((p.X & 1) + (p.Y & 1) * 2) ^ par;
}
int main() {
	scanf("%lld%lld%lld%lld%d%d", &n, &m, &x, &y, &vx, &vy);
	int ans = res();
	if (ans == -1)return !printf("-1");
	if (ans == 0)return !printf("0 0");
	if (ans == 1)return !printf("%lld 0",n);
	if (ans == 2)return !printf("0 %lld",m);
	if (ans == 3)return !printf("%lld %lld",n,m);
}