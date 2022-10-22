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
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define COMPRESS(a) sort(ALL(a));a.resize(unique(ALL(a))-a.begin())
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
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Vi v[300001],vv[300001];
Pi tree[1050000];
int hld[300001],cnt[300001],num[300001],E[300001],idx[300001],parent[300001],depth[300001],cc;
int n;
Pi operator + (Pi p1,Pi p2){
	return {p1.X+p2.X,p1.Y+p2.Y};
}
void upd(int node, int S, int E, int k, Pi dif){
	if (S == E){
		tree[node]=tree[node]+dif;
		return;
	}
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
	tree[node]=tree[node*2]+tree[node*2+1];
}

Pi find(int node, int S, int E, int i, int j){
	if (i > E || j < S)return {0,0};
	if (i <= S && j >= E)return tree[node];
	return find(node * 2, S, (S + E) / 2, i, j)+find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
}
void dfs(int N,int d){
	depth[N]=d;
	cnt[N]=1;
	for(int next:v[N]){
		dfs(next,d+1);
		cnt[N]+=cnt[next];
	}
}
void HLD(int N){
	int c=-1;
	num[N]=++cc;
	idx[num[N]]=N;
	for(int next:v[N]){
		if(c==-1 || cnt[next]>cnt[c])c=next;
	}
	if(c!=-1){
		hld[c]=hld[N];
		HLD(c);
	}
	for(int next:v[N]){
		if(next==c)continue;
		hld[next]=next;
		HLD(next);
	}
	E[N]=cc;
}
Pi query(int x,int y){
	Pi res;
	while(hld[x]!=hld[y]){
		if(depth[hld[x]]>depth[hld[y]]){
			res=res+find(1,1,n,num[hld[x]],num[x]);
			x=parent[hld[x]];
		}
		else{
			res=res+find(1,1,n,num[hld[y]],num[y]);
			y=parent[hld[y]];
		}
	}
	if(depth[x]>depth[y])swap(x,y);
	res=res+find(1,1,n,num[x],num[y]);
	return res;
}
int ans;
void dfs2(int N){
	Pi P=find(1,1,n,num[N],E[N]);
	Pi Q=query(1,N);
	if(P.X==0){
		if(Q.X==1){
			upd(1,1,n,num[Q.Y],{-1,-Q.Y});
		}
		upd(1,1,n,num[N],{1,N});
	}
	ans=max(ans,tree[1].X);
	for(int next:vv[N]){
		dfs2(next);
	}
	if(P.X==0){
		if(Q.X==1){
			upd(1,1,n,num[Q.Y],{1,Q.Y});
		}
		upd(1,1,n,num[N],{-1,-N});
	}
}
void solve(){
	ans=cc=0;
	scanf("%d",&n);
	fup(i,1,n,1){
		v[i].clear();
		vv[i].clear();
	}
	fup(i,2,n,1){
		int x;
		scanf("%d",&x);
		vv[x].pb(i);
	}
	fup(i,2,n,1){
		int x;
		scanf("%d",&x);
		v[x].pb(i);
		parent[i]=x;
	}
	dfs(1,0);
	hld[1]=1;
	HLD(1);
	dfs2(1);
	printf("%d\n",ans);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}