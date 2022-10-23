#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define per(i,a,b) for(int i=a; i>=(b); --i)
#define ll long long
#define int ll
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define sz(a) ((int)a.size())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif

const int maxn=505;

int n,a[maxn],dp[maxn][maxn],maxx[maxn][2],ndp[maxn][maxn];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(i,0,n) cin >> a[i];
    rep(i,0,maxn) rep(j,0,maxn) dp[i][j]=-4e18;
    rep(i,0,maxn) maxx[i][0]=maxx[i][1]=-4e18;
    maxx[0][0]=maxx[0][1]=0;
    rep(i,0,n){
        rep(j,0,maxn) rep(k,0,maxn) ndp[j][k]=-4e18;
        rep(j,0,i+2) rep(k,0,n){
            ndp[j][k]=max(ndp[j][k],dp[j][k]+a[k]);
            if(k<i) continue;
            int cost=k-i-1;
            if(j+cost>=0){
                if(dp[j+cost][k]==maxx[j+cost][0]) ndp[j][k]=max(ndp[j][k],maxx[j+cost][1]+a[k]);
                else ndp[j][k]=max(ndp[j][k],maxx[j+cost][0]+a[k]);
            }
        }
        memcpy(dp,ndp,sizeof ndp);
        rep(j,0,i+2){
            maxx[j][0]=maxx[j][1]=-4e18;
            rep(k,0,n) maxx[j][0]=max(maxx[j][0],dp[j][k]);
            bool flag=0;
            rep(k,0,n){
                if(maxx[j][0]==dp[j][k]&&!flag) flag=1;
                else maxx[j][1]=max(maxx[j][1],dp[j][k]);
            }
        }
    }
    int res=-4e18;
    rep(i,0,n+1) res=max(res,maxx[i][0]);
    cout << res << "\n";
}