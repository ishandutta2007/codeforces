#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
vector <int> sv[sz], st, sp[sz];
int n;
bool us[sz];
bool dfs(int v)
{
    sp[st.size()].push_back(v);
    st.push_back(v), us[v]=1;
    if(st.size()*2>=n)
    {
        printf("PATH\n%d\n", st.size());
        for(int a=0; a<st.size(); a++) printf("%d ", st[a]+1);
        printf("\n");
        st.pop_back();
        return true;
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(!us[ne])
        {
            if(dfs(ne))
            {
                st.pop_back();
                return true;
            }
        }
    }

    st.pop_back();
    return false;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int m;
        scanf("%d%d", &n, &m);
        for(int a=0; a<m; a++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            sv[u].push_back(v);
            sv[v].push_back(u);
        }
        for(int a=0; a<n; a++) us[a]=0;
        if(!dfs(0))
        {
            vector <pair <int, int> > an;
            for(int a=0; a<n; a++)
            {
                for(int b=0; b+1<sp[a].size(); b+=2) an.push_back({sp[a][b]+1, sp[a][b+1]+1});
            }
            printf("PAIRING\n%d\n", an.size());
            for(int a=0; a<an.size(); a++)
            {
                printf("%d %d\n", an[a].first, an[a].second);
            }

        }


        for(int a=0; a<n; a++)
        {
            sp[a].clear();
            sv[a].clear();
        }
    }
}