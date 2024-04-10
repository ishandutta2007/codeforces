#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int del(int x,int y){return x>=y?x-y:x+mod-y;}
inline void Add(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void Del(int &x,int y){x-=y;if(x<0) x+=mod;}
struct num3{
    int val[3];
    num3(){val[0]=val[1]=val[2]=0;}
    num3 operator + (num3 x){
        num3 ans;
        for(int i=0;i<3;i++){
            ans.val[i]=add(val[i],x.val[i]);
        }
        return ans;
    }
    num3 operator - (num3 x){
        num3 ans;
        for(int i=0;i<3;i++){
            ans.val[i]=del(val[i],x.val[i]);
        }
        return ans;
    }
    num3 operator * (num3 x){
        num3 ans;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i+j>=3) Add(ans.val[i+j-3],1ll*val[i]*x.val[j]%mod);
                else Add(ans.val[i+j],1ll*val[i]*x.val[j]%mod);
            }
        }
        return ans;
    }
};
const int MAXN=6e6;
long long fast_pow(long long x,long long k){
    long long ans=1;
    while(k){
        if(k&1) ans=ans*x%mod;
        x=x*x%mod;k>>=1;
    }
    return ans;
}
const int inv3=fast_pow(3,mod-2);
long long Fac[MAXN+10],Fac_inv[MAXN+10];
void Pre_Fac(){
    Fac[0]=1;for(int i=1;i<=MAXN;i++) Fac[i]=Fac[i-1]*i%mod;
    Fac_inv[MAXN]=fast_pow(Fac[MAXN],mod-2);
    for(int i=MAXN;i>=1;i--) Fac_inv[i-1]=Fac_inv[i]*i%mod;
}
long long Binom(int x,int y){
    if(y<0||x<y) return 0;
    return Fac[x]*Fac_inv[y]%mod*Fac_inv[x-y]%mod;
}
int n,q;
num3 N[MAXN+10];
num3 Em(int x){
    num3 ans;
    ans.val[0]=x;
    return ans;
}
int main(){
    scanf("%d %d",&n,&q);Pre_Fac();
    N[0].val[0]=n+1;N[0].val[1]=N[0].val[2]=n;
    num3 E;E.val[1]=1;
    for(int i=1;i<=3*n;i++){
        N[i]=E*(N[i-1]-Em(Binom(3*n,i))-Em(Binom(3*n,i-1)));
        // printf("%d %d %d\n",N[i].val[0],N[i].val[1],N[i].val[2]);
        num3 tmp;long long t=Binom(3*n+1,i+1);
        // printf("%lld\n",t);
        tmp.val[0]=(t+N[i].val[0]-N[i].val[1]+mod)*inv3%mod;
        tmp.val[1]=(t+N[i].val[1]-N[i].val[2]+mod)*inv3%mod;
        tmp.val[2]=(t+N[i].val[2]-N[i].val[0]+mod)*inv3%mod;
        N[i]=tmp;
        // printf("%d %d %d\n",N[i].val[0],N[i].val[1],N[i].val[2]);
    }
    for(int ti=1,x;ti<=q;ti++){
        scanf("%d",&x);
        printf("%d\n",N[x].val[0]);
    }
    // system("pause");
    return 0;
}
//(1-E)*N[i]=E*(N[i-1]-C(3n,i)-C(3n,i-1))
//v0,v1,v2 
//v0-v2=x
//v1-v0=y
//v2-v1=z
//v0+v1+v2=C(3n+1,i+1);
//v0=(C(3n+1,i+1)+x-y)/3;
//v1=(C(3n+1,i+1)+y-z)/3;