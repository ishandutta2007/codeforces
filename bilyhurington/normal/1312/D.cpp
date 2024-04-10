/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-09 23:03:40
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
int n,m;
const int mod=998244353;
long long jie[200010],fan[200010];
long long C(int x,int y){if(x<y||y<0) return 0;return jie[x]*fan[x-y]%mod*fan[y]%mod;}
long long pw(long long x,int k){
    long long ans=1;
    while(k){
        if(k&1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        k/=2;
    }
    return ans;
}
int main(){
    jie[0]=1;
    for(int i=1;i<=200000;i++) jie[i]=jie[i-1]*i%mod;
    fan[200000]=pw(jie[200000],mod-2);
    for(int i=200000;i>=1;i--) fan[i-1]=fan[i]*i%mod;
    scanf("%d %d",&n,&m);
    long long ans=0;
    for(int i=1;i<=m;i++){
        long long sum=(C(m-1,n-2)-C(i-1,n-2)+mod)%mod;
        ans+=sum*((pw(2,n-1)-2*pw(2,n-3)%mod+mod)%mod)%mod;
        ans%=mod;
    }
    printf("%lld\n",(ans*pw(2,mod-2)%mod+mod)%mod);
    return 0;
}