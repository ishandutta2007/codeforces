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
ll MOD = 1000000000;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Vi v;
VPi pr;
int d[1000001], MAX[1000001];
int main() {
	int n, a, b;
	scanf("%d", &n);
	fup(i, 0, n - 1, 1)
	{
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}
	sort(ALL(v));
	v.erase(unique(ALL(v)), v.end());
	scanf("%d%d", &a, &b);
	int N = a - b;
	for (int x : v)
	{
		int fi = ((b - 1) / x + 1)*x;
		fup(i, fi, a, x)
			MAX[i - b] = x;
	}
	pr.push_back(mp(-a,0));
	fdn(i, a-1, b, 1)
	{
		int ii = i - b;
		int t = MAX[ii];
		d[ii] = d[ii + 1] + 1;
		if (t != 0)
		{
			int tt = lower_bound(ALL(pr), mp(-i - t + 1, -1)) - pr.begin();
			if (tt != (int)pr.size())
			{
				d[ii] = min(d[ii], pr[tt].Y + 1);
			}
		}
		while (!pr.empty() && pr.back().Y >= d[ii])pr.pop_back();
		pr.push_back(mp(-i, d[ii]));
	}
	printf("%d", d[0]);
}