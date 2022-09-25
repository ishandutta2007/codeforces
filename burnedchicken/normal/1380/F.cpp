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
//#define inf 2000000000
#define inf 8000000000000000000
#define pi 3.14159265358979323846264338328
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
const int MOD=Mod2;

inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}

const int maxn=500005;
//i_am_noob
int n,m,a[maxn],dp[maxn][10],x,y,ans=1;
string str;
set<int> st;
set<int>::iterator it;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    rep(10) dp[0][i]=i+1,dp[1][i]=i+11;
    rep2(i,2,maxn) rep1(j,10) dp[i][j]=(2*dp[i-1][j]+8*dp[i-2][j])%MOD;
    cin >> n >> m >> str;
    rep(n) a[i]=str[i]-'0';
    st.insert(-1);
    rep(n) if(str[i]!='1'||i==n-1){
        ans=ans*dp[i-*st.rbegin()-1][a[i]]%MOD;
        st.insert(i);
    }
    while(m--){
        cin >> x >> y;
        x--;
        if(a[x]==y){
            print1(ans);
            continue;
        }
        if(y==1){
            it=st.find(x);
            if(x==n-1) ans=ans*dp[x-(*prev(it))-1][1]%MOD*inverse(dp[x-(*prev(it))-1][a[x]])%MOD;
            else ans=ans*inverse(dp[x-(*prev(it))-1][a[x]])%MOD*dp[(*next(it))-(*prev(it))-1][a[*next(it)]]%MOD*inverse(dp[(*next(it))-x-1][a[*next(it)]])%MOD;
            if(x!=n-1) st.erase(it);
            a[x]=1;
        }else if(a[x]==1){
            it=--st.upper_bound(x);
            if(x==n-1){
                ans=ans*dp[x-(*prev(it))-1][y]%MOD*inverse(dp[x-(*prev(it))-1][1])%MOD;
            }
            else ans=ans*dp[x-(*it)-1][y]%MOD*dp[(*next(it))-x-1][a[*next(it)]]%MOD*inverse(dp[(*next(it))-(*it)-1][a[*next(it)]])%MOD;
            st.insert(x);
            a[x]=y;
        }else{
            it=st.lower_bound(x);
            ans=ans*inverse(dp[x-(*prev(it))-1][a[x]])%MOD*dp[x-(*prev(it))-1][y]%MOD;
            a[x]=y;
        }
        print1(ans);
    }
    return 0;
}