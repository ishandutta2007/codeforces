#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int *a, int *b){return (a[0]<b[0]);}
int n, m, cq=0, ***sm, **cnu;
bool *us;
vector <int*> *gor, *ver;
vector <int> *sv, tout;
void dfs(int y, int x)
{
    cnu[y][x]=cq;
    if(sm[y][x][0]!=-1) if(cnu[y][sm[y][x][0]]==-1) dfs(y, sm[y][x][0]);
    if(sm[y][x][1]!=-1) if(cnu[y][sm[y][x][1]]==-1) dfs(y, sm[y][x][1]);
    if(sm[y][x][2]!=-1) if(cnu[sm[y][x][2]][x]==-1) dfs(sm[y][x][2], x);
    if(sm[y][x][3]!=-1) if(cnu[sm[y][x][3]][x]==-1) dfs(sm[y][x][3], x);
}
void dfs2(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) dfs2(ne);
    }
    tout.push_back(v);
}
int main()
{
    ifstream in("input.txt");
    scanf("%d%d", &n, &m);
    gor=new vector <int*> [n], ver=new vector <int*> [m], sm=new int**[n], cnu=new int*[n];
    for(int a=0; a<n; a++)
    {
        sm[a]=new int*[m], cnu[a]=new int[m];
        for(int b=0; b<m; b++)
        {
            int x;
            scanf("%d", &x);
            gor[a].push_back(new int[2]);
            gor[a].back()[0]=x, gor[a].back()[1]=b;
            ver[b].push_back(new int[2]);
            ver[b].back()[0]=x, ver[b].back()[1]=a;
            sm[a][b]=new int[4], cnu[a][b]=-1;
        }
    }
    for(int a=0; a<n; a++)
    {
        sort(gor[a].begin(), gor[a].end(), comp);
        for(int b=0; b<m; b++)
        {
            int nu=gor[a][b][1], lnu=-1, rnu=-1;
            sm[a][nu][0]=-1, sm[a][nu][1]=-1;
            if(b!=0) lnu=gor[a][b-1][1];
            if(b+1!=m) rnu=gor[a][b+1][1];
            if(lnu!=-1) if(gor[a][b][0]==gor[a][b-1][0]) sm[a][nu][0]=lnu;
            if(rnu!=-1) if(gor[a][b][0]==gor[a][b+1][0]) sm[a][nu][1]=rnu;
        }
    }
    for(int a=0; a<m; a++)
    {
        sort(ver[a].begin(), ver[a].end(), comp);
        for(int b=0; b<n; b++)
        {
            int nu=ver[a][b][1], lnu=-1, rnu=-1;
            sm[nu][a][2]=-1, sm[nu][a][3]=-1;
            if(b!=0) lnu=ver[a][b-1][1];
            if(b+1!=n) rnu=ver[a][b+1][1];
            if(lnu!=-1) if(ver[a][b][0]==ver[a][b-1][0]) sm[nu][a][2]=lnu;
            if(rnu!=-1) if(ver[a][b][0]==ver[a][b+1][0]) sm[nu][a][3]=rnu;
        }
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            if(cnu[a][b]==-1)
            {
                dfs(a, b);
                cq++;
            }
        }
    }
    sv=new vector <int> [cq], us=new bool[cq];
    for(int a=0; a<cq; a++) us[a]=0;
    for(int a=0; a<n; a++)
    {
        for(int b=m-1; b>0; b--)
        {
            int nu1=gor[a][b][1], nu2=gor[a][b-1][1];
            if(gor[a][b][0]!=gor[a][b-1][0])
            {
                int c1=cnu[a][nu1], c2=cnu[a][nu2];
                sv[c1].push_back(c2);
            }
        }
    }
    for(int a=0; a<m; a++)
    {
        for(int b=n-1; b>0; b--)
        {
            int nu1=ver[a][b][1], nu2=ver[a][b-1][1];
            if(ver[a][b][0]!=ver[a][b-1][0])
            {
                int c1=cnu[nu1][a], c2=cnu[nu2][a];
                sv[c1].push_back(c2);
            }
        }
    }
    for(int a=0; a<cq; a++) if(us[a]==0) dfs2(a);
    int an[cq];
    for(int a=0; a<cq; a++)
    {
        int v=tout[a];
        an[v]=1;
        for(int b=0; b<sv[v].size(); b++)
        {
            int ne=sv[v][b];
            an[v]=max(an[v], an[ne]+1);
        }
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++) printf("%d ", an[cnu[a][b]]); //cout<<an[cnu[a][b]]<<" ";
        printf("\n");
    }
}