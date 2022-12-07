#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector <int> sv[n];
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    map <vector <int>, vector <int> > se;
    for(int a=0; a<n; a++)
    {
        sort(sv[a].begin(), sv[a].end());
        se[sv[a]].push_back(a);
    }
    if(se.size()==3)
    {
        int yk=1, an[n];
        for(auto it=se.begin(); it!=se.end(); it++)
        {
            vector <int> &sp=(*it).second;
            if((*it).first.size()+sp.size()!=n)
            {
                cout<<-1;
                return 0;
            }
            bool us[n];
            for(int a=0; a<n; a++) us[a]=0;
            for(int a=0; a<sp.size(); a++) us[sp[a]]=1, an[sp[a]]=yk;
            for(int a=0; a<(*it).first.size(); a++)
            {
                if(us[(*it).first[a]])
                {
                    cout<<-1;
                    return 0;
                }
            }
            yk++;
        }
        for(int a=0; a<n; a++) printf("%d ", an[a]);
    }
    else cout<<-1;
}