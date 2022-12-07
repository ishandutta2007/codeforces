#include<cstdio>
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
#include<algorithm>
#include<list>
#include<functional>
#define mp make_pair
#define X first
#define Y second
#define INF 987654321
#define PI 3.14159265358979323846264
#define MOD 1000000007LL
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
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int parent[1000001];
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
int a[1000001];
Vi v[1000001];
Vi group[1000001];
int n;
inline ll sz(int x)
{
	return -parent[find(x)];
}
ll MAX()
{
	MEM_1(parent);
	ll res = 0;
	fup(i, 1, 1000000, 1)
	{
		for (int x : group[i])
		{
			for (int next : v[x])
				if (a[next] == a[x])merge(next, x);
		}
		for (int x : group[i])
		{
			if (x == find(x))
			{
				res += sz(x)*(sz(x) + 1) / 2 *i;
			}
		}
		for (int x : group[i])
		{
			for (int next : v[x])
				if (a[next] < a[x])
				{
					res += sz(next)*sz(x)*i;
					merge(x, next);
				}
		}
	}
	return res;
}
ll MIN()
{
	MEM_1(parent);
	ll res = 0;
	fdn(i, 1000000, 1, 1)
	{
		for (int x : group[i])
		{
			for (int next : v[x])
				if (a[next] == a[x])merge(next, x);
		}
		for (int x : group[i])
		{
			if (x == find(x))
			{
				res += sz(x)*(sz(x) + 1) / 2 * i;
			}
		}
		for (int x : group[i])
		{
			for (int next : v[x])
				if (a[next] > a[x])
				{
					res += sz(next)*sz(x)*i;
					merge(x, next);
				}
		}
	}
	return res;
}
int main() {
	scanf("%d", &n);
	fup(i, 1, n, 1)
	{
		scanf("%d", &a[i]);
		group[a[i]].push_back(i);
	}
	fup(i, 1, n - 1, 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	printf("%lld", MAX() - MIN());
}