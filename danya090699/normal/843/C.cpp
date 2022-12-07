//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int n, si[sz], c1, c2=-1, last, q=0, an[sz*2][3];
vector <int> sv[sz];
void siz(int v, int pr)
{
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            siz(ne, v);
            si[v]+=si[ne];
        }
    }
}
int find_ce(int v, int pr)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr and si[ne]>n/2) return find_ce(ne, v);
    }
    if(pr!=-1) si[pr]=n-si[v];
    return v;
}
void dfs(int v, int pr, int x, int ce)
{
    if(v!=x and pr!=x)
    {
        an[q][0]=ce, an[q][1]=last, an[q][2]=v;
        q++, last=v;
        an[q][0]=v, an[q][1]=pr, an[q][2]=x;
        q++;
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dfs(ne, v, x, ce);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    siz(0, -1);
    c1=find_ce(0, -1);
    for(int a=0; a<sv[c1].size(); a++)
    {
        int ne=sv[c1][a];
        if(si[ne]==n-si[ne]) c2=ne;
        else
        {
            last=ne;
            dfs(ne, c1, ne, c1);
            if(last!=ne)
            {
                an[q][0]=c1, an[q][1]=last, an[q][2]=ne, q++;
            }
        }
    }
    if(c2!=-1)
    {
        for(int a=0; a<sv[c2].size(); a++)
        {
            int ne=sv[c2][a];
            if(ne!=c1)
            {
                last=ne;
                dfs(ne, c2, ne, c2);
                if(last!=ne)
                {
                    an[q][0]=c2, an[q][1]=last, an[q][2]=ne, q++;
                }
            }
        }
    }
    cout<<q;
    for(int a=0; a<q; a++) printf("\n%d %d %d", an[a][0]+1, an[a][1]+1, an[a][2]+1);
}