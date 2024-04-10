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

ll s[500001];
int N;
struct SEG{
	ll tree[1050000];
	void init(int node,int S,int E){
		tree[node]=-INF;
		if(S==E)return;
		int L=node<<1,R=L|1,M=S+E>>1;
		init(L,S,M);
		init(R,M+1,E);
	}
	void upd(int node,int S,int E,int k,ll dif){
		if(S==E){
			tree[node]=max(tree[node],dif);
			return;
		}
		int L=node<<1,R=L|1,M=S+E>>1;
		if(k<=M)upd(L,S,M,k,dif);
		else upd(R,M+1,E,k,dif);
		tree[node]=max(tree[L],tree[R]);
	}

	ll find(int node,int S,int E,int i,int j){
		if(i>E || j<S)return -INF;
		if(i<=S && j>=E)return tree[node];
		int L=node<<1,R=L|1,M=S+E>>1;
		return max(find(L,S,M,i,j),find(R,M+1,E,i,j));
	}
}pos,zero,neg;
void solve(){
	s[0]=0;
	int n;
	scanf("%d",&n);
	Vll vv={0};
	fup(i,1,n,1){
		scanf("%lld",s+i);
		s[i]+=s[i-1];
		vv.pb(s[i]);
	}
	COMPRESS(vv);
	N=vv.size();
	fup(i,0,n,1)s[i]=lower_bound(ALL(vv),s[i])-vv.begin();
	pos.init(1,0,N-1);pos.upd(1,0,N-1,s[0],0);
	zero.init(1,0,N-1);zero.upd(1,0,N-1,s[0],0);
	neg.init(1,0,N-1);neg.upd(1,0,N-1,s[0],0);
	fup(i,1,n,1){
		ll t=max({pos.find(1,0,N-1,0,s[i]-1)+i,zero.find(1,0,N-1,s[i],s[i]),neg.find(1,0,N-1,s[i]+1,N-1)-i});
		if(i==n){
			printf("%lld\n",t);
			return;
		}
		pos.upd(1,0,N-1,s[i],t-i);
		zero.upd(1,0,N-1,s[i],t);
		neg.upd(1,0,N-1,s[i],t+i);
	}
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}