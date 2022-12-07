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
ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

typedef tuple<double, double, double> ddd;
ddd operator + (ddd d1, ddd d2)
{
	double a1, b1, c1, a2, b2, c2;
	tie(a1, b1, c1) = d1;
	tie(a2, b2, c2) = d2;
	return ddd(a1 + a2, b1 + b2, c1 + c2);
}
ddd d[101][101][101];
ddd mul(double xx, ddd D)
{
	double x, y, z;
	tie(x, y, z) = D;
	return ddd(x*xx, y*xx, z*xx);
}
ddd go(int r, int s, int p)
{
	if (r < 0 || s < 0 || p < 0)return ddd(0, 0, 0);
	if (r == 0 && s == 0)return ddd(0, 0, 1);
	if (r == 0 && p == 0)return ddd(0, 1, 0);
	if (s == 0 && p == 0)return ddd(1, 0, 0);
	ddd &ret = d[r][s][p];
	if (get<0>(ret) != -1)return ret;
	ret = ddd(0, 0, 0);
	int tot = r*s + s*p + p*r;
	ret = ret + mul((double)r*s / tot, go(r, s - 1, p)) + mul((double)s*p / tot, go(r, s, p - 1)) + mul((double)p*r / tot, go(r - 1, s, p));
	return ret;
}
int main() {
	fill(&d[0][0][0], &d[100][100][101], ddd(-1.0, -1.0, -1.0));
	int r, s, p;
	scanf("%d%d%d", &r, &s, &p);
	ddd ans = go(r, s, p);
	double x, y, z;
	tie(x, y, z) = ans;
	printf("%.10f %.10f %.10f", x, y, z);
}