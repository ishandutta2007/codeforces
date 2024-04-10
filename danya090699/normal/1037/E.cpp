#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    cin>>n>>m>>k;
    set <int> sv[n];
    int re[m][2], st[n];
    for(int a=0; a<n; a++) st[a]=0;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        re[a][0]=u, re[a][1]=v;
        sv[u].insert(v);
        sv[v].insert(u);
        st[u]++, st[v]++;
    }
    set <pair <int, int> > se;
    for(int a=0; a<n; a++) se.insert(make_pair(st[a], a));
    int an[m];
    //for(int b=0; b<n; b++) cout<<st[b]<<" ";
        //cout<<"\n";
    for(int a=m-1; a>=0; a--)
    {
        while(se.size())
        {
            int v=(*se.begin()).second;
            if(st[v]<k)
            {
                //cout<<a<<" "<<v<<" "<<st[v]<<"\n";
                se.erase(se.begin());
                for(auto it=sv[v].begin(); it!=sv[v].end(); it++)
                {
                    int ne=(*it);
                    sv[ne].erase(v);

                    se.erase(make_pair(st[ne], ne));
                    st[ne]--;
                    se.insert(make_pair(st[ne], ne));
                }
                sv[v].clear();
            }
            else break;
        }
        //for(int b=0; b<n; b++) cout<<st[b]<<" ";
        //cout<<"\n";
        an[a]=se.size();
        int u=re[a][0], v=re[a][1];
        if(sv[u].find(v)!=sv[u].end())
        {
            sv[u].erase(v), sv[v].erase(u);

            se.erase(make_pair(st[u], u));
            st[u]--;
            se.insert(make_pair(st[u], u));

            se.erase(make_pair(st[v], v));
            st[v]--;
            se.insert(make_pair(st[v], v));
        }
    }
    for(int a=0; a<m; a++) printf("%d\n", an[a]);
}