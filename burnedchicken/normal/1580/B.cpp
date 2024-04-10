#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define chkmin(a,b) (a=min(a,b))
#define chkmax(a,b) (a=max(a,b))
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
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(vector<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(unordered_set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=105;

//i_am_noob
//#define wiwihorz  
int n,m,k,p;
int dp[maxn][maxn][maxn],fac[maxn],C[maxn][maxn];

void orzck(){
    ld start=clock();
    cin >> n >> m >> k >> p;
    if(m+k>n+1){
        print(0);
        return;
    }
    int tot=0;
    fac[0]=1;
    rep2(i,1,maxn) fac[i]=fac[i-1]*i%p;
    C[0][0]=1;
    rep2(i,1,n+2) rep1(j,i+1){
        if(j) C[i][j]+=C[i-1][j-1];
        C[i][j]+=C[i-1][j];
        C[i][j]%=p;
    }
    rep1(j,m+1) dp[0][j][0]=1;
    //rep(n+1) rep1(j,m+1) dp[i][j][0]=fac[i];
    rep2(i,1,n+1){
        rep2(j,1,m+1){
            if(j>i){
                dp[i][j][0]=fac[i];
                continue;
            }
            rep1(cnt,min(k+1,i+2-j)){
                if(j==1){
                    if(cnt==1) dp[i][j][cnt]=fac[i];
                    else dp[i][j][cnt]=0;
                    //bug(i,j,cnt,dp[i][j][cnt]);
                    continue;
                }
                rep1(pos,(i+1)/2){
                    int times=1+(pos!=i-1-pos);
                    __int128 tmp=0;
                    rep1(cntl,cnt+1) tmp+=dp[pos][j-1][cntl]*dp[i-1-pos][j-1][cnt-cntl];
                    tot+=cnt+1;
                    tmp%=p;
                    tmp*=times*C[i-1][pos]%p;
                    tmp%=p;
                    //bug(pos,tmp,times);
                    dp[i][j][cnt]+=tmp;
                }
                dp[i][j][cnt]%=p;
                //bug(i,j,cnt,dp[i][j][cnt]);
            }
        }
    }
    print(dp[n][m][k]);
    bug((clock()-start)/CLOCKS_PER_SEC);
    bug(tot);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) orzck();
    return 0;
}