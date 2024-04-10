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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

VPi v[200001];
Vi vv[200001];
int num[200001],low[200001],x[200000],y[200000];
bool chk[200000];
int n,m,s,c;
void dfs(int N,int pp)
{
	num[N]=low[N]=++c;
	for(auto p:v[N])
	{
		if(p.X==pp)continue;
		if(!num[p.X])
		{
			dfs(p.X,N);
			if(low[p.X]>num[N])chk[p.Y]=1;
			low[N]=min(low[N],low[p.X]);
		}
		else low[N]=min(low[N],num[p.X]);
	}
}
ll parent[200001],w[200001];
int sz[200001];
int find(int a)
{
	if (parent[a]==a)return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b)
	{
		w[a]+=w[b];
		sz[a]+=sz[b];
		parent[b] = a;
	}
}
ll ans;
bool cc[200001];
ll dfs2(int N,int p,ll tmp)
{
	if(sz[N]>=3)
	{
		cc[N]=1;
		tmp=0;
	}
	if(N!=find(s) && vv[N].size()==1)
	{
		if(sz[N]>=3)ans+=w[N];
		else tmp+=w[N];
		return tmp;
	}
	ll ret=0;
	for(int next:vv[N])
	{
		if(next==p)continue;
		ret=max(ret,dfs2(next,N,tmp));
		if(cc[next])cc[N]=1;
	}
	if(cc[N])ans+=w[N];
	else ret+=w[N];
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)
	{
		scanf("%lld",w+i);
		parent[i]=i;
		sz[i]=1;
	}
	if(n==1)return !printf("%lld",w[1]);
	fup(i,0,m-1,1)
	{
		scanf("%d%d",&x[i],&y[i]);
		v[x[i]].pb(mp(y[i],i));
		v[y[i]].pb(mp(x[i],i));
	}
	scanf("%d",&s);
	dfs(s,-1);
	fup(i,0,m-1,1)
		if(!chk[i])merge(x[i],y[i]);
	fup(i,0,m-1,1)
		if(chk[i])
		{
			vv[find(x[i])].pb(find(y[i]));
			vv[find(y[i])].pb(find(x[i]));
		}
	ll t=dfs2(find(s),-1,0);
	printf("%lld",ans+t);
}