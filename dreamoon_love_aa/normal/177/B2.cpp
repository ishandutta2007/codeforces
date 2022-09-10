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
int r[1000000],rn,dp[1000000];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            r[rn++]=i;
            if(i!=n/i)r[rn++]=n/i;
        }
    }
    sort(r,r+rn);
    r[rn]=n;
    for(i=0;i<=rn;i++){
        dp[i]=r[i]+1;
        for(j=0;j<i;j++){
            if(r[i]%r[j]==0){
                dp[i]=max(dp[i],dp[j]+r[i]);
            }
        }
    }
    cout<<dp[rn]<<endl;
    return 0;
}