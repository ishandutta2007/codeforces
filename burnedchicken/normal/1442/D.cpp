#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,fma,tune=native")

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
//#define inf 1010000000
#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=1000005;
//i_am_noob
inline char readchar(){
    const int maxn=1<<20;
    static char buf[maxn],*p=buf,*q=buf;
    if(p==q&&(q=(p=buf)+fread(buf,1,maxn,stdin))==buf) return EOF;
    else return *p++;
}
inline int readint(){
    int c=readchar(),x=0,neg=0;
    while((c<'0'||c>'9')&&c!='-'&&c!=EOF) c=readchar();
    if(c=='-') neg=1,c=readchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=readchar();
    return neg?-x:x;
}


signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    int n,k,t[3005],x,dp[2][3005];
    vector<int> vec[3005];
    bool flag;
    n=readint(),k=readint();
    rep(n){
        t[i]=readint();
        rep1(j,t[i]){
            x=readint();
            vec[i].pb(x);
        }
    }
    dp[0][0]=0;
    rep2(i,1,k+1) dp[0][i]=-inf;
    rep(n){
        x=0;
        if(flag) rep1(ii,k+1) dp[0][ii]=dp[1][ii];
        else rep1(ii,k+1) dp[1][ii]=dp[0][ii];
        rep1(j,min(t[i],k)){
            x+=vec[i][j];
            if(flag){
                #pragma GCC ivdep
                rep1(ii,k-j) dp[0][ii+j+1]=max(dp[0][ii+j+1],dp[1][ii]+x);
            }
            else{
                #pragma GCC ivdep
                rep1(ii,k-j) dp[1][ii+j+1]=max(dp[1][ii+j+1],dp[0][ii]+x);
            }
        }
        flag^=1;
    }
    print(dp[flag][k]);
    return 0;
}