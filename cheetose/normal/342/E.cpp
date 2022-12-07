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
#define INF 987654321
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

int sz[100001],p[100001],parent[100001][17],depth[100001],ans[100001];
bool kill[100001];
Vi v[100001];
void dfs(int N,int pp,int d){
    parent[N][0]=pp;
    depth[N]=d;
	for(int next:v[N])
	{
		if(next==pp)continue;
		dfs(next,N,d+1);
	}
}
int getSz(int N,int p){
    sz[N]=1;
    for(int next:v[N]){
        if(next==p || kill[N])continue;
        sz[N]+=getSz(next,N);
    }
    return sz[N];
}
int get_centroid(int N,int p,int cap){
    for(int next:v[N]){
        if(kill[next] || next==p)continue;
        if(sz[next]>cap) return get_centroid(next,N,cap);
    }
    return N;
}
void decompose(int N,int pp){
    int cap=getSz(N,-1)/2;
    int cen=get_centroid(N,-1,cap);
    p[cen]=pp;
    kill[cen]=1;
    for(int next:v[cen]){
        if(!kill[next])decompose(next,cen);
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
int dist(int x,int y)
{
	return depth[x]+depth[y]-2*depth[LCA(x,y)];
}
void upd(int N)
{
	int M=N;
	while(M>0)
	{
		ans[M]=min(ans[M],dist(M,N));
		M=p[M];
	}
}
int query(int N)
{
	int res=INF,M=N;
	while(M>0)
	{
		res=min(res,ans[M]+dist(M,N));
		M=p[M];
	}
	return res;
}
int main() {
	MEM_1(parent);
	int n,q;
	scanf("%d%d",&n,&q);
	fup(i,2,n,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,-1,0);
	fup(i,1,n,1)ans[i]=INF;
	fup(j,0,15,1)
		fup(i,1,n,1)
		if (parent[i][j] != -1)
			parent[i][j + 1] = parent[parent[i][j]][j];
	decompose(1,-1);
	upd(1);
	while(q--)
	{
		int o,x;
		scanf("%d%d",&o,&x);
		if(o==1)upd(x);
		else printf("%d\n",query(x));
	}
}