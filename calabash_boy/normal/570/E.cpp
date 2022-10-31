#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 0x3f3f3f3f;

#define PB(x) push_back(x)
#define rep(i,l,r) for (ll i = l,_ = r;i< _;i++)
#define REP(i,l,r) for (ll i=l,_=r;i<=_;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0)
#define untie do{ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}while (0)

/************* header ******************/

const int maxn = 5e2+10;
const ll mod = 1e9+7;
ll dp[2][maxn][maxn];
int dxl[] = {-1,0};
int dyl[] = {0,-1};
int dxr[] = {1,0};
int dyr[] = {0,1};
int n,m;
char s[maxn][maxn];
inline bool check(int x,int y){
    return x>=0 && x<n && y >=0 && y<m;
}
inline void add(ll & tar,ll val){
    tar = (tar + val) %mod;
}
int main(){
    scanf("%d%d",&n,&m);
    rep(i,0,n)scanf("%s",s+i);
    if (s[0][0] != s[n-1][m-1])leave(0);
    dp[0][0][n-1] = 1;
    int now = 0;
    int Top = (n+m-2)>>1;
    for (ll step = 1;step <= Top;step++,now ^=1){
        memset(dp[now^1],0,sizeof dp[0]);
        REP(xl,0,min(step,1ll*n-1))REP(xr,max(0ll,n-1-step),n-1){

            int yl = step - xl;
            int yr = n+m-2-step - xr;
            if (yl<0 || yr<0 || yl >=m || yr >=m)continue;
            if (s[xl][yl] != s[xr][yr])dp[now^1][xl][xr] = 0;
            else{
                rep(kl,0,2)rep(kr,0,2){
                    int xxl = xl + dxl[kl];
                    int yyl = yl + dyl[kl];
                    int xxr = xr + dxr[kr];
                    int yyr = yr + dyr[kr];
                    if (check(xxl,yyl) && check(xxr,yyr)){
                        add(dp[now^1][xl][xr],dp[now][xxl][xxr]);
                    }
                }
            }
        }
    }
//    REP(step,0,1)REP(i,0,n-1)REP(j,0,n-1){
//        cout<<"dp["<<step<<"]["<<i<<"]["<<j<<"]="<<dp[step][i][j]<<endl;
//    }
    ll ans =0;
    if ((n+m) &1){
        rep(i,0,n)REP(j,i,min(1ll*n-1,i+1)){
                add(ans,dp[now][i][j]);
            }
    }else{
        rep(i,0,n){
            add(ans,dp[now][i][i]);
        }

    }
    printf("%lld\n",ans);
    return 0;
}