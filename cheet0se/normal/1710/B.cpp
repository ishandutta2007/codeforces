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

ll x[200005],p[200005];
Pll operator - (const Pll &p1){
	return mp(-p1.X,-p1.Y);
}
Pll operator + (const Pll &p1,const Pll &p2){
	return mp(p1.X+p2.X,p1.Y+p2.Y);
}

struct FenwickTree{
	int n;
	VPll tree;
	
	FenwickTree(){}
	FenwickTree(int N){
		n=N;
		tree.resize(N+1,Pll(0,0));
	}
	
	void upd(int i,Pll k){
		i++;
		while(i<=n){
			tree[i]=tree[i]+k;
			i+=(i&-i);
		}
	}
	Pll sum(int i){
		Pll c;
		i++;
		while(i>0){
			c=c+tree[i];
			i-=(i&-i);
		}
		return c;
	}
};
ll h[200005];
void solve(){
	int n;
	ll m;
	scanf("%d%lld",&n,&m);
	fup(i,0,n,1)h[i]=0;
	Vll vv;
	fup(i,0,n-1,1){
		scanf("%lld%lld",x+i,p+i);
		vv.pb(x[i]);
	}
	COMPRESS(vv);
	fup(i,0,n-1,1){
		x[i]=lower_bound(ALL(vv),x[i])-vv.begin();
		h[x[i]]+=p[i];
	}
	int N=vv.size();
	FenwickTree A(N),B(N);
	fup(i,0,n-1,1){
		int j=x[i];
		int k=lower_bound(ALL(vv),vv[x[i]]-p[i])-vv.begin();
		A.upd(k,Pll(vv[x[i]]-p[i],1));A.upd(j,-Pll(vv[x[i]]-p[i],1));
		k=lower_bound(ALL(vv),vv[x[i]]+p[i])-vv.begin();
		B.upd(j+1,Pll(vv[x[i]]+p[i],1));B.upd(k,-Pll(vv[x[i]]+p[i],1));
	}
	vector<pair<ll,Pll>> L,R;
	fup(i,0,N-1,1){
		Pll P=A.sum(i);
		h[i]+=P.Y*vv[i]-P.X;
		P=B.sum(i);
		h[i]+=P.X-P.Y*vv[i];
		if(h[i]>m){
			L.pb(mp(vv[i],mp(h[i]-vv[i],h[i])));
			R.pb(mp(vv[i],mp(h[i]+vv[i],h[i])));
		}
	}
	if(L.empty()){
		fup(i,1,n,1)putchar('1');
		puts("");
		return;
	}
	int M=L.size();
	fup(i,1,M-1,1)L[i].Y=max(L[i].Y,L[i-1].Y);
	fdn(i,M-2,0,1)R[i].Y=max(R[i].Y,R[i+1].Y);
	fup(i,0,n-1,1){
		ll j=x[i];
		bool ok=1;
		int k=lower_bound(ALL(R),mp(vv[x[i]],Pll(-INF,-INF)))-R.begin();
		if(k!=M){
			ll dist=R[k].Y.X-R[k].Y.Y-vv[j];
			if(R[k].Y.Y-max(0ll,p[i]-dist)>m)ok=0;
		}
		k--;
		if(k!=-1){
			ll dist=vv[j]-(L[k].Y.Y-L[k].Y.X);
			if(L[k].Y.Y-max(0ll,p[i]-dist)>m)ok=0;
		}
		printf("%d",ok);
	}
	puts("");
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}