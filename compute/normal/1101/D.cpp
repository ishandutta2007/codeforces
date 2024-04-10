#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
int arr[maxn];
vector<int> G[maxn];
vector<int> prime;
vector<int> facby[maxn];
vector<int> factor[maxn];
vector<int> id[maxn];
int n;
void db()
{
    for(int i=2;i<maxn;i++)
    {
        if(!factor[i].size())
        {
            prime.push_back(i);
            for(int j=i;j<maxn;j+=i)
            {
                factor[j].push_back(i);
                for(int k=0;k<id[j].size();k++)
                    facby[i].push_back(id[j][k]);
            }
        }
    }
}
bool vis[maxn];
pair<int,int> dfs(int u,int fa,int cur)
{
    vis[u]=1;
    pair<int,int> ret=make_pair(u,1);
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(arr[v]%cur!=0||v==fa) continue;
        auto tmp=dfs(v,u,cur);
        if(tmp.second>=ret.second)
        {
            ret=tmp;
            ret.second++;
        }
    }
    return ret;
}
void solve()
{
    int ans=0;
    for(int i=0;i<prime.size();i++)
    {
        int cur=prime[i];
        if(!facby[cur].size()) continue;
        memset(vis,0,sizeof(vis));
        for(int j=0;j<facby[cur].size();j++)
        {
            int index=facby[cur][j];
            if(!vis[index])
            {
                auto ret=dfs(index,-1,cur);
                ret=dfs(ret.first,-1,cur);
                ans=max(ans,ret.second);
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        id[arr[i]].push_back(i);
    }
    for(int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    db();
    solve();
}