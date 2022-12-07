//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
int n, q, last=0, mi[sz], pr[sz], be;
bool us[sz];
vector <int> sv[sz];
void dfs(int v)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v])
        {
            mi[ne]=min(ne+1, mi[v]);
            pr[ne]=v;
            dfs(ne);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>q;
    for(int a=0; a<n; a++) us[a]=0;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v), sv[v].push_back(u);
    }
    int ty, v;
    cin>>ty>>v;
    v=(v+last)%n;
    pr[v]=-1, mi[v]=v+1, us[v]=1, be=v+1;
    dfs(v);
    for(int a=1; a<q; a++)
    {
        scanf("%d%d", &ty, &v);
        v=(v+last)%n;
        if(ty==1)
        {
            if(us[v]==0)
            {
                int cu=v;
                while(us[cu]==0)
                {
                    us[cu]=1, be=min(be, cu+1);
                    cu=pr[cu];
                }
            }
        }
        else
        {
            if(us[v]) last=be;
            else last=min(be, mi[v]);
            printf("%d\n", last);
        }
    }
}