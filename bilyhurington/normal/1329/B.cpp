/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-04-04 00:03:51
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int T,d,mod;
long long f[60];
long long dp(int x){
    if(f[x]!=-1) return f[x];
    if(!x) return 1;
    f[x]=1;
    for(int i=0;i<x;i++){
        f[x]+=dp(i);
    } 
    f[x]%=mod;
    f[x]*=(1<<x);
    f[x]%=mod;
    return f[x];
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&d,&mod);
        long long ans=0;
        memset(f,-1,sizeof(f));
        for(int i=0;(1<<(i+1))<=d;i++){
            ans+=dp(i);
            ans%=mod;
        }
        int l=log2(d);
        // printf("%lld ",ans);
        ans=(ans+(d-(1<<(l))+1)*(1+ans)%mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}