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
const int MOD=Mod;
 
inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}
 
const int maxn=100005;
//i_am_noob
int t,x,y,z,a[maxn],b[maxn],c[maxn],ans,pt1,pt2,k,found;

inline int f(int a, int b, int c){return (a-b)*(a-b)+(b-c)*(b-c)+(a-c)*(a-c);}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	while(t--){
		cin >> x >> y >> z;
		rep(x) cin >> a[i];
		rep(y) cin >> b[i];
		rep(z) cin >> c[i];
		sort(a,a+x);
		sort(b,b+y);
		sort(c,c+z);
		ans=9e18,pt1=0,pt2=0;
		rep(x){
			while(pt1<y-1){
				if(b[pt1+1]<=a[i]) pt1++;
				else break;
			}
			while(pt2<z-1){
				if(c[pt2+1]<=a[i]) pt2++;
				else break;
			}
			k=b[pt1]+a[i]>>1;
			found=lower_bound(c,c+z,k)-c;
			if(found<z) ans=min(ans,f(a[i],b[pt1],c[found]));
			if(found>0) ans=min(ans,f(a[i],b[pt1],c[found-1]));
			if(pt1<y-1){
				k=b[pt1+1]+a[i]>>1;
				found=lower_bound(c,c+z,k)-c;
				if(found<z) ans=min(ans,f(a[i],b[pt1+1],c[found]));
				if(found>0) ans=min(ans,f(a[i],b[pt1+1],c[found-1]));
			}
			k=c[pt2]+a[i]>>1;
			found=lower_bound(b,b+y,k)-b;
			if(found<y) ans=min(ans,f(a[i],c[pt2],b[found]));
			if(found>0) ans=min(ans,f(a[i],c[pt2],b[found-1]));
			if(pt2<z-1){
				k=c[pt2+1]+a[i]>>1;
				found=lower_bound(b,b+y,k)-b;
				if(found<y) ans=min(ans,f(a[i],c[pt2+1],b[found]));
				if(found>0) ans=min(ans,f(a[i],c[pt2+1],b[found-1]));
			}
		}
		print1(ans);
	}
	return 0;
}