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
ll MOD = 1000000000;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };


int n, m, k1, k2, v;
Vi st, el;
Pi ST(int j)
{
	Pi p = mp(-1, -1);
	auto it = lower_bound(ALL(st), j);
	if (it != st.end())p.Y = *it;
	if (it != st.begin())
	{
		it--;
		p.X = *it;
	}
	return p;
}
Pi EL(int j)
{
	Pi p = mp(-1, -1);
	auto it = lower_bound(ALL(el), j);
	if (it != el.end())p.Y = *it;
	if (it != el.begin())
	{
		it--;
		p.X = *it;
	}
	return p;
}
int main() {
	scanf("%d%d%d%d%d", &n, &m, &k1, &k2, &v);
	fup(i, 1, k1, 1)
	{
		int x;
		scanf("%d", &x);
		st.push_back(x);
	}
	fup(i, 1, k2, 1)
	{
		int x;
		scanf("%d", &x);
		el.push_back(x);
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if(x1==x2)
		{
		    printf("%d\n",(int)abs(y2-y1));
		    continue;
		}
		Pi S = ST(y1), E = EL(y1);
		int ans = INF;
		if (S.X != -1)
		{
			int t = S.X;
			ans = min(ans, (int)abs(y1 - t) + (int)abs(x2 - x1) + (int)abs(y2 - t));
		}
		if (S.Y != -1)
		{
			int t = S.Y;
			ans = min(ans, (int)abs(y1 - t) + (int)abs(x2 - x1) + (int)abs(y2 - t));
		}
		if (E.X != -1)
		{
			int t = E.X;
			int c = (int)abs(x2 - x1);
			ans = min(ans, (int)abs(y1 - t) + (int)abs(y2 - t) + (c - 1) / v + 1);
		}
		if (E.Y != -1)
		{
			int t = E.Y;
			int c = (int)abs(x2 - x1);
			ans = min(ans, (int)abs(y1 - t) + (int)abs(y2 - t) + (c - 1) / v + 1);
		}
		printf("%d\n", ans);
	}
}