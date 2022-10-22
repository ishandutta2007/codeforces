#include<bits/stdc++.h>
#include<bits/extc++.h>
#define N 200000
using namespace std;
int n,h[N+5],maxh,root,f[N+5];
long long ans;
vector<int> e[N+5];
inline void dfs(int x,int fa)
{
    for(int y:e[x]) if(y!=fa)
        dfs(y,x),f[x]=max(f[x],f[y]);
    if(f[x]<h[x] && x!=root)
        ans+=h[x]-f[x],f[x]=h[x];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",h+i);
        if(h[i]>maxh) maxh=h[i],root=i;
    }
    for(int i=1,u,v;i<n;++i)
    {
        scanf("%d %d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(root,0);
    int max1=0,max2=0;
    for(int y:e[root])
        if(f[y]>=max1) max2=max1,max1=f[y];
        else if(f[y]>max2) max2=f[y];
    ans+=h[root]*2-max1-max2;
    printf("%lld",ans);
    return 0;
}