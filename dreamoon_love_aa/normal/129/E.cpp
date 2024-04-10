#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
#define MOD 1000000007
using namespace std;
long long dp[1024][1024];
long long f(int n,int k){
    long long an=0;
    if(k==0)return 1;
    if(dp[n][k]>=0)return dp[n][k];
    int i;
    for(i=1;i<=n-2;i++){
        an+=f(i,k-1)*(n-1-i);
    }
    return dp[n][k]=an%MOD;
}
int main(){
    int i,j,k,n,m;
    scanf("%d%d%d",&n,&m,&k);
    memset(dp,-1,sizeof(dp));
    cout<<f(n,k)*f(m,k)%MOD<<endl;

    return 0;
}