//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int tin[sz], tout[sz], cnu[sz], up[17][sz], co[17][sz], timer=0, q=0;
vector <int> sv[sz];
void dfs(int v)
{
    cnu[v]=q, tin[v]=timer, timer++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs(ne);
    }
    tout[v]=timer, timer++;
}
bool is_pr(int u, int v){return (tin[v]>=tin[u] and tout[v]<=tout[u]);}
int go(int u, int v, int c)
{
    if(!(is_pr(v, u)))
    {
        for(int a=16; a>=0; a--)
        {
            if(!(is_pr(up[a][v], u)))
            {
                if(co[a][v]!=c) c=-1;
                v=up[a][v];
            }
        }
        if(co[0][v]!=c) c=-1;
    }
    return c;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        scanf("%d%d", &up[0][a], &co[0][a]);
        if(up[0][a]==-1) up[0][a]=a;
        else
        {
            up[0][a]--;
            sv[up[0][a]].push_back(a);
        }
    }
    for(int a=0; a<n; a++)
    {
        if(up[0][a]==a)
        {
            dfs(a), q++;
        }
    }
    for(int a=1; a<17; a++)
    {
        for(int b=0; b<n; b++)
        {
            up[a][b]=up[a-1][up[a-1][b]];
            if(co[a-1][b]==co[a-1][up[a-1][b]]) co[a][b]=co[a-1][b];
            else co[a][b]=-1;
        }
    }
    int qq;
    cin>>qq;
    for(int a=0; a<qq; a++)
    {
        int ty, u, v;
        scanf("%d%d%d", &ty, &u, &v);
        u--, v--;
        if(cnu[u]!=cnu[v] or u==v) printf("NO\n");
        else
        {
            if(ty==1)
            {
                if(is_pr(u, v) and go(u, v, 0)==0) printf("YES\n");
                else printf("NO\n");
            }
            else
            {
                if(!(is_pr(v, u)) and go(u, v, 1)==1 and go(v, u, 0)==0) printf("YES\n");
                else printf("NO\n");
            }
        }
    }
}