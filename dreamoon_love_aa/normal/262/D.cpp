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
#define SIZE 55
int a[SIZE];
long long dp[SIZE][SIZE];
long double fac[SIZE];
int main(){
    int i,j,k,n,p,sum=0;
    fac[0]=1;
    for(i=1;i<SIZE;i++)fac[i]=fac[i-1]*i;
    cin>>n;
    for(i=0;i<n;i++){cin>>a[i];sum+=a[i];}
    cin>>p;
    if(sum<=p){
        printf("%.9lf\n",(double)n);
        return 0;
    }
    long double res=0;
    for(int rd=0;rd<n;rd++){
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(i=0;i<n;i++){
            if(i==rd)continue;
            for(j=n-1;j>=0;j--)
                for(k=0;k+a[i]<=p;k++){
                    dp[j+1][k+a[i]]+=dp[j][k];
                }
        }
        long double tmp=0;
        for(i=0;i<n;i++){
            for(j=0;j<=p;j++)
                if(j+a[rd]>p&&dp[i][j]>0){
                    tmp+=i*dp[i][j]*fac[i]*fac[n-i-1];
                }
        }
        res+=tmp/fac[n];
    }
    printf("%.12lf\n",(double)res);
    return 0;
}