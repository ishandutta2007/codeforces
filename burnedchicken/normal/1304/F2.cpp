#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
//#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a) 
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
using namespace std;
using namespace __gnu_pbds;
 
const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
 
inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}
 
const int maxn=20005;
//i_am_noob
int n,m,k,a[55][20005],dp[55][20005],ans=0,x=0;

struct segment_tree{
	int val[4*maxn],tag[4*maxn];
	inline int lc(int k){return k<<1;}
	inline int rc(int k){return (k<<1)+1;}
	inline int mid(int l, int r){return l+r>>1;}
	void reset(){
		memset(val,0,sizeof(val));
		memset(tag,0,sizeof(tag));
	}
	void pull(int k){val[k]=max(val[lc(k)],val[rc(k)]);}
	void push(int k, int l, int r){
		if(l!=r){
			tag[lc(k)]+=tag[k];
			tag[rc(k)]+=tag[k];
			val[lc(k)]+=tag[k];
			val[rc(k)]+=tag[k];
		}
		tag[k]=0;
	}
	void modify(int k, int l, int r, int ql, int qr, int x){
		if(l>qr||r<ql) return;
		if(ql<=l&&qr>=r){
			val[k]+=x;
			tag[k]+=x;
			return;
		}
		push(k,l,r);
		modify(lc(k),l,mid(l,r),ql,qr,x);
		modify(rc(k),mid(l,r)+1,r,ql,qr,x);
		pull(k);
	}
	int query(int k, int l, int r, int ql, int qr){
		if(l>qr||r<ql) return -2e9;
		if(ql<=l&&qr>=r) return val[k];
		push(k,l,r);
		return max(query(lc(k),l,mid(l,r),ql,qr),query(rc(k),mid(l,r)+1,r,ql,qr));
	}
	void Debug(int k, int l, int r){
		print4(l,r,val[k],tag[k]);
		if(l!=r){
			Debug(lc(k),l,mid(l,r));
			Debug(rc(k),mid(l,r)+1,r);
		}
	}
}segtree;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m >> k;
	rep(n) rep1(j,m) cin >> a[i][j];
	if(n==1){
		rep(k) x+=a[0][i];
		ans=max(ans,x);
		rep(m-k){
			x+=a[0][i+k]-a[0][i];
			ans=max(ans,x);
		}
		print1(ans);
		return 0;
	}
	dp[0][0]=0;
	rep(k) dp[0][0]+=a[0][i]+a[1][i];
	rep1(j,m-k) dp[0][j+1]=dp[0][j]+a[0][j+k]+a[1][j+k]-a[0][j]-a[1][j];
	rep2(i,1,n){
		segtree.reset();
		rep1(j,m-k+1) segtree.modify(1,1,m-k+1,j+1,j+1,dp[i-1][j]);
		rep1(j,m-k+1) dp[i][j]=0;
		rep1(j,k) dp[i][0]+=a[i][j]+(i==n-1?0:a[i+1][j]);
		rep1(j,m-k) dp[i][j+1]+=dp[i][j]+a[i][j+k]-a[i][j]+(i==n-1?0:a[i+1][j+k]-a[i+1][j]);
		rep1(j,k) segtree.modify(1,1,m-k+1,max(1,j-k+2),min(m-k+1,j+1),-a[i][j]);
		dp[i][0]+=segtree.query(1,1,m-k+1,1,m-k+1);
		rep1(j,m-k){
			segtree.modify(1,1,m-k+1,max(1,j+2),min(m-k+1,j+k+1),-a[i][j+k]);
			segtree.modify(1,1,m-k+1,max(1,j-k+2),min(m-k+1,j+1),a[i][j]);
			dp[i][j+1]+=segtree.query(1,1,m-k+1,1,m-k+1);
		}
	}
	rep(m-k+1) ans=max(ans,dp[n-1][i]);
	print1(ans);
	return 0;
}