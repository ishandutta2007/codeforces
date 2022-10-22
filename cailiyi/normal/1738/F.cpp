#include<bits/stdc++.h>
#define N 1000
using namespace std;
int T,n,d[N+5],p[N+5],fa[N+5];
bool vis[N+5];
inline int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i) scanf("%d",d+i),vis[i]=0,p[i]=fa[i]=i;
        sort(p+1,p+1+n,[&](int x,int y) {return d[x]>d[y];});
        for(int i=1;i<=n;++i)
        {
            int x=p[i],y;
            if(vis[x]) continue;
            vis[x]=1;
            for(int j=1;j<=d[x];++j)
            {
                printf("? %d\n",x),fflush(stdout);
                scanf("%d",&y),fa[find(y)]=find(x);
                if(vis[y]) break;
                vis[y]=1;
            }
        }
        printf("! ");
        for(int i=1;i<=n;++i) printf("%d%c",find(i)," \n"[i==n]);
        fflush(stdout);
    }
    return 0;
}