#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int dp[2001][2001];
int n,h,l,r;
int fix(int a){
    if(a<0)a+=h;
    return a;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>h>>l>>r;
    int a;
    for(int i=1;i<h;i++)dp[0][i]=-2001;
    int ma;
    for(int i=1;i<=n;i++){
        cin>>a;
        ma=-2001;
        for(int j=0;j<h;j++){
            dp[i][j]=max(dp[i-1][fix(j-a)],dp[i-1][fix(j-a+1)]);
            if(j>=l&&j<=r)dp[i][j]++;
            ma=max(ma,dp[i][j]);
        }
    }
    printf("%d\n",ma);
    return 0;
}