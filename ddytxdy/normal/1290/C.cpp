#include<bits/stdc++.h>
using namespace std;
const int N=3e5+50,inf=1e9;
int n,k,p[N],q[N],b[N],w[N],f[N],g[N],ans;char s[N];
int find(int x){
    if(x==f[x])return x;
    int ff=f[x];
    f[x]=find(f[x]);
    g[x]=g[x]^g[ff];
    return f[x];
}
int main(){
    scanf("%d%d%s",&n,&k,s+1);
    for(int i=1;i<=n;i++)s[i]-='0',s[i]^=1;
    for(int i=1,x;i<=k;i++){
        scanf("%d",&x);
        for(int j=1,y;j<=x;j++)
            scanf("%d",&y),p[y]?q[y]=i:p[y]=i;
    }
    for(int i=1;i<=k;i++)b[i]=1,f[i]=i;
    for(int i=1;i<=n;i++){
        if(q[i]){
            int fx=find(p[i]),fy=find(q[i]);
            if(fx!=fy){
                ans-=min(b[fx],w[fx])+min(b[fy],w[fy]);
                int fl=g[p[i]]^g[q[i]]^s[i];
                f[fx]=fy;g[fx]=fl;
                b[fy]=min(b[fy]+(fl?w[fx]:b[fx]),inf);
                w[fy]=min(w[fy]+(fl?b[fx]:w[fx]),inf);
                ans+=min(b[fy],w[fy]);
            }
        }
        else if(p[i]){
            int ff=find(p[i]);
            ans-=min(b[ff],w[ff]);
            g[p[i]]^s[i]?w[ff]=inf:b[ff]=inf;
            ans+=min(b[ff],w[ff]);
        }
        printf("%d\n",ans);
    }
    return 0;
}