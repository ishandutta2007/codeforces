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
#define MOD 100000000
using namespace std;
long long dp[2][101][101];
int k1,k2;
long long f(int flag,int n1,int n2){
    int i;
    if(n1==n2&&n1==0)return 1;
    if(dp[flag][n1][n2]>=0)return dp[flag][n1][n2];
    long long an=0;
    if(!flag){
        for(i=1;i<=n1&&i<=k1;i++)an+=f(1,n1-i,n2);
    }
    else{
        for(i=1;i<=n2&&i<=k2;i++)an+=f(0,n1,n2-i);
    }
    return dp[flag][n1][n2]=an%MOD;
}
int main(){
    int i,j,k,n1,n2;
    long long an=0;
    scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
    memset(dp,-1,sizeof(dp));
    an+=f(0,n1,n2);
    an+=f(1,n1,n2);
    an%=MOD;
    cout<<an<<endl;


    return 0;
}