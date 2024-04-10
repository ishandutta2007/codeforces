/*
 * @Author: BilyHurington
 * @Date: 2020-11-02 12:57:06
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-11-03 13:48:46
 */
#include<bits/stdc++.h>
using namespace std;
const int MAXN=5000,mod=998244353;
long long fast_pow(long long x,long long k){
    long long ans=1;
    while(k){
        if(k&1) ans=ans*x%mod;
        x=x*x%mod;k>>=1;
    }
    return ans;
}
long long Fac[MAXN+10],Fac_inv[MAXN+10];
void Pre_Fac(){
    Fac[0]=1;for(int i=1;i<=MAXN;i++) Fac[i]=Fac[i-1]*i%mod;
    Fac_inv[MAXN]=fast_pow(Fac[MAXN],mod-2);
    for(int i=MAXN;i>=1;i--) Fac_inv[i-1]=Fac_inv[i]*i%mod;
}
long long A(int x,int y){
    if(y<0||x<y) return 0;
    return Fac[x]*Fac_inv[x-y]%mod;
}
int n,a[MAXN+10],f[MAXN+10],L[MAXN+10];
void Add(int &x,int y){x+=y;if(x>=mod) x-=mod;}
int main(){
    scanf("%d",&n);Pre_Fac();
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);L[0]=-1;f[0]=1;
    if(a[n]<a[n-1]*2){printf("0");return 0;}
    for(int i=1;i<=n;i++) L[i]=upper_bound(a+1,a+n+1,a[i]/2)-a-1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=L[i];j++){
            // printf("%d %d\n",i,j);
            Add(f[i],f[j]*A(n-2-L[j],L[i]-L[j]-1)%mod);
            // printf("%d %d\n",n-2-L[j],n-1-L[i]);
        }
    }
    printf("%d",f[n]);
    return 0;
}