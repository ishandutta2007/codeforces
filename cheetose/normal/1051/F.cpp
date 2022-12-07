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
#define y0 y12
#define y1 y22
#define INF 987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
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
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

ll dist[100001];
int n,m;
VPi v[100001],vv[100001];
int x[100001],y[100001],z[100001],t[100001];
int p[100001],parent[100001][17],depth[100001];
ll d[42][100001];
bool chk[100001];
int find(int a)
{
	if (p[a] < 0)return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b)
	{
		p[a] += p[b];
		p[b] = a;
	}
}
void dfs(int N,int p,ll d,int D)
{
	dist[N]=d;
	depth[N]=D;
	parent[N][0]=p;
	for(auto& P:vv[N])
	{
		if(P.X==p)continue;
		dfs(P.X,N,d+P.Y,D+1);
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
		fdn(j,16,0,1)
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
Vi V;
void dij(int i)
{
	MEM0(chk);
	int S=V[i];
	priority_queue<Pll> q;
	d[i][S] = 0;
	q.push({ 0,S });
	while (!q.empty())
	{
		int x = q.top().Y;
		q.pop();
		if (chk[x])continue;
		chk[x] = 1;
		for (const auto& p : v[x])
		{
			int next = p.X, cost = p.Y;
			if (d[i][next] > d[i][x]+cost)
			{
				d[i][next] = d[i][x] + cost;
				q.push({ -d[i][next],next });
			}
		}
	}
}
int main() {
	fill(&d[0][0],&d[41][100001],INF);
	MEM_1(p);
	MEM_1(parent);
	scanf("%d%d",&n,&m);
	fup(i,1,m,1)
	{
		scanf("%d%d%d",x+i,y+i,z+i);
		v[x[i]].pb(mp(y[i],z[i]));
		v[y[i]].pb(mp(x[i],z[i]));
		t[i]=i;
	}
	sort(t+1,t+m+1,[&](int x,int y){
		return z[x]<z[y];
	});
	fup(ii,1,m,1)
	{
		int i=t[ii];
		if(find(x[i])==find(y[i]))
		{
			V.pb(x[i]);
			V.pb(y[i]);
		}
		else
		{
			merge(x[i],y[i]);
			vv[x[i]].pb(mp(y[i],z[i]));
			vv[y[i]].pb(mp(x[i],z[i]));
		}
	}
	int N=V.size();
	assert(N<=42);
	fup(i,0,N-1,1)dij(i);
	dfs(1,-1,0,0);
	fup(j,0,15,1)
		fup(i,1,n,1)
		if (parent[i][j] != -1)
			parent[i][j + 1] = parent[parent[i][j]][j];
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		ll ans=dist[xx]+dist[yy]-2*dist[LCA(xx,yy)];
		fup(i,0,N-1,1)ans=min(ans,d[i][xx]+d[i][yy]);
		printf("%lld\n",ans);
	}
}