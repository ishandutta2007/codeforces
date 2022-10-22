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
int MOD = 1000000003;
ll POW(ll a, ll b, ll MMM){ll ret = 1;for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret;}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if(a==0||b==0)return a+b; return a*(b / gcd(a, b)); }
//int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

double dist(double X1, double Y1, double X2, double Y2)
{
	return sqrt((X1 - X2)*(X1 - X2) + (Y1 - Y2)*(Y1 - Y2));
}
int main()
{
	double r, x1, y1, x2, y2;
	scanf("%lf%lf%lf%lf%lf", &r, &x1, &y1, &x2, &y2);
	if (sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) >= r) return !printf("%.8f %.8f %.8f", x1, y1, r);
	double dx = x1 - x2, dy = y1 - y2;
	if (abs(dx) < 0.0001)
	{
		if (y2 < y1)
		{
			double y = y1 + r;
			return !printf("%.8f %.8f %.8f", x1, (y+y2)/2, (y-y2)/2);
		}
		else
		{
			double y = y1 - r;
			return !printf("%.8f %.8f %.8f", x1, (y2 + y) / 2, (y2 - y) / 2);
		}
	}
	double a = dy / dx;
	double b = y1 - a*x1;
	double c = b - y1;
	double xx1 = ((x1-a*c) - sqrt((x1 - a*c)*(x1 - a*c) - (a*a + 1)*(x1*x1 + c*c - r*r))) / (a*a + 1), xx2 = ((x1 - a*c) + sqrt((x1 - a*c)*(x1 - a*c) - (a*a + 1)*(x1*x1 + c*c - r*r))) / (a*a + 1);
	double yy1 = a*xx1 + b, yy2 = a*xx2 + b;
	if (dist(x2, y2, xx1, yy1) > dist(x2, y2, xx2, yy2))
	{
		return !printf("%.8f %.8f %.8f", (xx1+x2)/2, (yy1+y2)/2, dist(x2, y2, xx1, yy1)/2);
	}
	else
	{
		return !printf("%.8f %.8f %.8f", (xx2 + x2) / 2, (yy2 + y2) / 2, dist(x2, y2, xx2, yy2) / 2);
	}
}