#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
string ty[sz];
vector <int> sv[sz], sv2[sz];
bool va[sz], us[sz];
void dfs(int v)
{
    for(int a=0; a<sv[v].size(); a++) dfs(sv[v][a]);
    if(ty[v]=="AND")
    {
        int x=sv[v][0], y=sv[v][1];
        va[v]=(va[x]&va[y]);
        va[x]^=1;
        if((va[x]&va[y])!=va[v]) sv2[v].push_back(x);
        va[x]^=1;
        va[y]^=1;
        if((va[x]&va[y])!=va[v]) sv2[v].push_back(y);
        va[y]^=1;
    }
    if(ty[v]=="OR")
    {
        int x=sv[v][0], y=sv[v][1];
        va[v]=(va[x]|va[y]);
        va[x]^=1;
        if((va[x]|va[y])!=va[v]) sv2[v].push_back(x);
        va[x]^=1;
        va[y]^=1;
        if((va[x]|va[y])!=va[v]) sv2[v].push_back(y);
        va[y]^=1;
    }
    if(ty[v]=="XOR")
    {
        int x=sv[v][0], y=sv[v][1];
        va[v]=(va[x]^va[y]);
        va[x]^=1;
        if((va[x]^va[y])!=va[v]) sv2[v].push_back(x);
        va[x]^=1;
        va[y]^=1;
        if((va[x]^va[y])!=va[v]) sv2[v].push_back(y);
        va[y]^=1;
    }
    if(ty[v]=="NOT")
    {
        int x=sv[v][0];
        va[v]=(!va[x]);
        sv2[v].push_back(x);
    }
}
void dfs2(int v)
{
    us[v]=1;
    for(int a=0; a<sv2[v].size(); a++) dfs2(sv2[v][a]);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        cin>>ty[a];
        if(ty[a]=="IN")
        {
            int x;
            scanf("%d", &x);
            va[a]=x;
        }
        else
        {
            int qq=2;
            if(ty[a]=="NOT") qq=1;
            for(int b=0; b<qq; b++)
            {
                int v;
                scanf("%d", &v);
                v--, sv[a].push_back(v);
            }
        }
    }
    dfs(0);
    dfs2(0);
    for(int a=0; a<n; a++)
    {
        if(ty[a]=="IN")
        {
            int x=va[0]^us[a];
            printf("%d", x);
        }
    }
}