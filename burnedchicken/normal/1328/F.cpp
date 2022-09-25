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
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
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

const int maxn=200005;
//i_am_noob
int n,k,a[maxn],sum1[maxn],sum2[maxn],x,y,ans=4e18;
map<int,int> m;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> k;
    rep(n) cin >> a[i];
    sort(a,a+n);
    rep(n) m[a[i]]++;
    sum1[0]=sum2[0]=0;
    rep(n) sum1[i+1]=sum1[i]+a[i];
    rep(n) sum2[i+1]=sum2[i]+a[n-1-i];
    rep(n) if(i==n-1||a[i]!=a[i+1]){
        if(m[a[i]]>=k){
            print1(0);
            return 0;
        }
        if(a[i]==a[0]) ans=min(ans,sum2[n-i-1]-(n-i-1)*a[i]-(n-k));
        else if(i==n-1) ans=min(ans,(n-1)*a[n-1]-sum1[n-1]-(n-k));
        else{
            x=i*a[i]-sum1[i]-(i+1-m[a[i]]),y=sum2[n-i-1]-(n-i-1)*a[i]-(n-i-1);
            if(i+1>=k) ans=min(ans,x+k-m[a[i]]);
            if(n-i-1+m[a[i]]>=k) ans=min(ans,y+k-m[a[i]]);
            ans=min(ans,x+y+k-m[a[i]]);
        }
    }
    print1(ans);
    return 0;
}