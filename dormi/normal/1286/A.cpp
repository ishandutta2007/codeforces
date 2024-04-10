#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=101;
int arr[MAXN];
int dp[MAXN][2][2*MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    set<int> nums;
    int cnt[2]={n/2,n+1/2};
    rep(k,0,2)for(int i=0;i<2*(n+1);i++)dp[0][k][i]=200;
    int am=0;
    rep(i,1,n+1){
        sc(arr[i]);
        if(arr[i])cnt[arr[i]%2]-=1;
    }
    dp[0][0][cnt[0]]=0;
    dp[0][1][cnt[0]]=0;
    rep(i,1,n+1){
        rep(k,0,2)for(int a=0;a<2*(n+1);a++){
            dp[i][k][a]=200;
            if(arr[i]){
                if(k==arr[i]%2) {
                    dp[i][k][a] = min(dp[i - 1][k][a], dp[i - 1][(k + 1) % 2][a] + 1);
                }
            }
            else{
                dp[i][k][a]=min(dp[i-1][(k+1)%2][a+(k==0?1:0)]+1,dp[i-1][k][a+(k==0?1:0)]);
            }
        }
    }
    prl(min(dp[n][0][0],dp[n][1][0]));
    return 0;
}