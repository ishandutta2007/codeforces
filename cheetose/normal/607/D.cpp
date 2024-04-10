#include <bits/stdc++.h>
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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

ll a[200005];
int n=1,q;
int q1[200005],q2[200005];
Vi v[200005];
ll tree[524288],lazy1[524288],lazy2[524288];
int cnt[200005],parent[200005],s[200005],e[200005],cc;
void init(int node, int S, int E)
{
	lazy1[node]=1;
	if (S == E)
	{
		if(S==1)tree[node] = a[S];
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
	tree[node] = (tree[2 * node] + tree[2 * node + 1])%MOD;
}
void propagation(int node, int S, int E)
{
	tree[node]=(tree[node]*lazy1[node]+lazy2[node]*(E-S+1))%MOD;
	if(S!=E)
	{
		fup(next,node*2,node*2+1,1)
		{
			lazy1[next]=(lazy1[next]*lazy1[node])%MOD;
			lazy2[next]=(lazy2[next]*lazy1[node]+lazy2[node])%MOD;
		}
	}
	lazy1[node]=1,lazy2[node]=0;
}
void upd(int node, int S, int E, int i, int j, int p1, int p2)
{
	propagation(node, S, E);
	if (i > E || j < S) return;
	if (j >= E && i <= S)
	{
		if(p1==1)
		{
			lazy2[node]=(lazy2[node]+p2)%MOD;
		}
		else if(p1==2)
		{
			lazy1[node]=(lazy1[node]*p2)%MOD;
			lazy2[node]=(lazy2[node]*p2)%MOD;
		}
		else 
		{
			lazy1[node]=0,lazy2[node]=p2;
		}
		propagation(node, S, E);
		return;
	}
	upd(2 * node, S, (S + E) / 2, i, j, p1, p2);
	upd(2 * node + 1, (S + E) / 2 + 1, E, i, j, p1 ,p2);
	tree[node] = (tree[2 * node] + tree[2 * node + 1])%MOD;
}
ll find(int node, int S, int E, int i, int j)
{
	propagation(node, S, E);
	if (i > E || j < S) return 0;
	if (j >= E && i <= S) return tree[node];
	return (find(node * 2, S, (S + E) / 2, i, j) + find(2 * node + 1, (S + E) / 2 + 1, E, i, j))%MOD;
}
void dfs(int N){
	s[N]=++cc;
	for(int next:v[N]){
		dfs(next);
	}
	e[N]=cc;
}
int main(){
	scanf("%lld%d",a+1,&q);
	fup(i,0,q-1,1){
		scanf("%d",q1+i);
		if(q1[i]==1){
			scanf("%d%lld",q2+i,&a[++n]);
			parent[n]=q2[i];
			v[q2[i]].pb(n);
			q2[i]=n;
		}else{
			scanf("%d",q2+i);
		}
	}
	dfs(1);
	init(1,1,n);
	fup(i,0,q-1,1){
		if(q1[i]==1){
			int x=q2[i];
			int par=parent[x];
			cnt[par]++;
			int mul=1LL*(cnt[par]+1)*POW(cnt[par],MOD-2)%MOD;
			upd(1,1,n,s[par],e[par],2,mul);
			int t=1LL*POW(a[par],MOD-2)*find(1,1,n,s[par],s[par])%MOD;
			upd(1,1,n,s[x],s[x],3,t*a[x]%MOD);
		}else{
			int x=q2[i];
			int par=parent[x];
			ll res=find(1,1,n,s[x],e[x]);
			if(x!=1){
				ll t=find(1,1,n,s[par],s[par])*POW(a[par],MOD-2)%MOD;
				res=res*POW(t,MOD-2)%MOD;
			}
			printf("%lld\n",res);
		}
	}
}