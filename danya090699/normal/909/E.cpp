#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, an=0;
    cin>>n>>m;
    set <pair <int, int> > se[2];
    int ty[n], q[n];
    vector <int> sv[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ty[a]);
        q[a]=0;
    }
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        sv[v].push_back(u), q[u]++;
    }
    for(int a=0; a<n; a++) se[ty[a]].insert(make_pair(q[a], a));
    while(se[0].size() or se[1].size())
    {
        while(se[0].size())
        {
            int v=(*se[0].begin()).second;
            if(q[v]>0) break;
            se[0].erase(se[0].begin());
            for(int a=0; a<sv[v].size(); a++)
            {
                int ne=sv[v][a];
                se[ty[ne]].erase(make_pair(q[ne], ne));
                q[ne]--;
                se[ty[ne]].insert(make_pair(q[ne], ne));
            }
        }
        if(se[1].size()==0) break;
        an++;
        while(se[1].size())
        {
            int v=(*se[1].begin()).second;
            if(q[v]>0) break;
            se[1].erase(se[1].begin());
            for(int a=0; a<sv[v].size(); a++)
            {
                int ne=sv[v][a];
                se[ty[ne]].erase(make_pair(q[ne], ne));
                q[ne]--;
                se[ty[ne]].insert(make_pair(q[ne], ne));
            }
        }
    }
    cout<<an;
}