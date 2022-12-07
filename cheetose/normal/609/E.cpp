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
typedef long double ld;
typedef double db;
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

bool chk[200000];
int n,m;
ll ans[200000];
struct edge{
	int x,y,z,i;
}e[200000];
VPi v[200001];

int Parent[200001];
int find(int a)
{
	if (Parent[a] < 0)return a;
	return Parent[a] = find(Parent[a]);
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b)
	{
		Parent[a] += Parent[b];
		Parent[b] = a;
	}
}

int parent[200001][19], cost[200001][19],depth[200001];
void dfs(int N,int p,int d,int c)
{
	depth[N]=d;
	parent[N][0]=p;
	cost[N][0]=c;
	for(auto next:v[N])
	{
		if(next.X==p)continue;
		dfs(next.X,N,d+1,next.Y);
	}
}
int LCA(int x, int y)
{
	if (depth[x] < depth[y])swap(x, y);
	int dif = depth[x] - depth[y];
	for (int j = 0; dif > 0; j++)
	{
		if (dif & 1)x = parent[x][j];
		dif /= 2;
	}

	if (x != y)
	{
		fdn(j,18,0,1)
		{
			if (parent[x][j] != -1 && parent[x][j] != parent[y][j])
			{
				x = parent[x][j];
				y = parent[y][j];
			}
		}
		x = parent[x][0];
	}
	return x;
}
int mmx(int u,int d)
{
	int res=0;
	int t=depth[d]-depth[u];
	int now=d;
	fdn(i,18,0,1)
	{
		if(t&(1<<i))
		{
			res=max(res,cost[now][i]);
			now=parent[now][i];
		}
	}
	return res;
}
int mx(int x,int y)
{
	int t=LCA(x,y);
	return max(mmx(t,x),mmx(t,y));
}
int main() {
	MEM_1(Parent);
	MEM_1(parent);
	MEM_1(depth);
	scanf("%d%d",&n,&m);
	fup(i,0,m-1,1)
	{
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
		e[i].i=i;
	}
	sort(e,e+m,[&](edge e1,edge e2){return e1.z<e2.z;});
	ll res=0;
	fup(i,0,m-1,1)
	{
		int x,y,z;
		x=e[i].x,y=e[i].y,z=e[i].z;
		if(find(x)==find(y))continue;
		v[x].pb(mp(y,z));
		v[y].pb(mp(x,z));
		res+=z;
		merge(x,y);
		chk[e[i].i]=1;
	}
	dfs(1,-1,0,0);
	fup(j,0,18,1)
		fup(i,1,n,1)
		if (parent[i][j] != -1)
		{
			parent[i][j + 1] = parent[parent[i][j]][j];
			cost[i][j+1]=max(cost[i][j],cost[parent[i][j]][j]);
		}
	fup(i,0,m-1,1)
	{
		if(chk[e[i].i])ans[e[i].i]=res;
		else
		{
			int x=e[i].x,y=e[i].y;
			ll z=e[i].z;
			ans[e[i].i]=res-mx(x,y)+z;
		}
	}
	fup(i,0,m-1,1)printf("%lld\n",ans[i]);
}