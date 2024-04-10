#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz], sp;
int us[sz], pr[sz], an=-1, cy=-1;
bool us2[sz];
void find_cy(int v, int pre)
{
    if(cy==-1)
    {
        pr[v]=pre;
        if(us[v]) cy=v;
        else
        {
            us[v]=1;
            for(int a=0; a<sv[v].size(); a++)
            {
                int ne=sv[v][a];
                if(ne!=an and us[ne]!=2) find_cy(ne, v);
            }
            us[v]=2;
        }
    }
}
int be(int a, int b, int rt)
{
    if(a==-1) return b;
    else if(b==-1) return a;
    else
    {
        int da=a-rt, db=b-rt;
        if(da<=0) da+=sp.size();
        if(db<=0) db+=sp.size();
        if(da>db) return a;
        else return b;
    }
}
void dfs(int v, int rt)
{
    us2[v]=1;
    us[v]=-1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us2[ne]==0)
        {
            if(us[ne]==-2) dfs(ne, rt);
            us[v]=be(us[v], us[ne], rt);
        }
    }
    us2[v]=0;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
    }
    for(int a=0; a<n; a++) if(us[a]==0) find_cy(a, -1);

    for(int a=0; a<n; a++) us[a]=-2;
    int v=cy;
    while(1)
    {
        sp.push_back(v);
        v=pr[v];
        if(v==cy) break;
    }
    reverse(sp.begin(), sp.end());
    int ot[sp.size()];
    for(int a=0; a<sp.size(); a++)
    {
        us[sp[a]]=a, ot[a]=a-1;
    }
    for(int a=0; a<sp.size(); a++)
    {
        int v=sp[a], cu=-1;
        for(int b=0; b<sv[v].size(); b++)
        {
            int ne=sv[v][b];
            if(us[ne]==-2) dfs(ne, a);
            cu=be(cu, us[ne], a);
        }
        if(cu>a)
        {
            if(a+1<=cu-1) ot[a+1]=max(ot[a+1], cu-1);
        }
        else
        {
            if(a+1<sp.size()) ot[a+1]=sp.size()-1;
            if(cu!=0) ot[0]=max(ot[0], cu-1);
        }
    }
    int rg=-1;
    for(int a=0; a<sp.size(); a++)
    {
        rg=max(rg, ot[a]);
        if(rg<a)
        {
            an=sp[a];
            break;
        }
    }
    for(int a=0; a<n; a++) us[a]=0;
    cy=-1;
    for(int a=0; a<n; a++) if(us[a]==0) find_cy(a, -1);
    if(cy==-1) cout<<an+1;
    else cout<<-1;
}