#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz];
int d1, d2, le=0, pr[sz];
long long an=0;
vector <pair <int, int> > sp;
pair <int, int> dfs(int v, int pre)
{
    pair <int, int> re(0, v), be1(0, v), be2(0, v);
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pre)
        {
            pair <int, int> cu=dfs(ne, v);
            if(cu.first>be1.first)
            {
                be2=be1, be1=cu;
            }
            else if(cu.first>be2.first) be2=cu;
            re=max(re, cu);
        }
    }
    if(be1.first+be2.first>le)
    {
        le=be1.first+be2.first, d1=be1.second, d2=be2.second;
    }
    re.first++;
    return re;
}
void dfs2(int v, int pre)
{
    pr[v]=pre;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pre) dfs2(ne, v);
    }
}
void dfs3(int v, int pre, int h, int to)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pre) dfs3(ne, v, h+1, to);
    }
    sp.push_back(make_pair(v, to));
    an+=h;
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
        sv[u].push_back(v), sv[v].push_back(u);
    }
    dfs(0, -1);
    dfs2(d1, -1);
    vector <int> way;
    while(d2!=d1)
    {
        way.push_back(d2), d2=pr[d2];
    }
    way.push_back(d1);
    for(int a=0; a<way.size(); a++)
    {
        int v=way[a], v1=-1, v2=-1, to=way[0], h=a;
        if(a>0) v1=way[a-1];
        if(a+1<way.size()) v2=way[a+1];
        if(le-a>a)
        {
            to=way.back(), h=le-a;
        }
        for(int b=0; b<sv[v].size(); b++)
        {
            int ne=sv[v][b];
            if(ne!=v1 and ne!=v2) dfs3(ne, v, h+1, to);
        }
    }
    for(int a=0; a<way.size()-1; a++)
    {
        sp.push_back(make_pair(way[a], way.back()));
        an+=le-a;
    }
    cout<<an<<"\n";
    for(int a=0; a<sp.size(); a++) printf("%d %d %d\n", sp[a].first+1, sp[a].second+1, sp[a].first+1);
}