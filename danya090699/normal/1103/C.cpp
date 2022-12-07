#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
vector <int> sv[sz];
int n, m, k, us[sz], pr[sz], h[sz];
vector <int> an1;
vector <vector <int> > an2;
int de(int x, int y){return x/y+(x%y>0);}
void dfs(int v)
{
    us[v]=1;
    int le=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) pr[ne]=v, h[ne]=h[v]+1, le=0, dfs(ne);
    }
    if(le)
    {
        if(an1.size()==0)
        {
            if(h[v]+1>=de(n, k))
            {
                an1.push_back(v);
                while(pr[v]!=v) an1.push_back(pr[v]), v=pr[v];
            }
            else if(an2.size()<k)
            {
                int u1=-1, u2=-1;
                for(int a=0; a<sv[v].size(); a++)
                {
                    int ne=sv[v][a];
                    if(ne!=pr[v])
                    {
                        if(u1==-1) u1=ne;
                        else if(u2==-1) u2=ne;
                    }
                }
                if(h[u1]>h[u2]) swap(u1, u2);
                an2.resize(an2.size()+1);

                if((h[v]-h[u1]+1)%3!=0)
                {
                    while(v!=u1) an2.back().push_back(v), v=pr[v];
                    an2.back().push_back(v);
                }
                else if((h[v]-h[u2]+1)%3!=0)
                {
                    while(v!=u2) an2.back().push_back(v), v=pr[v];
                    an2.back().push_back(v);
                }
                else
                {
                    an2.back().push_back(v);
                    v=u2;
                    while(v!=u1) an2.back().push_back(v), v=pr[v];
                    an2.back().push_back(v);
                }
            }
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m>>k;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    pr[0]=0, h[0]=0, dfs(0);
    if(an1.size())
    {
        printf("PATH\n%d\n", an1.size());
        for(int a=0; a<an1.size(); a++) printf("%d ", an1[a]+1);
    }
    else
    {
        printf("CYCLES\n");
        for(int a=0; a<k; a++)
        {
            printf("%d\n", an2[a].size());
            for(int b=0; b<an2[a].size(); b++) printf("%d ", an2[a][b]+1);
            printf("\n");
        }
    }
}