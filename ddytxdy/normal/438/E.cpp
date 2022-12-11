#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50,mod=998244353;
int n,m,r[N],lo[N],rt[N],irt[N],inv[N],a[N],b[N];
int Glim(int n){int z=1;while(z<n)z<<=1;return z;}
void getr(int n){for(int i=1;i<n;i++)r[i]=r[i>>1]>>1^(i&1)<<lo[n];}
int power(int x,int y){
    int z=1;
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
    return z;
}
void init(int n){
    int lim=Glim(n);
    for(int i=2,j=0;i<=lim;i<<=1,j++)lo[i]=j,inv[i]=power(i,mod-2);
    for(int i=1;i<lim;i<<=1){
        int Wn=power(3,(mod-1)/(i*2));
        for(int k=0,w=1;k<i;k++,w=1ll*w*Wn%mod)rt[i+k]=w;
    }
    for(int i=1;i<lim;i++)irt[i]=power(rt[i],mod-2);
}
void NTT(int *a,int n,int op){
    for(int i=0;i<n;i++)if(i<r[i])swap(a[i],a[r[i]]);
    for(int i=1,*w=op>0?rt:irt;i<n;i<<=1)
        for(int j=0;j<n;j+=i<<1)
            for(int k=0;k<i;k++){
                int x=a[j+k],y=1ll*a[i+j+k]*w[i+k]%mod;
                a[j+k]=(x+y)%mod;a[i+j+k]=(x-y)%mod;
            }
    if(op<0)for(int i=0;i<n;i++)a[i]=1ll*a[i]*inv[n]%mod;
}
int c[N],d[N];
void Inv(int *a,int *b,int n){
    if(n==1){b[0]=power(a[0],mod-2);return;}
    int m=n+1>>1,lim=Glim(n+m);Inv(a,b,m);
    for(int i=0;i<lim;i++)c[i]=i<n?a[i]:0,d[i]=i<m?b[i]:0;
    getr(lim);NTT(c,lim,1);NTT(d,lim,1);
    for(int i=0;i<lim;i++)c[i]=1ll*c[i]*d[i]%mod*d[i]%mod;
    NTT(c,lim,-1);for(int i=m;i<n;i++)b[i]=-c[i];
}
int F[N],G[N],H[N],P[N];
void calc(int *a,int n){
    if(n==1){a[0]=1;return;}
    int m=n+1>>1,lim=Glim(2*n+m);calc(a,m);
    for(int i=0;i<lim;i++)F[i]=i<m?a[i]:0,G[i]=i<n?b[i]:0;
    getr(lim);NTT(F,lim,1);NTT(G,lim,1);
    for(int i=0;i<lim;i++)H[i]=2ll*F[i]*G[i]%mod;
    NTT(H,lim,-1);H[0]--;Inv(H,P,n);
    for(int i=n;i<lim;i++)P[i]=0;getr(lim);NTT(P,lim,1);
    for(int i=0;i<lim;i++)F[i]=(1ll*F[i]*F[i]%mod*G[i]%mod-F[i]+1)*P[i]%mod;
    NTT(F,lim,-1);
    for(int i=m;i<n;i++)a[i]=-F[i];
}
int main(){
    scanf("%d%d",&n,&m);init(3*(m+1));
    for(int i=1,x;i<=n;i++)scanf("%d",&x),b[x]=1;
    calc(a,m+1);
    for(int i=1;i<=m;i++)printf("%d\n",(a[i]+mod)%mod);
    return 0;
}
// 2 3
// 1 2