#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#define hash hassh
using namespace std;
long long mod=1000000007;
long long dp[255][255],c[255][255],multi1[255],multi2[255];
int main() {
    c[0][0]=c[1][0]=c[1][1]=1;
    for(int i=2;i<=250;i++) {
        c[i][0]=c[i][i]=1;
        for (int j = 1; j < i; j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1],c[i][j]%=mod;
    }
    multi1[0]=multi2[0]=1;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) multi1[i]=multi1[i-1]*k%mod,multi2[i]=multi2[i-1]*(k-1)%mod;
    for(int i=1;i<=n;i++)
        dp[1][i]=c[n][i]*multi2[n-i]%mod;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int t=j;t<=n;t++){
                long long cnt;
                if(t==j) cnt=((multi1[j]-multi2[j])%mod*multi2[n-j]%mod+mod)%mod;
                else cnt=c[n-j][t-j]*multi2[n-t]%mod*multi1[j]%mod;
                dp[i][t]+=dp[i-1][j]*cnt;
                dp[i][t]%=mod;
            }
    cout<<dp[n][n]<<endl;
    return 0;
}