#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,mod=1e9+7,inv2=5e8+4;
int n,mx=1<<17,a[N],b[N],c[N],f[N],g[20][N],bit[N],ans;
void FWT_xor(int *a,int op){
    for(int i=1;i<mx;i<<=1)
        for(int j=0;j<mx;j+=i<<1)
            for(int k=0;k<i;k++){
                int p=j+k,q=i+p,x=a[p],y=a[q];
                a[p]=x+y;a[q]=x-y;
                if(op<0)a[p]=1ll*a[p]*inv2%mod,a[q]=1ll*a[q]*inv2%mod;
            }
}
void FWT_or(int *a,int op){
    for(int i=1;i<mx;i<<=1)
        for(int j=0;j<mx;j+=i<<1)
            for(int k=0;k<i;k++)
                (a[i+j+k]+=op*a[j+k])%=mod;
}
void FWT_and(int *a,int op){
    for(int i=1;i<mx;i<<=1)
        for(int j=0;j<mx;j+=i<<1)
            for(int k=0;k<i;k++)
                (a[j+k]+=op*a[i+j+k])%=mod;
}
int read(){
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x;
}
int main(){
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++)a[read()]++;
    for(int i=0;i<mx;i++)bit[i]=bit[i>>1]+(i&1),g[bit[i]][i]=b[i]=a[i];
    FWT_xor(b,1);
    for(int i=0;i<mx;i++)b[i]=1ll*b[i]*b[i]%mod;
    FWT_xor(b,-1);for(int i=0;i<=17;i++)FWT_or(g[i],1);
    for(int i=17;~i;i--){
        for(int j=0;j<mx;j++)c[j]=0;
        for(int j=0;j<=i;j++)
            for(int k=0;k<mx;k++)
                c[k]=(c[k]+1ll*g[j][k]*g[i-j][k])%mod;
        for(int j=0;j<mx;j++)g[i][j]=c[j];
        FWT_or(g[i],-1);
    }
    for(int i=0;i<mx;i++)c[i]=g[bit[i]][i];
    f[0]=0;f[1]=1;for(int i=2;i<mx;i++)f[i]=(f[i-1]+f[i-2])%mod;
    for(int i=0;i<mx;i++)a[i]=1ll*a[i]*f[i]%mod,b[i]=1ll*b[i]*f[i]%mod,c[i]=1ll*c[i]*f[i]%mod;
    FWT_and(a,1);FWT_and(b,1);FWT_and(c,1);
    for(int i=0;i<mx;i++)a[i]=1ll*a[i]*b[i]%mod*c[i]%mod;
    FWT_and(a,-1);
    for(int i=0;i<mx;i++)if(bit[i]==1)(ans+=a[i])%=mod;
    cout<<(ans+mod)%mod;
    return 0;
}