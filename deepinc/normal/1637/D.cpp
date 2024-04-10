#include<bits/stdc++.h>
using namespace std;
int t,n,a[123],b[123],dp[123][10001];
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        int tot=0; long long ans=0;
        for(int i=1;i<=n;++i)cin>>a[i],tot+=a[i],ans+=a[i]*a[i]*(n-2);
        for(int i=1;i<=n;++i)cin>>b[i],tot+=b[i],ans+=b[i]*b[i]*(n-2);
        dp[0][0]=1;
        for(int i=0;i<n;++i)for(int j=0;j<=i*100;++j)dp[i+1][j+a[i+1]]|=dp[i][j],dp[i+1][j+b[i+1]]|=dp[i][j],dp[i][j]=0;
        int v=0;
        for(int i=0;i<=n*100;++i)if(dp[n][i])dp[n][i]=0,v=abs(v+v-tot)>abs(i+i-tot)?i:v;
        ans+=v*v+(tot-v)*(tot-v);
        cout<<ans<<endl;
    }
}