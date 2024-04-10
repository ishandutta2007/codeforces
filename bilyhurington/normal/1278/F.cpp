#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long Fac[5010],Faci[5010];
long long fast_pow(long long x,long long k){
    long long ans=1;
    while(k){
        if(k&1) ans=ans*x%mod;
        x=x*x%mod;k>>=1;
    }return ans;
}
void Pre_Fac(int n){
    Fac[0]=1;for(int i=1;i<=n;i++) Fac[i]=Fac[i-1]*i%mod;
    Faci[n]=fast_pow(Fac[n],mod-2);
    for(int i=n;i>=1;i--) Faci[i-1]=Faci[i]*i%mod;
}
long long C(int n,int m){
    if(m<0||n<m) return 0;
    return Fac[n]*Faci[m]%mod*Faci[n-m]%mod;
}
int n,m,k,P,Q,PI,QI;
long long PW[5010];//i^k
int pri[5010],tot;bool vis[5010];
void Pre_Pow(int n){
    PW[1]=1;tot=0;
    memset(vis,0,sizeof(vis));
    for(int i=2;i<=n;i++){
        if(!vis[i]){pri[++tot]=i;PW[i]=fast_pow(i,n);}
        for(int j=1;j<=tot&&i*pri[j]<=n;j++){
            vis[i*pri[j]]=1;
            PW[i*pri[j]]=PW[i]*PW[pri[j]]%mod;
            if(i%pri[j]==0) break;
        }
    }
}
long long f[5010];
int main(){
    scanf("%d %d %d",&n,&m,&k);
    P=fast_pow(m,mod-2);Q=mod+1-P;
    PI=fast_pow(P,mod-2);QI=fast_pow(Q,mod-2);
    Pre_Fac(k);Pre_Pow(k);
    if(m==1){printf("%lld\n",fast_pow(n,k));return 0;}
    if(n<=k){
        long long ans=0;
        long long t1=1,t2=fast_pow(Q,n);
        for(int i=0;i<=n;i++){
            // printf("%d %lld %lld %lld %lld\n",i,C(n,i),t1,t2,PW[i]);
            ans=(ans+t1*t2%mod*PW[i]%mod*C(n,i))%mod;
            t1=t1*P%mod;t2=t2*QI%mod;
        }printf("%lld\n",ans);
    }else{f[k]=1;//puts("???");
        long long t=1,val=1;
        for(int i=k-1;i>=0;i--){
            t=t*(mod-P)%mod;val=val*(n-i-1)%mod;
            f[i]=(f[i+1]*Q%mod+t*val%mod*Faci[k-i]%mod)%mod;
            //C(n-i-1,k-i)
        }
        long long ans=0,t1=1,t2=1;
        for(int i=0;i<=k;i++){
            (ans+=PW[i]*t1%mod*f[i]%mod*t2%mod*Faci[i]%mod)%=mod;
            t1=t1*P%mod;t2=t2*(n-i)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}