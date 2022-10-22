#include<bits/stdc++.h>
#define N 100000
using namespace std;
int T,n,a[N+5];
vector<int> e[N+5];
inline void dfs(int x,int fa,int deep)
{
    for(int y:e[x]) if(y!=fa) dfs(y,x,deep^1);
    a[x]=e[x].size();if(deep) a[x]=-a[x];
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i) e[i].clear();
        for(int i=1,u,v;i<n;++i)
        {
            scanf("%d %d",&u,&v);
            e[u].emplace_back(v);
            e[v].emplace_back(u);
        }
        dfs(1,0,0);
        for(int i=1;i<=n;++i)
            printf("%d ",a[i]);
        putchar('\n');
    }
    return 0;
}