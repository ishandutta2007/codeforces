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
#define INF 987654321987654321
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
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Vi v[100001];
Vi p[100001][17];
int parent[100001][17], depth[100001];
void dfs(int N,int p,int d)
{
	depth[N]=d;
	parent[N][0]=p;
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
void upd(Vi &A,Vi &v1,Vi &v2)
{
	int N=v1.size(),M=v2.size();
	int i=0,j=0;
	while(A.size()<10)
	{
		if(i==N && j==M)break;
		int t1=i==N?INF:v1[i];
		int t2=j==M?INF:v2[j];
		if(t1<t2)A.pb(t1),i++;
		else A.pb(t2),j++;
	}
}
void qq(Vi &V,int uu,int vv)
{
	int de=depth[vv]-depth[uu]+1;
	int now=vv;
	fdn(i,16,0,1)
	{
		if(de&(1<<i))
		{
			for(int x:p[now][i])V.pb(x);
			now=parent[now][i];
		}
	}
}
void query(int uu,int vv,int a)
{
	int t=LCA(uu,vv);
	Vi V;
	qq(V,t,uu);
	qq(V,t,vv);
	sort(ALL(V));
	V.resize(unique(ALL(V))-V.begin());
	int k=min((int)V.size(),a);
	printf("%d ",k);
	fup(i,0,k-1,1)printf("%d ",V[i]);
	puts("");
}
int main() {
	MEM_1(parent);
	MEM_1(depth);
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	fup(i,2,n,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	fup(i,1,m,1)
	{
		int x;
		scanf("%d",&x);
		if(p[x][0].size()<10)p[x][0].pb(i);
	}
	dfs(1,-1,0);
	fup(j,0,15,1)
		fup(i,1,n,1)
		if (parent[i][j] != -1)
		{
			parent[i][j + 1] = parent[parent[i][j]][j];
			upd(p[i][j+1],p[i][j],p[parent[i][j]][j]);
		}
	while(q--)
	{
		int u,v,a;
		scanf("%d%d%d",&u,&v,&a);
		query(u,v,a);
	}
}