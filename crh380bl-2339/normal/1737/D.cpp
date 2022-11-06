#include<bits/stdc++.h>
using namespace std;
long long a[505][505];
const long long INF=1LL<<61LL;
struct edge{
    int u,v,w;
    bool operator <(const edge z)const{
        return w<z.w;
    }
}e[505*500];
void work(){
    int n,m,i,j,k,u,v,w;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            a[i][j]=INF;
        }
        a[i][i]=0;
    }
    for(i=1;i<=m;++i){
        scanf("%d%d%d",&u,&v,&w);
        e[i].u=u;e[i].v=v;e[i].w=w;
        a[u][v]=1;
        a[v][u]=1;
    }
    for(k=1;k<=n;++k){
        for(i=1;i<=n;++i){
            for(j=1;j<=n;++j){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    // for(i=1;i<=n;++i){
    //     for(j=1;j<=n;++j)printf("%lld ",a[i][j]==INF?-1:a[i][j]);
    //     puts("");
    // }
    sort(e+1,e+1+m);
    long long ans=INF*2;
    for(i=1;i<=m;++i){
        if(i>1&&e[i].u==e[i-1].u&&e[i].v==e[i-1].v)continue;
        int d=n+5;
        for(int t=1;t<=n;++t){
            d=min(1LL*d,a[1][t]+a[n][t]+a[e[i].u][t]+1);
            d=min(1LL*d,a[1][t]+a[n][t]+a[e[i].v][t]+1);
            d=min(1LL*d,a[1][e[i].u]+a[n][e[i].v]);
            d=min(1LL*d,a[1][e[i].v]+a[n][e[i].u]);
        }
        ans=min(ans,1LL*e[i].w*(d+1));
    }
    printf("%lld\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}