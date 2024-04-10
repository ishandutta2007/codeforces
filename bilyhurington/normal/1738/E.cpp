#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010];
const int mod=998244353;
long long fast_pow(long long x,long long k){
    long long ans=1;
    while(k){
        if(k&1) ans=ans*x%mod;
        x=x*x%mod;k>>=1;
    }return ans;
}
long long Fac[100010],Faci[100010];
void Pre_Fac(int n){
    Fac[0]=1;for(int i=1;i<=n;i++) Fac[i]=Fac[i-1]*i%mod;
    Faci[n]=fast_pow(Fac[n],mod-2);
    for(int i=n;i>=1;i--) Faci[i-1]=Faci[i]*i%mod;
}
long long Binom(int n,int m){
    if(m<0||n<m) return 0;
    return Fac[n]*Faci[m]%mod*Faci[n-m]%mod; 
}
void solve(){
    bool pd=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]) pd=0;
    }
    if(pd){printf("%lld\n",fast_pow(2,n-1));return;}
    int l=0,r=n+1;long long sl=0,sr=0,ans=1;
    bool tag=0;
    while(l<r){
        int cntl=1+tag,cntr=1+tag,v=0;tag=1;
        while(!a[l+1]&&l+1<r) l++,cntl++,v++;
        while(!a[r-1]&&l+1<r) r--,cntr++,v++;
        // printf("%d %d %d\n",l,r,v);
        if(r==l+1){
            ans=ans*fast_pow(2,v+1)%mod;
            break;
        }
        if(min(cntl,cntr)>0){
            // printf("%d %d\n",cntl,cntr);
            long long sum=0;
            for(int i=1;i<=min(cntl,cntr);i++) sum=(sum+Binom(cntl-1,i-1)*Binom(cntr-1,i-1))%mod;
            ans=ans*sum%mod;
        }
        l++;r--;sl+=a[l];sr+=a[r];
        while(l+1<r&&sl!=sr){
            if(sl<sr){l++;sl+=a[l];}
            else{r--;sr+=a[r];}
        }
        if(l>=r) break;
        if(r==l+1&&sl!=sr) break;
    }
    printf("%lld\n",ans);
}
int main(){
    scanf("%d",&T);Pre_Fac(100000);
    while(T--) solve();
    return 0;
}