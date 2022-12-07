#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
vector <int> sv[sz];
int pr[sz], up[sz][20], us[sz];
void dfs(int v)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v])
        {
            pr[ne]=v, dfs(ne);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    k=n-k;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v), sv[v].push_back(u);
    }
    pr[n-1]=n-1;
    dfs(n-1);
    us[n-1]=1, k--;
    for(int a=0; a<n; a++) up[a][0]=pr[a];
    for(int a=1; a<20; a++)
    {
        for(int b=0; b<n; b++) up[b][a]=up[up[b][a-1]][a-1];
    }
    vector <int> an;
    for(int a=n-2; a>=0; a--)
    {
        int u=a, le=0;
        for(int b=19; b>=0; b--)
        {
            int ne=up[u][b];
            if(us[ne]==0)
            {
                u=ne, le+=(1<<b);
            }
        }
        if(us[a]==0) le++;
        if(le<=k)
        {
            int u=a;
            for(int b=0; b<le; b++)
            {
                us[u]=1, u=pr[u], k--;
            }
        }
        else an.push_back(a+1);
    }
    reverse(an.begin(), an.end());
    for(int a=0; a<an.size(); a++) printf("%d ", an[a]);
}