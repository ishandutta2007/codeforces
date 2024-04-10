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
#define INF 1987654321
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
typedef pair<ld, ld> Pd;
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

Vi v[100001];
int parent[100001][17],b[100001][17], depth[100001];
void dfs(int N,int p,int d)
{
	depth[N]=d;
	for(int next:v[N])
	{
		if(next==p)continue;
		dfs(next,N,d+1);
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
int query1(int u,int x)
{
	int d=depth[x]-depth[u];
	int c=0;
	fdn(j,16,0,1)
	{
		if(d&(1<<j))
		{
			c|=b[x][j];
			x=parent[x][j];
		}
	}
	return c==1;
}
int query2(int u,int x)
{
	int d=depth[x]-depth[u];
	int c=0;
	fdn(j,16,0,1)
	{
		if(d&(1<<j))
		{
			c|=b[x][j];
			x=parent[x][j];
		}
	}
	return c==2;
}

int p[100001];
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
		p[b] = a;
	}
}
int main() {
	MEM_1(p);
	MEM_1(parent);
	int n;
	scanf("%d",&n);
	Vi R;
	fup(i,1,n,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==-1)R.pb(i);
		else
		{
			merge(i,x);
			parent[i][0]=x;
			v[i].pb(x);
			v[x].pb(i);
			b[i][0]=1<<y;
		}
	}
	for(auto r:R)dfs(r,-1,0);
	fup(j,0,15,1)
		fup(i,1,n,1)
		if (parent[i][j] != -1)
		{
			parent[i][j + 1] = parent[parent[i][j]][j];
			b[i][j+1]= b[i][j]|b[parent[i][j]][j];
		}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int o,x,y;
		scanf("%d%d%d",&o,&x,&y);
		if(find(x)!=find(y))
		{
			puts("NO");
			continue;
		}
		int u=LCA(x,y);
		bool res=0;
		if(o==1)
		{
			if(u==x && query1(u,y))res=1;
		}
		else
		{
			if(u==x)
			{
				if(query2(u,y))res=1;
			}
			else
			{
				if(query1(u,x) && query2(u,y))res=1;
			}
		}
		puts(res?"YES":"NO");
	}
}