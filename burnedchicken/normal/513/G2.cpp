#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define per(i,a,b) for(int i=a; i>=(b); --i)
#define ll long long
#define int ll
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define pb push_back
#define sz(a) ((int)a.size())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif

const int maxn=105,mod=998244353;

int n,k,a[maxn];
double dp[maxn][maxn],ndp[maxn][maxn];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> k;
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) rep(j,i+1,n) dp[i][j]=(a[i]>a[j]);
    rep(_,0,min(k,1000ll)){
        memset(ndp,0,sizeof ndp);
        rep(i,0,n) rep(j,i+1,n){
            //no change
            int de=0;
            int cnt=i*(i+1)/2+(j-i)*(j-i-1)/2+(n-1-j)*(n-j)/2+(min(i,j-i-1)+1)+(min(j-i-1,n-1-j)+1);
            de+=cnt;
            ndp[i][j]+=dp[i][j]*cnt;
            //change i
            rep(t,0,i){
                cnt=min(t,j-i-1)+1;
                ndp[t][j]+=dp[i][j]*cnt;
                de+=cnt;
            }
            rep(t,i+1,j){
                cnt=min(i,j-t-1)+1;
                ndp[t][j]+=dp[i][j]*cnt;
                de+=cnt;
            }
            //change j
            rep(t,i+1,j){
                cnt=min(t-i-1,n-1-j)+1;
                ndp[i][t]+=dp[i][j]*cnt;
                de+=cnt;
            }
            rep(t,j+1,n){
                cnt=min(j-i-1,n-1-t)+1;
                ndp[i][t]+=dp[i][j]*cnt;
                de+=cnt;
            }
            //change both
            rep(t,0,i+1){
                int ni=t,nj=t+(j-i);
                cnt=min(t,n-1-j)+1;
                ndp[ni][nj]+=(1-dp[i][j])*cnt;
                de+=cnt;
            }
            rep(t,i+1,n){
                int ni=t,nj=t+(j-i);
                if(nj>=n) break;
                cnt=min(i,n-1-nj)+1;
                ndp[ni][nj]+=(1-dp[i][j])*cnt;
                de+=cnt;
            }
        }
        double de=n*(n+1)/2;
        de=1/de;
        rep(i,0,n) rep(j,i+1,n) dp[i][j]=ndp[i][j]*de;
    }
    double res=0;
    rep(i,0,n) rep(j,i+1,n) res+=dp[i][j];
    cout << fixed << setprecision(15) << res << "\n";
}