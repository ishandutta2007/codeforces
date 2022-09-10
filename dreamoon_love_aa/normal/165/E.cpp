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
int a[1000000],dp[1<<22];
bool fresh(int &x,int v){
    if(!v)return 0;
    x=v;
    return 1;
}
int main(){
    int i,j,k,n,M=1<<22;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        dp[a[i]]=a[i];
    }
    for(i=1;i<M;i++){
        if(!dp[i]){
            for(j=0;(1<<j)<=i;j++){
                if(i&(1<<j)){
                    if(fresh(dp[i],dp[i-(1<<j)]))break;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        if(i)printf(" ");
        if(dp[M-1-a[i]])printf("%d",dp[M-1-a[i]]);
        else printf("-1");
    }
    puts("");
    return 0;
}