#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=1000006;
const int mdn=998244353;

int n;
int dp[maxn],pfx[maxn];
int dc[maxn];

int main(){
    cin>>n;
    dp[1]=1;pfx[0]=1;
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j+=i)dc[j]++;
    for(int i=1;i<=n;i++){
        if(i>1)dp[i]=(dp[i]+pfx[i-1]+(long long)dc[i]-1)%mdn;
        pfx[i]=(pfx[i-1]+dp[i])%mdn;
    }
    cout<<dp[n];
    return 0;
}