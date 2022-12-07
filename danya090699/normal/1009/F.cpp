#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
vector <int> sv[sz], su[sz];
vector <pair <int, int> > ma[sz];
int nu[sz], an[sz];
void merge(int u, int v, int h)
{
    int d=su[u].size()-su[v].size();
    for(int a=0; a<su[v].size(); a++)
    {
        su[u][a+d]+=su[v][a];
        ma[u][a+d]=make_pair(su[u][a+d], h+su[v].size()-a);
        if(a+d>0)
        {
            if(ma[u][a+d-1].first>ma[u][a+d].first) ma[u][a+d]=ma[u][a+d-1];
        }
    }
}
void dfs(int v, int pr, int h)
{
    nu[v]=v;
    int be=v;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v, h+1);
            if(su[nu[ne]].size()>su[nu[be]].size()) be=ne;
        }
    }
    nu[v]=nu[be];
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=be and ne!=pr) merge(nu[be], nu[ne], h);
    }
    be=nu[v];
    su[be].push_back(1);
    ma[be].push_back(make_pair(1, h));
    if(ma[be].size()>1)
    {
        if(ma[be][ma[be].size()-2].first>1) ma[be].back()=ma[be][ma[be].size()-2];
    }
    an[v]=ma[be].back().second-h;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, -1, 0);
    for(int a=0; a<n; a++) printf("%d\n", an[a]);
}