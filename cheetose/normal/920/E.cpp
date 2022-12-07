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
#define MOD 900528LL
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
typedef vector<iii> Viii;
typedef complex<double> base;
ll POW(ll a, ll b, ll p) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1, p)) % p; ll t = POW(a, b / 2, p); return (t*t) % p; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0)return b; if (b == 0)return a; return a*b / gcd(a, b); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };


int parent[200001];
Vi v[200001];
bool chk[200001];
set<int> S;
set<int>::iterator it;
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
void dfs(int i)
{
	int N = v[i].size();
	if(S.find(i)!=S.end())S.erase(i);
	fup(j, 0, N - 2, 1)
	{
		int cur = v[i][j];
		int next = v[i][j + 1];
		while (!S.empty())
		{
			it = S.upper_bound(cur);
			if (it == S.end() || *it >= next)break;
			{
				merge(i, *it);
				dfs(*it);
			}
		}
	}
}
int main()
{
	MEM_1(parent);
	int n,m;
	scanf("%d%d", &n,&m);
	fup(i, 1, n, 1)
	{
		S.insert(i);
		v[i].push_back(0);
		v[i].push_back(n + 1);
	}
	fup(i, 0, m - 1, 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	fup(i, 1, n, 1)
	{
		if (v[i].empty())
		{
			puts("1");
			printf("%d", n);
			return 0;
		}
		sort(ALL(v[i]));
	}
	fup(i, 1, n, 1)
	{
		if (S.find(i)!=S.end())dfs(i);
	}
	Vi v;
	fup(i, 1, n, 1)if (parent[i] < 0)v.push_back(-parent[i]);
	sort(ALL(v));
	printf("%d\n", v.size());
	for (int x : v)printf("%d ", x);
}