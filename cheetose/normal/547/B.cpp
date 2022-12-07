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
ll MOD = 1999;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int a[200000];
Vi v;
inline int getidx(int x)
{
	return lower_bound(ALL(v), x) - v.begin();
}
int parent[200000];
int find(int a)
{
	if (parent[a] < 0)return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b)
	{
		parent[a] += parent[b];
		parent[b] = a;
	}
}
int ans[200001];
Vi vv[200000];
int main() {
	MEM_1(ans);
	MEM_1(parent);
	int n;
	scanf("%d", &n);
	fup(i, 0, n - 1, 1)
	{
		scanf("%d", a + i);
		v.push_back(a[i]);
	}
	ans[1] = *max_element(a, a + n);
	sort(ALL(v));
	v.resize(unique(ALL(v)) - v.begin());
	fup(i, 0, n - 1, 1)
	{
		a[i] = getidx(a[i]);
		vv[a[i]].push_back(i);
	}
	int N = v.size();
	ans[1] = getidx(ans[1]);
	int t = 1;
	fdn(i, N - 1, 0, 1)
	{
		for (int x : vv[i])
		{
			if (x != 0 && a[x - 1] >= i)
			{
				merge(x, x - 1);
				int tt = -parent[find(x)];
				if (tt > t)
				{
					ans[tt] = i;
					t = tt;
				}
			}
			if (x != n-1 && a[x + 1] >= i)
			{
				merge(x, x + 1);
				int tt = -parent[find(x)];
				if (tt > t)
				{
					ans[tt] = i;
					t = tt;
				}
			}
		}
	}
	fdn(i, n-1, 1, 1)if (ans[i] == -1)ans[i] = ans[i + 1];
	fup(i, 1, n, 1)printf("%d ", v[ans[i]]);
}