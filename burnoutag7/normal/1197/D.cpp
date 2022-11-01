    #include<bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
     
    int n,m,k;
    ll a[300005];
    ll dp[300005][15];
    ll ans;
     
    int main(){
     
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
     
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dp[1][1]=a[1]-k;
        for(int i=2;i<=n;i++){
            dp[i][0]=max(dp[i-1][m-1],0ll);
            dp[i][1]=max(dp[i-1][m]+a[i]-k,a[i]-k);
            for(int j=2;j<=min(i,m);j++){
                dp[i][j]=dp[i-1][j-1]+a[i];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                ans=max(ans,dp[i][j]);
            }
        }
        cout<<ans<<endl;
     
        return 0;
    }