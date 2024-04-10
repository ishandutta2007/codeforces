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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

VPll v1, v2, v3, v4;
int main() {
	int n;
	scanf("%d", &n);
	int ans = 0;
	fup(i, 0, n - 1, 1)
	{
		ll x, y;
		scanf("%lld%lld", &x, &y);
		if (x >= 0 && y>=0)v1.push_back(mp(x, y));
		else if (x<0 && y >= 0)v2.push_back(mp(x, y));
		else if (x<0 && y < 0)v3.push_back(mp(x, y));
		else v4.push_back(mp(x, y));
		if (x != 0 && y != 0)ans += 6;
		else ans += 4;
	}
	sort(ALL(v1));
	sort(ALL(v2), [&](Pll p1, Pll p2) {
		if (p1.X != p2.X)return p1.X > p2.X;
		return p1.Y < p2.Y;
	});
	sort(v3.rbegin(), v3.rend());
	sort(ALL(v4), [&](Pll p1, Pll p2) {
		if (p1.X != p2.X)return p1.X < p2.X;
		return p1.Y > p2.Y;
	});
	printf("%d\n", ans);
	for (auto &p : v1)
	{
		ll x, y;
		tie(x, y) = p;
		if (x != 0)printf("1 %lld R\n", x);
		if (y != 0)printf("1 %lld U\n", y);
		puts("2");
		if (y != 0)printf("1 %lld D\n", y);
		if (x != 0)printf("1 %lld L\n", x);
		puts("3");
	}
	for (auto &p : v2)
	{
		ll x, y;
		tie(x, y) = p;
		x *= -1;
		if (x != 0)printf("1 %lld L\n", x);
		if (y != 0)printf("1 %lld U\n", y);
		puts("2");
		if (y != 0)printf("1 %lld D\n", y);
		if (x != 0)printf("1 %lld R\n", x);
		puts("3");
	}
	for (auto &p : v3)
	{
		ll x, y;
		tie(x, y) = p;
		x *= -1;
		y *= -1;
		if (x != 0)printf("1 %lld L\n", x);
		if (y != 0)printf("1 %lld D\n", y);
		puts("2");
		if (y != 0)printf("1 %lld U\n", y);
		if (x != 0)printf("1 %lld R\n", x);
		puts("3");
	}
	for (auto &p : v4)
	{
		ll x, y;
		tie(x, y) = p;
		y *= -1;
		if (x != 0)printf("1 %lld R\n", x);
		if (y != 0)printf("1 %lld D\n", y);
		puts("2");
		if (y != 0)printf("1 %lld U\n", y);
		if (x != 0)printf("1 %lld L\n", x);
		puts("3");
	}
}