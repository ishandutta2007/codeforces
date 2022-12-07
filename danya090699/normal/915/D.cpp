#include <bits/stdc++.h>
using namespace std;
const int sz=1e3;
int n, m, us[sz], to[sz];
bool sm[sz][sz];
vector <int> sv[sz];
int dfs(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(sm[v][ne] and us[ne]!=2)
        {
            to[v]=ne;
            if(us[ne]==1) return ne;
            else
            {
                int u=dfs(ne);
                if(u!=-1) return u;
            }
        }
    }
    us[v]=2;
    return -1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sm[u][v]=1;
        sv[u].push_back(v);
    }
    int u=-1;
    for(int a=0; a<n; a++)
    {
        if(us[a]==0)
        {
            u=dfs(a);
            if(u!=-1)
            {
                int cu=u, ok=0;
                while(1)
                {
                    int ne=to[cu], fo=-1;
                    sm[cu][ne]=0;
                    for(int b=0; b<n; b++) us[b]=0;
                    for(int b=0; b<n; b++)
                    {
                        if(us[b]==0)
                        {
                            fo=dfs(b);
                            if(fo!=-1) break;
                        }
                    }
                    if(fo==-1)
                    {
                        ok=1;
                        break;
                    }
                    sm[cu][ne]=1, cu=ne;
                    if(cu==u) break;
                }
                if(ok) cout<<"YES";
                else cout<<"NO";
                break;
            }
        }
    }
    if(u==-1) cout<<"YES";
}