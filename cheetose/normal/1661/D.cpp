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

ll a[300005],tree[1<<20],lazy[1<<20];
void init(int node,int S,int E){
	if(S==E){
		tree[node]=a[S];
		return;
	}
	init(2*node,S,(S+E)/2);
	init(2*node+1,(S+E)/2+1,E);
	tree[node]=tree[2*node]+tree[2*node+1];
}
void propagation(int node,int S,int E){
	if(lazy[node]!=0){
		tree[node]+=lazy[node]*(E-S+1);
		if(S!=E){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
}
void upd(int node,int S,int E,int i,int j,ll val){
	propagation(node,S,E);
	if(i>E || j<S) return;
	if(j>=E && i<=S){
		lazy[node]+=val;
		propagation(node,S,E);
		return;
	}
	upd(2*node,S,(S+E)/2,i,j,val);
	upd(2*node+1,(S+E)/2+1,E,i,j,val);
	tree[node]=tree[2*node]+tree[2*node+1];
}
ll find(int node,int S,int E,int i,int j){
	propagation(node,S,E);
	if(i>E || j<S)return 0;
	if(j>=E && i<=S)return tree[node];
	return find(node*2,S,(S+E)/2,i,j)+find(2*node+1,(S+E)/2+1,E,i,j);
}
int n,k;
inline ll get(int i){
	return find(1,1,n,1,i);
}
int main(){
	scanf("%d%d",&n,&k);
	ll pr=0;
	fup(i,1,n,1){
		ll x;
		scanf("%lld",&x);
		a[i]=x-pr;
		pr=x;
	}
	init(1,1,n);
	ll ans=0;
	fdn(i,n,k+1,1){
		ll t=get(i);
		ll x=(t+k-1)/k;
		if(x<=0)continue;
		ans+=x;
		upd(1,1,n,i-k+1,i,-x);
	}
	ll tmp=0;
	fup(i,1,k,1){
		ll t=get(i);
		tmp=max(tmp,(t+i-1)/i);
	}
	printf("%lld\n",ans+tmp);
}