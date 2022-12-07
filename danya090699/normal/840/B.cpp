//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10;
vector <pair <int, int> > sv[sz];
int n, m, va[sz], st[sz], si[sz], qq=0;
bool us[sz], us2[sz];
void dfs(int v, int pr, int nu)
{
    us2[v]=1;
    //cout<<v<<" ";
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, nenu=sv[v][a].second;
        if(us2[ne]==0) dfs(ne, v, nenu);
    }
    if(va[v]!=-1 and st[v]%2!=va[v])
    {
        us[nu]=1, st[v]++, st[pr]++, qq++;
    }
}
void dfs2(int v, int nu)
{
    us2[v]=1;
    si[v]=va[v];
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, nenu=sv[v][a].second;
        if(us2[ne]==0)
        {
            dfs2(ne, nenu);
            si[v]+=si[ne];
        }
    }
    if(si[v]%2==1)
    {
        us[nu]=1, qq++;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    int fo=-1, q1=0;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &va[a]);
        if(va[a]==-1) fo=a;
        if(va[a]==1) q1++;
        st[a]=0, us2[a]=0;
    }
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(make_pair(v, a));
        sv[v].push_back(make_pair(u, a));
        us[a]=0;
    }
    //cout<<fo;
    if(fo!=-1)
    {
        dfs(fo, -1, -1);
        //cout<<fo<<" ";
        cout<<qq<<"\n";
        for(int a=0; a<m; a++)
        {
            if(us[a]) printf("%d\n", a+1);
        }
    }
    else
    {
        if(q1%2==1) cout<<-1;
        else
        {
            dfs2(0, -1);
            cout<<qq<<"\n";
            for(int a=0; a<m; a++)
            {
                if(us[a]) printf("%d\n", a+1);
            }
        }
    }
}