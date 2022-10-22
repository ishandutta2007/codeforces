#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1000010,mod=1e9+7,inv2=(mod+1)/2;
ll ksm(ll sum,int num){
    ll ans=1;
    while(num){
        if(num&1)ans=ans*sum%mod;
        sum=sum*sum%mod;
        num>>=1;
    }return ans;
}
int i,j,k,n,m,a[maxn];
ll Pow[maxn],nPow[maxn],Sum[maxn],p[maxn],dp[maxn],S[maxn];
int main(){
    int T;
    cin>>T;
    Pow[0]=1;for(i=1;i<maxn;i++)Pow[i]=Pow[i-1]*2%mod;
    nPow[0]=1;for(i=1;i<maxn;i++)nPow[i]=nPow[i-1]*inv2%mod;
    Sum[0]=1;for(i=1;i<maxn;i++)Sum[i]=(Sum[i-1]+Pow[i])%mod;
    for(i=1;i<maxn;i++){
        if(i==1)p[i]=0;
        else if(i==2)p[i]=2;
        else{
            p[i]=Sum[i-(i-1)/2-2]+1;
            p[i]%=mod;
        }
        // if(i<=10)cerr<<"i="<<i<<" p="<<p[i]<<endl;
    }
    while(T--){
        scanf("%d",&n);
        if(n==1){puts("1");continue;}
        dp[n]=1;S[n]=1;S[n+1]=0;
        for(i=n-1;i>=1;i--){
            int len=i;
            dp[i]=0;
            dp[i]=(S[i+1]-S[i+min(len-1,n-i)+1]+(i+min(len-1,n-i)==n?1:0)+mod)%mod;
            // for(j=1;j<=min(len-1,n-i);j++)
            //     if(i+j==n)dp[i]+=2*dp[i+j];
            //     else dp[i]+=dp[i+j];
            S[i]=S[i+1]+dp[i];S[i]%=mod;
            dp[i]%=mod;
        }
        ll tmp=ksm(inv2,n);
        for(i=1;i<=n;i++)printf("%lld ",(i==n?2*p[i]%mod:p[i])*dp[i]%mod*tmp%mod);
        puts("");
    }
}