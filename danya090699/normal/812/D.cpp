#include <bits/stdc++.h>
using namespace std;
int n, m, k, q, *la, *tin, *tout, *su, timer=0;
bool *us;
vector <int> *sv;
void dfs(int v)
{
    tin[v]=timer;
    timer++;
    su[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs(ne);
        su[v]+=su[ne];
    }
    tout[v]=timer;
    timer++;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m>>k>>q;
    sv=new vector <int>[n], la=new int[m], us=new bool[n], tin=new int[n], tout=new int[n], su=new int[n];
    for(int a=0; a<m; a++) la[a]=-1;
    for(int a=0; a<n; a++) us[a]=0;
    for(int a=0; a<k; a++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        if(la[y]!=-1)
        {
            sv[la[y]].push_back(x);
            us[x]=1;
        }
        la[y]=x;
    }
    for(int a=0; a<n; a++) if(us[a]==0) dfs(a);
    for(int a=0; a<q; a++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        int v=la[y];
        if(v==-1) cout<<0;
        else
        {
            if(tin[x]<tin[v] and tout[x]>tout[v]) cout<<su[x];
            else cout<<0;
        }
        cout<<"\n";
    }
}