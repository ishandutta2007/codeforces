#include <bits/stdc++.h>
#include <bits/extc++.h>

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
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=100005;
//i_am_noob
int r,n,t[maxn],x[maxn],y[maxn],dp[maxn],maxx[maxn];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> r >> n;
    rep2(i,1,n+1) cin >> t[i] >> x[i] >> y[i];
    rep2(i,1,n+1) x[i]--,y[i]--;
    t[0]=0,x[0]=0,y[0]=0;
    maxx[0]=0;
    rep2(i,1,n+1){
        if(i>=1000) dp[i]=maxx[i-1000];
        else dp[i]=-inf;
        rep2(j,max(0ll,i-999),i) if(t[i]-t[j]>=abs(x[i]-x[j])+abs(y[i]-y[j])) dp[i]=max(dp[i],dp[j]);
        dp[i]++;
        maxx[i]=max(maxx[i-1],dp[i]);
    }
    print1(maxx[n]);
    return 0;
}