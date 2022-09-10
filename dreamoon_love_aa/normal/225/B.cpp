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
long long dp[200];
int main(){
    int i,j,k,n,s;
    dp[0]=dp[1]=1;
    cin>>s>>k;
    for(i=2;;i++){
        for(j=max(i-k,0);j<i;j++)dp[i]+=dp[j];
        if(dp[i]>s)break;
    }
    i--;
    vector<int>an;
    while(s){
        if(s>=dp[i]){
            an.pb(dp[i]);
            s-=dp[i];
        }
        i--;
    }
    an.pb(0);
    printf("%d\n",an.size());
    for(i=0;i<an.size();i++){
        if(i)printf(" ");
        printf("%d",an[i]);
    }
    puts("");
    return 0;
}