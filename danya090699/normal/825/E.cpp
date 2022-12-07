//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int n, m;
vector <int> sv[sz];
int q[sz], an[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    for(int a=0; a<n; a++) q[a]=0;
    for(int a=0; a<m; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sv[v].push_back(u);
        q[u]++;
    }
    set <int, greater <int> > se;
    for(int a=0; a<n; a++) if(q[a]==0) se.insert(a);
    for(int a=n; a>0; a--)
    {
        int v=*se.begin();
        an[v]=a;
        se.erase(se.begin());
        for(int b=0; b<sv[v].size(); b++)
        {
            int ne=sv[v][b];
            q[ne]--;
            if(q[ne]==0) se.insert(ne);
        }
    }
    for(int a=0; a<n; a++) cout<<an[a]<<" ";
}