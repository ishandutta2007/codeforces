//Come on, make Togliatti great again!
#include <bits/stdc++.h>
#define iter map <int, int>::iterator
using namespace std;
const int sz=3e5+10;
int n, up[19][sz], tin[sz], tout[sz], h[sz], timer=0;
int c1=0, c2=-1, ma=0, q=1;
vector <int> sv[sz];
map <int, int> se[sz];
void dfs(int v, int he)
{
    tin[v]=timer, timer++;
    h[v]=he;
    for(int a=0; a<sv[v].size(); a++) dfs(sv[v][a], he+1);
    tout[v]=timer, timer++;
}
bool is_ne(int x, int y)
{
    return (tin[x]>=tin[y] and tout[x]<=tout[y]);
}
bool comp(int a, int b){return tin[a]<tin[b];}
int nex(int u, int v)
{
    if(is_ne(v, u))
    {
        int p=upper_bound(sv[u].begin(), sv[u].end(), v, comp)-sv[u].begin();
        return sv[u][p-1];
    }
    else return up[0][u];
}
int dis(int u, int v)
{
    if(tin[v]>tin[u]) swap(u, v);
    if(tout[v]>tout[u]) return h[u]-h[v];
    else
    {
        int v2=v;
        for(int a=18; a>=0; a--)
        {
            int ne=up[a][v];
            if(tout[ne]<tout[u]) v=ne;
        }
        v=up[0][v];
        return h[v2]-h[v]+h[u]-h[v];
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    n++;
    up[0][0]=0;
    for(int a=1; a<n; a++)
    {
        scanf("%d", &up[0][a]);
        up[0][a]--;
        sv[up[0][a]].push_back(a);
    }
    for(int a=1; a<19; a++)
    {
        for(int b=0; b<n; b++) up[a][b]=up[a-1][up[a-1][b]];
    }
    dfs(0, 0);
    se[0][0]=1;
    for(int a=1; a<n; a++)
    {
        if(c2==-1)
        {
            int le=dis(c1, a);
            if(le>=ma/2)
            {
                int v=nex(c1, a);
                if(le==ma/2)
                {
                    se[c1][v]++, q++;
                }
                else
                {
                    q-=se[c1][v], q++;
                    se[c1].erase(v);
                    if(le==1) se[v][v]++;
                    else
                    {
                        int u=nex(v, a);
                        se[v][u]++;
                    }
                    c2=v, ma++;
                }
            }
        }
        else
        {
            if(dis(c1, a)>dis(c2, a)) swap(c1, c2);
            int le=dis(c1, a);
            if(le>=ma/2)
            {
                int v=nex(c1, a);
                if(le==ma/2)
                {
                    se[c1][v]++, q++;
                }
                else
                {
                    iter it=se[c1].begin();
                    for(it; it!=se[c1].end(); it++) q-=(*it).second;
                    se[c1].clear();
                    it=se[c2].begin();
                    for(it; it!=se[c2].end(); it++) se[c1][c2]+=(*it).second;
                    se[c2].clear();
                    se[c1][v]++, q++;
                    c2=-1, ma++;
                }
            }
        }
        printf("%d\n", q);
    }
}