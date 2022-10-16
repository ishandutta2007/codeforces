#include <iostream>
#include <cstdio>
#define mod 998244353
using namespace std;
int t,n,u[200005],v[200005],first[100005],nxt[200005],f[100005],k,fg,c[100005];
void dfs(int now,int fa){
    int num=0;
    for (int i=first[now];i&&fg;i=nxt[i])
        if (v[i]!=fa){
            dfs(v[i],now);
            num+=1-c[v[i]];
        }
    if (num%k==0)c[now]=0;
    else if (num%k==k-1)c[now]=1;
    else fg=0;
    if (now==1&&c[now]!=0)fg=0;
    return;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for (int i=1;i<n;i++){
            scanf("%d%d",&u[i],&v[i]);
            nxt[i]=first[u[i]],first[u[i]]=i;
            u[i+n]=v[i],v[i+n]=u[i];
            nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
        }
        f[1]=1;
        for (int i=1;i<n;i++)f[1]=f[1]*2%mod;
        for (int i=2;i<n;i++){
            if ((n-1)%i==0){
                k=i,fg=1;
                dfs(1,0);
                if (fg==1)f[i]=1;
                for (int j=1;j<=n;j++)c[i]=0;
            }
        }
        for (int i=n;i>=1;i--)
            for (int j=i*2;j<=n;j+=i)f[i]-=f[j];
        for (int i=1;i<=n;i++)printf("%d ",f[i]);
        puts("");
        for (int i=1;i<=n;i++)f[i]=0;
        for (int i=1;i<=n*2;i++)first[i]=nxt[i]=0;
    }
    return 0;
}