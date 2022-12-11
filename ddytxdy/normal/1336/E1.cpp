#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e6+50,mod=998244353,inv2=499122177;
int n,m,a[20][N],c[N],lim,bit[N],ans[N],num;LL b[60],x;
void insert(LL x){
    for(int i=m;~i;i--)if(x>>i&1){
        if(!b[i]){b[i]=x;num++;return;}
        x^=b[i];
    }
}
void dfs(int x,LL now){
    if(x<=m/2){
        int num=0;
        for(int i=m/2+1;i<=m;i++)num+=now>>i&1;//cout<<num<<"--";
        a[num][now&(lim-1)]++;return;
    }
    dfs(x-1,now);
    if(b[x])dfs(x-1,now^b[x]);
}
void dfs2(int x,int now){
    if(x==-1){c[now]++;return;}
    dfs2(x-1,now);
    if(b[x])dfs2(x-1,now^b[x]);
}
void FWT_xor(int *a,int op){
    for(int i=1;i<lim;i<<=1)
        for(int j=0;j<lim;j+=i<<1)
            for(int k=0;k<i;k++){
                int x=a[j+k],y=a[i+j+k];
                a[j+k]=(x+y)%mod,a[i+j+k]=(x-y)%mod;
                if(op<0)a[j+k]=1ll*a[j+k]*inv2%mod,a[i+j+k]=1ll*a[i+j+k]*inv2%mod;
            }
}
int power(int x,int y){
    int z=1;
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
    return z;
}
int main(){
    scanf("%d%d",&n,&m);lim=1<<(m/2+1);
    for(int i=0;i<lim;i++)bit[i]=bit[i>>1]+(i&1);
    for(int i=1;i<=n;i++)
        scanf("%lld",&x),insert(x);
    // for(int i=m;~i;i--)printf("%lld\n",b[i]);
    dfs(m,0);dfs2(m/2,0);
    // for(int i=0;i<lim;i++)printf("%d ",c[i]);puts("");
    FWT_xor(c,1);
    for(int i=0;i<=m-m/2;i++){
        FWT_xor(a[i],1);
        for(int j=0;j<lim;j++)a[i][j]=1ll*a[i][j]*c[j]%mod;
        FWT_xor(a[i],-1);
        for(int j=0;j<lim;j++)(ans[i+bit[j]]+=a[i][j])%=mod;
    }
    int dat=power(2,n-num);
    for(int i=0;i<=m;i++)printf("%d ",1ll*ans[i]*dat%mod);
    return 0;
}