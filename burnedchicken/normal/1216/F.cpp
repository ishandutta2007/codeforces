#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define int long long
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
 
const int maxn=200005;
//i_am_noob
int n,k,dp[maxn];
string str;
vector<int> vec;

struct segment_tree{
	int val[4*maxn],tag[4*maxn];
	inline int mid(int l, int r){return l+r>>1;}
	void reset(){
		memset(val,0,sizeof(val));
		memset(tag,0,sizeof(tag));
	}
	void pull(int k){val[k]=min(val[k<<1],val[(k<<1)+1]);}
	void push(int k, int l, int r){
		if(l!=r){
			tag[k<<1]+=tag[k];
			tag[(k<<1)+1]+=tag[k];
			val[k<<1]+=tag[k];
			val[(k<<1)+1]+=tag[k];
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
		modify(k<<1,l,mid(l,r),ql,qr,x);
		modify((k<<1)+1,mid(l,r)+1,r,ql,qr,x);
		pull(k);
	}
	int query(int k, int l, int r, int ql, int qr){
		if(l>qr||r<ql) return 4e18;
		if(ql<=l&&qr>=r) return val[k];
		push(k,l,r);
		return min(query(k<<1,l,mid(l,r),ql,qr),query((k<<1)+1,mid(l,r)+1,r,ql,qr));
	}
	void Debug(int k, int l, int r){
		print4(l,r,val[k],tag[k]);
		if(l!=r){
			Debug(k<<1,l,mid(l,r));
			Debug((k<<1)+1,mid(l,r)+1,r);
		}
	}
}segtree;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> k >> str;
	rep3(i,n-1,0) if(str[i]=='1') vec.pb(i+1);
	dp[0]=0;
	segtree.reset();
	rep2(i,1,n+1){
		if(!vec.empty()) if(vec.back()+k<i) vec.pop_back();
		dp[i]=dp[i-1]+i;
		if(!vec.empty()) if(vec.back()<=i){
			if(vec.back()-k-1<=0) dp[i]=vec.back();
			else dp[i]=min(dp[i],segtree.query(1,1,n,vec.back()-k-1,i-1)+vec.back());
		}
		segtree.modify(1,1,n,i,i,dp[i]);
	}
	print1(dp[n]);
	return 0;
}