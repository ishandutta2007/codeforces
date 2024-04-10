#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+7;
int dep[maxn];
vector<int> G[maxn];
bool ok(vector<int> &a,vector<int> &b)
{
    if(a.size()<b.size()) return false;
    for(auto &p:b)
    {
        if(!binary_search(a.begin(),a.end(),p)) return false;
    }
    return true;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&dep[i]);
    for(int i=0,u,v;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++) sort(G[i].begin(),G[i].end());
    vector<int> q;
    q.push_back(dep[n]);
    int ans=0;
    for(int i=n-2;i>=0;i--)
    {
        if(ok(G[dep[i+1]],q)) ans++;
        else q.push_back(dep[i+1]); 
    }
    printf("%d\n",ans);
}