#include <bits/stdc++.h>
using namespace std;
bool comp(int a, int b){return (a>b);}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=2e9;
    cin>>n;
    int za[n];
    for(int a=0; a<n; a++) scanf("%d", &za[a]);
    vector <int> sv[n];
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    multiset <int, bool(*)(int, int)> se(&comp);
    for(int a=0; a<n; a++) se.insert(za[a]);
    for(int a=0; a<n; a++)
    {
        int cu=za[a];
        se.erase(se.find(za[a]));
        for(int b=0; b<sv[a].size(); b++)
        {
            int ne=sv[a][b];
            cu=max(cu, za[ne]+1);
            se.erase(se.find(za[ne]));
        }
        if(se.size()>0) cu=max(cu, (*se.begin())+2);
        an=min(cu, an);
        se.insert(za[a]);
        for(int b=0; b<sv[a].size(); b++)
        {
            int ne=sv[a][b];

            se.insert(za[ne]);
        }
    }
    cout<<an;
}