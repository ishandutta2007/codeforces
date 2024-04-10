#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
int n;
vector<pair<int,int> > g[110000];
int ans[110000];
void dfs(int x,int pre,int col)
{
    for(auto p:g[x])
    {
        if (p.first==pre)continue;
        ans[p.second]=(col==0?2:3);
        dfs(p.first,x,col^1);
    }
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<n;i++)
        {
            int x,y; scanf("%d%d",&x,&y);
            g[x].pb(mp(y,i));
            g[y].pb(mp(x,i));
        }
        int flag=1;
        for(int i=1;i<=n;i++)
            if (g[i].size()>2)
            {
                flag=0;
                break;
            }
        if (!flag){puts("-1");continue; }
        int head; for(int i=1;i<=n;i++)if (g[i].size()==1){ head=i; break; }
        dfs(head,0,0);
        for(int i=1;i<n;i++)printf("%d ",ans[i]); puts("");
    }
    
}