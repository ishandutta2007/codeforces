/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-04-27 00:33:43
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
int n;
long long k,jie[500010],fan[500010];
const int mod=998244353;
long long fast_pow(long long x,long long k){
    long long ans=1;
    while(k){
        if(k&1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        k>>=1;
    }
    return ans;
}
long long C(int x,int y){return jie[x]*fan[x-y]%mod*fan[y]%mod;}
int main(){
    jie[0]=1;
    for(int i=1;i<=500000;i++) jie[i]=jie[i-1]*i%mod;
    fan[500000]=fast_pow(jie[500000],mod-2);
    for(int i=500000;i>=1;i--) fan[i-1]=fan[i]*i%mod;
    scanf("%d %lld",&n,&k);
    if(k>n-1){printf("0");return 0;}
    if(!k){printf("%lld",jie[n]);return 0;}
    long long ans1=0;
    for(int i=0;i<n-k;i++) ans1+=(i%2==1?-1:1)*C(n-k,i)%mod*fast_pow(n-k-i,n)%mod,ans1%=mod;
    long long ans=2*C(n,k)%mod*(ans1+mod)%mod;
    printf("%lld",ans);
    return 0;
}