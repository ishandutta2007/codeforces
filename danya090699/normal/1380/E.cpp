#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int nu[m], an=m-1;
    set <int> se[m];
    for(int a=0; a<m; a++) nu[a]=a;
    for(int a=0; a<n; a++)
    {
        int i;
        scanf("%d", &i);
        i--;
        if(se[i].size())
        {
            auto it=se[i].end();
            it--;
            if((*it)!=a-1) an++;
        }
        se[i].insert(a);
    }
    cout<<an<<"\n";
    for(int a=0; a<m-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        int to=nu[u], fr=nu[v];
        if(se[to].size()<se[fr].size())
        {
            swap(fr, to), nu[u]=to;
        }
        vector <int> sp;
        for(auto it=se[fr].begin(); it!=se[fr].end(); it++)
        {
            sp.push_back(*it);
        }
        se[fr].clear();
        for(int a=0; a+1<sp.size(); a++)
        {
            if(sp[a]+1!=sp[a+1]) an--;
        }
        //cout<<fr<<" "<<to;
        for(int a=0; a<sp.size(); a++)
        {
            auto it=se[to].insert(sp[a]).first;
            int pr=-1, ne=-1;
            if(it!=se[to].begin())
            {
                it--, pr=(*it), it++;
            }
            it++;
            if(it!=se[to].end()) ne=(*it);

            if(pr!=-1 and ne!=-1) an--;

            if(pr!=-1 and pr+1!=sp[a]) an++;

            if(ne!=-1 and sp[a]+1!=ne) an++;
        }
        an--;
        printf("%d\n", an);
    }
}