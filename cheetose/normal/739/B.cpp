#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
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
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
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
typedef tuple<int, int, int, int> iiii;
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

int n,cc;
int parent[200001][18];
ll a[200001],d[200001],dist[200001];
Pi p[200001];
Vi v[200001];
int tree[400005];
void upd(int i, int k)
{
	while (i <= cc)
	{
		tree[i] += k;
		i += (i&-i);
	}
}
int sum(int i)
{
	int c = 0;
	while (i > 0)
	{
		c += tree[i];
		i -= (i&-i);
	}
	return c;
}
void dfs(int N,ll c)
{
	dist[N]=c;
	p[N].X=++cc;
	for(int next:v[N])
	{
		dfs(next,c+d[next]);
	}
	p[N].Y=++cc;
}
void to(int N)
{
	int now=N;
	fdn(i,17,0,1)
	{
		int next=parent[now][i];
		if(next==-1)continue;
		if(dist[N]-dist[next]<=a[N])now=next;
	}
	if(now==N)return;
	int u=now,v=parent[N][0];
	upd(p[u].X,1);
	upd(p[v].Y,-1);
}
int main() {
	MEM_1(parent);
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%lld",a+i);
	fup(i,2,n,1)
	{
		scanf("%d%lld",&parent[i][0],d+i);
		v[parent[i][0]].pb(i);
	}
	dfs(1,0);
	fup(j,0,16,1)
		fup(i,1,n,1)
		if (parent[i][j] != -1)
			parent[i][j + 1] = parent[parent[i][j]][j];
	fup(i,1,n,1)to(i);
	fup(i,1,n,1)printf("%d ",sum(p[i].X)-sum(p[i].Y));
}