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
long long a[100000];
int dp[100000];
bool f(long long x,long long y,int step){
    if(x&1){
        return y%x==0;
    }
    else{
        if(step<55&&((x>>step)<<step)==x){
            x>>=step;
            return y%x==0&&((y/x)&1);
        }
        else{
            int i;
            for(i=32;i>0;i>>=1)
                if(((x>>i)<<i)==x)x>>=i;
            return y%x==0;
        }
    }
}
int main(){
    int i,j,k,n,an=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)cin>>a[n-i+1];
    dp[1]=1;
    for(i=2;i<=n;i++){
        dp[i]=1;
        for(j=1;j<i;j++)
            if(f(a[j],a[i],i-j)){
                dp[i]=max(dp[i],dp[j]+1);
            }
        an=max(an,dp[i]);
    }
    cout<<n-an<<endl;

    return 0;
}