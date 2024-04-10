#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10;
int q=1, ne[sz][26], pr[sz], prsy[sz], go[sz][26], link[sz], link2[sz];
multiset <int, greater <int> > se[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int nu[n], val[n];
    for(int a=0; a<n; a++)
    {
        val[a]=0;
        string str;
        cin>>str;
        int s=0;
        for(int b=0; b<str.size(); b++)
        {
            int sy=str[b]-'a';
            if(!ne[s][sy])
            {
                ne[s][sy]=q, pr[q]=s, prsy[q]=sy, q++;
            }
            s=ne[s][sy];
        }
        nu[a]=s;
        se[nu[a]].insert(0);
    }
    queue <int> qu;
    qu.push(0);
    while(qu.size())
    {
        int v=qu.front();
        if(v==0 or pr[v]==0) link[v]=0;
        else link[v]=go[link[pr[v]]][prsy[v]];

        if(se[link[v]].size()) link2[v]=link[v];
        else link2[v]=link2[link[v]];

        for(int i=0; i<26; i++)
        {
            if(ne[v][i])
            {
                go[v][i]=ne[v][i], qu.push(ne[v][i]);
            }
            else go[v][i]=go[link[v]][i];
        }
        qu.pop();
    }
    for(int a=0; a<m; a++)
    {
        int ty;
        scanf("%d", &ty);
        if(ty==1)
        {
            int i, x;
            scanf("%d%d", &i, &x);
            i--;
            se[nu[i]].erase(se[nu[i]].find(val[i]));
            val[i]=x;
            se[nu[i]].insert(val[i]);
        }
        else
        {
            string str;
            cin>>str;
            int s=0, an=-1;
            for(int b=0; b<str.size(); b++)
            {
                s=go[s][str[b]-'a'];
                int v=s;
                while(v)
                {
                    if(se[v].size()) an=max(an, *se[v].begin());
                    v=link2[v];
                }
            }
            printf("%d\n", an);
        }
    }
}