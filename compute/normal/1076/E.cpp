#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int maxn=3e5+7;
vector<PII> query[maxn];
vector<int> G[maxn];
long long tree[maxn];
long long ans[maxn];
int depth[maxn],reflect[maxn];
int st[maxn],ed[maxn];
void dfs(int now,int far)
{
    static int tot=0;
    st[now]=++tot;
    reflect[tot]=now;
    if(far==-1)
    {
        depth[now]=1;
    }
    for(int i=0;i<G[now].size();i++)
    {
        int v=G[now][i];
        if(v==far) continue;
        depth[v]=depth[now]+1;
        dfs(v,now);
    }
    ed[now]=tot;
}
void add(int x,int v)
{
    while(x<maxn)
    {
        tree[x]+=v;
        x+=x&-x;
    }
}
long long sum(int x)
{
    long long ret=0;
    while(x>0)
    {
        ret+=tree[x];
        x-=x&-x;
    }
    return ret;
}
int main()
{
    int n;
    memset(tree,0,sizeof(tree));
    scanf("%d",&n);
    for(int i=1,u,v;i<=n-1;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,-1);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int v,d,x;
        scanf("%d%d%d",&v,&d,&x);
        d+=depth[v];
        d=min(d,n);
        query[st[v]].push_back(make_pair(d,x));
        query[ed[v]+1].push_back(make_pair(d,-x));
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<query[i].size();j++)
        {
            PII temp=query[i][j];
            add(temp.first,temp.second);
        }
        ans[reflect[i]]=sum(n)-sum(depth[reflect[i]]-1);
    }
    for(int i=1;i<=n;i++)
    {
        printf("%lld ",ans[i]);
    }
}