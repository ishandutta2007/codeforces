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
#define MAX 1000000000
using namespace std;
int dp[360361];
int main(){
    long long a,b,aa,bb,an;
    int i,j,k,n;
    cin>>a>>b>>k;
    long long lcm=1;
    for(i=2;i<=k;i++)lcm=lcm*i/__gcd(lcm,(long long)i);
    aa=a%lcm;
    bb=b%lcm;
    for(i=0;i<bb;i++)dp[i]=MAX;
    for(i=bb+1;i<=lcm;i++){
        dp[i]=dp[i-1]+1;
        for(j=2;j<=k;j++)dp[i]=min(dp[i],dp[i-i%j]+1);
    }
    if(b/lcm==a/lcm)printf("%d\n",dp[a%lcm]);
    else{
        an=dp[lcm];
        dp[0]=0;
        for(i=1;i<=lcm;i++){
            dp[i]=dp[i-1]+1;
            for(j=2;j<=k;j++)dp[i]=min(dp[i],dp[i-i%j]+1);
        }
        cout<<an+dp[lcm]*(a/lcm-b/lcm-1)+dp[aa]<<endl;
    }
    return 0;
}