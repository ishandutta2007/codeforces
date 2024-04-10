#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int n, l[sz], r[sz], an[sz], p[sz], an2[sz], pr[sz], us[sz];
set <int> pos;
void dfs(int v)
{
    us[v]=1;
    while(1)
    {
        auto it=pos.lower_bound(l[p[v]]);

        if(it!=pos.end() and (*it)==v) it++;

        if(it!=pos.end() and (*it)<=r[p[v]])
        {
            int to=(*it);
            if(us[to]==0) pr[to]=v, dfs(to);
            else if(us[to]==1)
            {
                an2[p[v]]=to;
                while(v!=to)
                {
                    an2[p[pr[v]]]=v;
                    v=pr[v];
                }
                cout<<"NO\n";
                for(int a=0; a<n; a++) printf("%d ", an[a]+1);
                cout<<"\n";
                for(int a=0; a<n; a++) printf("%d ", an2[a]+1);
                exit(0);
            }
        }
        else break;
    }
    us[v]=2, pos.erase(v);
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    vector <pair <int, int> > sp[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d%d", &l[a], &r[a]);
        l[a]--, r[a]--;
        sp[l[a]].push_back({r[a], a});
    }
    set <pair <int, int> > se;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sp[a].size(); b++) se.insert(sp[a][b]);
        int i=(*se.begin()).second;
        an[i]=a, an2[i]=a, p[a]=i;
        se.erase(se.begin());
    }
    for(int a=0; a<n; a++) pos.insert(a);
    for(int a=0; a<n; a++) if(us[a]==0) dfs(a);
    cout<<"YES\n";
    for(int a=0; a<n; a++) printf("%d ", an[a]+1);
}