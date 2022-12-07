//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz2=30, sz=1e5+10;
int n, m, su[sz];
bool us[sz];
vector <pair <int, int> > sv[sz];
vector <int> good;
vector <bitset <sz2> > ma;
bool gauss(vector <bitset <sz2> > ma, int m)
{
    int n=sz2;
    bitset <sz2> us;
    for(int a=0; a<m; a++)
    {
        int fo=-1;
        for(int b=0; b<n; b++) if(ma[b][a] and us[b]==0) fo=b;
        if(fo!=-1)
        {
            for(int b=0; b<n; b++)
            {
                if(b!=fo and ma[b][a]) ma[b]^=ma[fo];
            }
            us[fo]=1;
        }
    }
    bool ok=1;
    for(int a=0; a<n; a++) if(us[a]==0 and ma[a][m]) ok=0;
    return ok;
}
void add(int x)
{
    int m=good.size();
    for(int a=sz2-1; a>=0; a--) ma[a][m]=((x&(1<<a))>0);
    if(gauss(ma, m)==0) good.push_back(x);
}
void dfs(int v, int pre, int x)
{
    us[v]=1, su[v]=x;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, pr=sv[v][a].second;
        if(ne!=pre)
        {
            if(us[ne]) add(su[v]^su[ne]^pr);
            else dfs(ne, v, x^pr);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v, pr;
        scanf("%d%d%d", &u, &v, &pr);
        u--, v--;
        sv[u].push_back(make_pair(v, pr));
        sv[v].push_back(make_pair(u, pr));
    }
    for(int a=0; a<sz2; a++)
    {
        bitset <sz2> x;
        ma.push_back(x);
    }
    for(int a=0; a<n; a++) us[a]=0;
    dfs(0, -1, 0);
    for(int a=0; a<sz2; a++) ma[a].reset();
    int an=0;
    for(int a=sz2-1; a>=0; a--)
    {
        int m2=good.size();
        for(int b=0; b<m2; b++) ma[a][b]=((good[b]&(1<<a))>0);
        ma[a][m2]=((su[n-1]&(1<<a))>0);
        if(gauss(ma, m2)==0)
        {
            an+=(1<<a);
            if(ma[a][m2]==0) ma[a][m2]=1;
            else ma[a][m2]=0;
        }
    }
    cout<<an;
}