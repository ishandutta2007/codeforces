#include <bits/stdc++.h>
using namespace std;
int *pr, *h, *ma;
vector <int> *sv;
void dfs(int v)
{
    ma[v]=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v])
        {
            h[ne]=h[v]+1, pr[ne]=v;
            dfs(ne);
            ma[v]=max(ma[v], ma[ne]+1);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, x, an=0;
    cin>>n>>x;
    x--;
    sv=new vector <int> [n], pr=new int[n], h=new int[n], ma=new int[n];
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sv[u].push_back(v), sv[v].push_back(u);
    }
    h[0]=0, pr[0]=-1;
    dfs(0);
    //cout<<h[x];
    int en=h[x]/2;
    while(h[x]>en)
    {
        //cout<<x<<" ";
        an=max(an, h[x]+ma[x]);
        x=pr[x];
    }
    cout<<an*2;
}