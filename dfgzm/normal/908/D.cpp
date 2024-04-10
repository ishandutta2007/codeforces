#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const int maxn=2010;
ll ksm(ll sum,int num){
    ll ans=1;
    while(num){
        if(num&1)ans=ans*sum%mod;
        sum=sum*sum%mod;
        num>>=1;
    }return ans;
}
int i,j,k,n,m;
ll dp[maxn][maxn+maxn],A,B,pa,pb;
int main(){
    cin>>n>>A>>B;
    pa=A*ksm(A+B,mod-2)%mod;
    pb=B*ksm(A+B,mod-2)%mod;
    dp[1][0]=1;
    for(i=1;i<=n;i++){
        for(j=0;j<n;j++){
            // put an 'A'
            dp[i+1][j]+=dp[i][j]*pa;dp[i+1][j]%=mod;
            // put a  'B'
            dp[i][i+j]+=dp[i][j]*pb;dp[i][i+j]%=mod;
        }
    }
    ll ans=0;
    for(i=0;i<=n;i++)
        for(j=n;j<=n+n;j++)
            ans+=dp[i][j]*j%mod,ans%=mod;
    for(j=0;j<n;j++)
        ans+=dp[n+1][j]*((j+n+1+A*ksm(B,mod-2)%mod)%mod)%mod,ans%=mod;
    cout<<ans<<endl;
}
/*
T= A/A+B (T + 1)
B/A+B T = A/A+B
*/