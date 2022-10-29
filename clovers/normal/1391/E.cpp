#include<bits/stdc++.h>
using namespace std;
const int N=500005;
typedef pair<int,int> pii;
#define mk make_pair

int n,m,t,vis[N],dep[N],pre[N];
vector<int> v[N],ans[N];

void dfs(int u)
{
    vis[u]=1;
    ans[dep[u]].push_back(u);
    for(int i=0;i<(int)v[u].size();i++)
    {
        int to=v[u][i];
        if(vis[to]) continue;
        dep[to]=dep[u]+1; pre[to]=u;
        dfs(to);
    }
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) v[i].clear(),ans[i].clear();
        for(int i=1;i<=n;i++) vis[i]=0;
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y); v[y].push_back(x);
        }
        dep[1]=1; pre[1]=0; dfs(1);
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            if(dep[i]>=(n+1)/2)
            {
                flag=1; int now=i;
                puts("PATH");
                printf("%d\n",dep[i]);
                while(now)
                {
                    printf("%d ",now);
                    now=pre[now];
                }
                puts("");
                break;
            }
        }
        vector<pii> ANS; ANS.clear();
        if(!flag)
        {
            puts("PAIRING");
            int num=0;
            for(int i=2;i<=n;i++)
            {
                for(int j=0;j+1<(int)ans[i].size();j+=2)
                {
                    ANS.push_back(mk(ans[i][j],ans[i][j+1]));
                    num++;
                }
            }
            printf("%d\n",num);
            for(int i=0;i<ANS.size();i++)
            {
                printf("%d %d\n",ANS[i].first,ANS[i].second);
            }
        }
    }
    return 0;
}