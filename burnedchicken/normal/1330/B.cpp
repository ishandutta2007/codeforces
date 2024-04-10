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
int t,n,a[maxn],cnt[maxn],x,y;
vector<pii> vec;
bool ok;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		rep(n) cin >> a[i];
		rep(n+1) cnt[i]=0;
		rep(n) cnt[a[i]]++;
		x=y=-1;
		ok=true;
		rep2(i,1,n+1){
			if(cnt[i]==2) continue;
			if(cnt[i]<=1) x=i-1;
			else ok=false;
			break;
		}
		rep2(i,x+1,n+1){
			if(cnt[i]==1) continue;
			if(cnt[i]==0) y=i-1;
			else ok=false;
			break;
		}
		if(!ok){
			print1(0);
			continue;
		}
		if(x+y!=n){
			print1(0);
			continue;
		}
		vec.clear();
		rep(n+1) cnt[i]=0;
		ok=true;
		rep(x) cnt[a[i]]++;
		rep2(i,1,x+1) if(cnt[i]!=1) ok=false;
		if(ok) vec.pb(mp(x,n-x));
		rep(n+1) cnt[i]=0;
		ok=true;
		rep(y) cnt[a[i]]++;
		rep2(i,1,y+1) if(cnt[i]!=1) ok=false;
		if(ok) vec.pb(mp(y,n-y));
		if(x==y&&(!vec.empty())) vec.pop_back();
		print1(sz(vec));
		rep(sz(vec)) print2(vec[i].first,vec[i].second);
	}
	return 0;
}