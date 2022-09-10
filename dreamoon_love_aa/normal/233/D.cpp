#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 101
#define MOD 1000000007
long long dp[SIZE][SIZE*SIZE],pow1[SIZE],pow2[SIZE];
long long mypow(long long x,long long y){
    long long res=1;
    while(y){
        if(y&1){
            res*=x;
            res%=MOD;
        }
        x*=x;
        x%=MOD;
        y>>=1;
    }
    return res;
}
int main(){
    int i,j,n,k,K;
    long long m;
    cin>>n>>m>>K;
    long long tmp=1;
    for(i=0;i<=n;i++){
        pow1[i]=mypow(tmp,m/n);
        pow2[i]=mypow(tmp,m/n+1);
        tmp*=n-i;
        tmp%=MOD;
        tmp*=mypow(i+1,MOD-2);
        tmp%=MOD;
    }
    if(m%n==0){
        for(i=0;i<=n;i++)dp[0][i]=pow1[i];
    }
    else{
        for(i=0;i<=n;i++)dp[0][i]=pow2[i];
    }
    for(i=1;i<n;i++){
        int ni=min(n*(i+1),K);
        for(j=0;j<=ni;j++){
            if(i<m%n){
                for(k=0;k<=j&&k<=n;k++){
                    dp[i][j]+=dp[i-1][j-k]*pow2[k];
                    dp[i][j]%=MOD;
                }
            }
            else{
                for(k=0;k<=j&&k<=n;k++){
                    dp[i][j]+=dp[i-1][j-k]*pow1[k];
                    dp[i][j]%=MOD;
                }
            }
        }
    }
    long long res=0;
    cout<<dp[n-1][K]<<endl;
    return 0;
}