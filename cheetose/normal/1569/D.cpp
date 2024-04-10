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

struct FEN{
	int tree[1000005]={};
	void upd(int i, int k){
		i++;
		while (i <= 1000002){
			tree[i] += k;
			i += (i&-i);
		}
	}
	int sum(int i){
		i++;
		int c = 0;
		while (i > 0){
			c += tree[i];
			i -= (i&-i);
		}
		return c;
	}
}A,B;
void solve(){
	Vi v,h;
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	fup(i,0,n-1,1){
		int x;
		scanf("%d",&x);
		v.pb(x);
	}
	fup(i,0,m-1,1){
		int x;
		scanf("%d",&x);
		h.pb(x);
	}
	ll ans=0;
	Vi aa,bb;
	VPi vv;
	fup(i,0,k-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		vv.pb(mp(x,y));
		bool V=binary_search(ALL(v),x);
		bool H=binary_search(ALL(h),y);
		if(V && H)continue;
		if(!H){
			aa.pb(y);
			auto it=upper_bound(ALL(h),y);
			ans+=A.sum((*it)-1);
			it--;
			ans-=A.sum(*it);
			A.upd(y,1);
		}
		if(!V){
			bb.pb(x);
			auto it=upper_bound(ALL(v),x);
			ans+=B.sum((*it)-1);
			it--;
			ans-=B.sum(*it);
			B.upd(x,1);
		}
	}
	sort(ALL(vv),[&](Pi p1,Pi p2){
		if(p1.X!=p2.X)return p1.X<p2.X;
		return p1.Y<p2.Y;
	});
	int N=vv.size();
	int cnt=0;
	fup(i,0,N-1,1){
		if(i==0 || vv[i].X!=vv[i-1].X || (*lower_bound(ALL(h),vv[i-1].Y)<=vv[i].Y))cnt=0;
		ans-=cnt;
		cnt++;
	}
	sort(ALL(vv),[&](Pi p1,Pi p2){
		if(p1.Y!=p2.Y)return p1.Y<p2.Y;
		return p1.X<p2.X;
	});
	cnt=0;
	fup(i,0,N-1,1){
		if(i==0 || vv[i].Y!=vv[i-1].Y || (*lower_bound(ALL(v),vv[i-1].X)<=vv[i].X))cnt=0;
		ans-=cnt;
		cnt++;
	}
	for(int x:aa)A.upd(x,-1);
	for(int x:bb)B.upd(x,-1);
	printf("%lld\n",ans);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}