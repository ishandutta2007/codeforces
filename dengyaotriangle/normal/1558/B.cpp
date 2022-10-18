#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=4000005;

int n,m;
int pfx[maxn],dp[maxn];


int main(){
    cin>>n>>m;
    dp[1]=1;
    int s=0;
    for(int i=1;i<=n;i++){
        pfx[i]=(pfx[i]+pfx[i-1])%m;
        dp[i]=(dp[i]+pfx[i]+(long long)s)%m;
        s=(s+dp[i])%m;
        for(int j=2;i*j<=n;j++){
            pfx[i*j]=(pfx[i*j]+dp[i])%m;
            int r=(i+1)*j;
            if(r<=n)pfx[r]=(pfx[r]+m-dp[i])%m;
        }
    }
    cout<<dp[n];
    return 0;
}