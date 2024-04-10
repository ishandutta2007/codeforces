#include <bits/stdc++.h>
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


int a[500005], lazy[1050000];
Pi tree[1050000];
Pi merge(Pi L,Pi R){
	if(L.X==R.X)return mp(L.X,L.Y+R.Y);
	if(L.X<R.X)return L;
	return R;
}
void init(int node,int S,int E){
	if(S==E){
		tree[node]=mp(0,1);
		return;
	}
	init(2*node,S,(S+E)/2);
	init(2*node+1,(S+E)/2+1,E);
	tree[node]=merge(tree[node<<1],tree[node<<1|1]);
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
	tree[node]=merge(tree[node<<1],tree[node<<1|1]);
}
Pi find(int node,int S,int E,int i,int j){
	propagation(node,S,E);
	if(i>E || j<S)return mp(INF,INF);
	if(j>=E && i<=S)return tree[node];
	return merge(find(node*2,S,(S+E)/2,i,j),find(2*node+1,(S+E)/2+1,E,i,j));
}
int b[500005];
Vi v[500005];
int main(){
	int n;
	scanf("%d",&n);
	fup(i,1,n,1){
		scanf("%d",a+i);
		b[i]=v[a[i]].size();
		v[a[i]].pb(i);
	}
	init(1,1,n);
	ll ans=0;
	fup(i,1,n,1){
		if(b[i]==0)upd(1,1,n,1,i,1);
		if(b[i]>=1){
			int t=v[a[i]][b[i]-1];
			upd(1,1,n,t+1,i,1);
		}
		if(b[i]==2){
			int t=v[a[i]][b[i]-2];
			upd(1,1,n,1,t,-1);
		}
		if(b[i]>=3){
			int t=v[a[i]][b[i]-3];
			upd(1,1,n,1,t,1);
			int t2=v[a[i]][b[i]-2];
			upd(1,1,n,t+1,t2,-1);
		}
		Pi p=find(1,1,n,1,i);
		if(p.X==0)ans+=p.Y;
	}
	printf("%lld\n",ans);
}