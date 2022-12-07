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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Vi v[200005];
int cnt[200005],S[200005],E[200005],idx[200005],cc;
int par[200005],chk[200005];
void dfs(int N,int p=-1,int c=1){
	par[N]=p;
	S[N]=++cc;
	idx[cc]=N;
	if(p!=-1 && v[N].size()==1){
		cnt[N]=c;
		E[N]=cc;
		return;
	}
	cnt[N]=-987654321;
	for(int next:v[N]){
		if(next==p)continue;
		dfs(next,N,c+1);
	}
	E[N]=cc;
}
Pi a[524288], tree[524288];
int lazy[524288];
void init(int node,int S,int E){
	if(S==E){
		int N=idx[S];
		tree[node]=mp(cnt[N],N);
		return;
	}
	init(2*node,S,(S+E)/2);
	init(2*node+1,(S+E)/2+1,E);
	tree[node]=max(tree[2*node],tree[2*node+1]);
}
void propagation(int node,int S,int E){
	if(lazy[node]!=0){
		tree[node].X+=lazy[node];
		if(S!=E){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
}
void upd(int node,int S,int E,int i,int j,int val){
	propagation(node,S,E);
	if(i>E || j<S) return;
	if(j>=E && i<=S){
		lazy[node]+=val;
		propagation(node,S,E);
		return;
	}
	upd(2*node,S,(S+E)/2,i,j,val);
	upd(2*node+1,(S+E)/2+1,E,i,j,val);
	tree[node]=max(tree[2*node],tree[2*node+1]);
}
Pi find(int node,int S,int E,int i,int j){
	propagation(node,S,E);
	if(i>E || j<S)return mp(-987654321,-1);
	if(j>=E && i<=S)return tree[node];
	return max(find(node*2,S,(S+E)/2,i,j),find(2*node+1,(S+E)/2+1,E,i,j));
}
inline ll res(int n,int r,int b){
	return 1ll*(n-r-b)*(r-b);
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	fup(i,1,n-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	ll ans=-INF;
	dfs(1);
	init(1,1,n);
	int rem=n;
	fup(i,1,k,1){
		Pi p=find(1,1,n,1,n);
		if(p.X>0){
			rem-=p.X;
			int x=p.Y;
			while(x>=1 && !chk[x]){
				chk[x]=1;
				upd(1,1,n,S[x],E[x],-1);
				x=par[x];
			}
		}
		ll w=min(res(n,i,0),res(n,i,rem));
		fup(b,n/2-1,n/2+1,1){
			if(b>=0 && b<=rem){
				w=min(w,res(n,i,b));
			}
		}
		ans=max(ans,w);
	}
	printf("%lld\n",ans);
}