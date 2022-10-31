#include <bits/stdc++.h>
using namespace std;
long long n,m,x,last,sz;
long long a[105][105];
long long b[100001];
long long dp[100001];
long long dp2[100001];
long long ans=1e15;
int main(){
    cin>>n>>m>>x;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin>>a[i][j];
            if (i==1 && j==1) last=a[i][j]%x;
            else if (a[i][j]%x!=last){
                cout<<"-1";
                return 0;
            }
            ++sz;
            b[sz]=a[i][j];
        }
    }
    sort(b+1,b+sz+1);
    for (int i=2;i<=sz;++i){
        dp[i]=dp[i-1]+(b[i]-b[i-1])*(i-1)/x;
    }
    for (int i=sz-1;i>0;--i){
        dp2[i]=dp2[i+1]+(b[i+1]-b[i])*(sz-i)/x;
    }
    for (int i=1;i<=sz;++i){
        ans=min(ans,dp2[i]+dp[i]);
      //  cout<<dp[i]<<" "<<dp2[i]<<endl;
    }
    cout<<ans;
}