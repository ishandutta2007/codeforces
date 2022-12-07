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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

static char buf[1 << 19];
static int idx = 0;
static int bytes = 0;
static inline int _read() {
	if (!bytes || idx == bytes) {
		bytes = (int)fread(buf, sizeof(buf[0]), sizeof(buf), stdin);
		idx = 0;
	}
	return buf[idx++];
}
static inline int _readInt() {
	int x = 0, s = 1;
	int c = _read();
	while (c <= 32) c = _read();
	if (c == '-') s = -1, c = _read();
	while (c > 32) x = 10 * x + (c - '0'), c = _read();
	if (s < 0) x = -x;
	return x;
}
Vi v[2000001];
int a[1000000],b[1000000],res[2000001];
int N;
int tree[2097152], lazy[2097152];
void init(int node,int S,int E){
	tree[node]=lazy[node]=0;
	if(S==E)return;
	int L=node<<1,R=L|1;
	init(L,S,(S+E)/2);
	init(R,(S+E)/2+1,E);
}
void propagation(int node,int S,int E){
	if(lazy[node]!=0){
		tree[node]+=lazy[node];
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
	int L=node<<1,R=L|1;
	upd(L,S,(S+E)/2,i,j,val);
	upd(R,(S+E)/2+1,E,i,j,val);
	tree[node]=min(tree[L],tree[R]);
}
ll find(int node,int S,int E,int i,int j){
	propagation(node,S,E);
	if(i>E || j<S)return INF;
	if(j>=E && i<=S)return tree[node];
	return min(find(node*2,S,(S+E)/2,i,j),find(2*node+1,(S+E)/2+1,E,i,j));
}
struct FenwickTree{
	int n,tot;
	Vi tree;
	
	FenwickTree(){}
	FenwickTree(int N){
		n=N,tot=0;
		tree.resize(N+1);
	}
	
	void upd(int i, int k){
		tot+=k;
		while (i <= n){
			tree[i] += k;
			i += (i&-i);
		}
	}
	int sum(int i){
		int c = 0;
		while (i > 0){
			c += tree[i];
			i -= (i&-i);
		}
		return c;
	}
};
void solve(){
	int n=_readInt(),m=_readInt();
	Vi vv;
	fup(i,0,n-1,1){
		a[i]=_readInt();
		vv.pb(a[i]);
	}
	fup(i,0,m-1,1){
		b[i]=_readInt();
		vv.pb(b[i]);
	}
	COMPRESS(vv);
	N=vv.size();
	fup(i,0,N,1)v[i].clear();
	FenwickTree A(N);
	fup(i,0,n-1,1){
		a[i]=lower_bound(ALL(vv),a[i])-vv.begin()+1;
		v[a[i]].pb(i);
	}
	fup(i,0,m-1,1){
		b[i]=lower_bound(ALL(vv),b[i])-vv.begin()+1;
	}
	init(1,0,n);
	ll ans=0;
	fdn(i,n-1,0,1){
		ans+=A.sum(a[i]-1);
		A.upd(a[i],1);
	}
	fup(i,0,n-1,1){
		upd(1,0,n,i+1,n,1);
	}
	fup(x,1,N,1){
		for(int i:v[x])upd(1,0,n,i+1,n,-1);
		res[x]=find(1,0,n,0,n);
		for(int i:v[x])upd(1,0,n,0,i,1);
	}
	fup(i,0,m-1,1)ans+=res[b[i]];
	printf("%lld\n",ans);
}
int main(){
	int tc=_readInt();
	while(tc--)solve();
}