#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
int si[sz], q[sz], be=-1, bva=0, ok=1;
void dfs(int v, int pr)
{
    si[v]=0, q[v]=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v);
            if(si[ne]+1>si[v]) si[v]=si[ne]+1, q[v]=1;
            else if(si[ne]+1==si[v]) q[v]++;
        }
    }
    if(si[v]>bva and q[v]>1) bva=si[v], be=v;
}
void dfs2(int v, int pr, int h)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs2(ne, v, h+1);
        }
    }
    if(h==0)
    {
        if(sv[v].size()<3) ok=0;
    }
    else if(h<bva)
    {
        if(sv[v].size()<4) ok=0;
    }
    else
    {
        if(sv[v].size()>1) ok=0;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, 0);
    if(be!=-1 and k==bva)
    {
        dfs2(be, be, 0);
        if(ok) cout<<"Yes";
        else cout<<"No";
    }
    else cout<<"No";
}