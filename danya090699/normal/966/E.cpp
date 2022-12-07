#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz], sp[sz], q[sz], add[sz], yk[sz];
int n, m, pr[sz], si[sz], h[sz], hld[sz], bl[sz], an=0;
void dfs(int v)
{
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        h[ne]=h[v]+1, dfs(ne), si[v]+=si[ne];
    }
}
void dfs2(int v)
{
    if(sv[v].size())
    {
        vector <int> ve;
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a];
            ve.push_back(ne);
            if(si[ne]>si[ve[0]]) swap(ve[0], ve.back());
        }
        hld[ve[0]]=hld[pr[ve[0]]];
        sp[hld[ve[0]]].push_back(ve[0]);
        for(int a=1; a<ve.size(); a++)
        {
            hld[ve[a]]=ve[a], sp[ve[a]].push_back(ve[a]);
        }
        for(int a=0; a<sv[v].size(); a++) dfs2(sv[v][a]);
    }
}
bool comp(int a, int b){return si[a]<si[b];}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    pr[0]=0, hld[0]=0, sp[0].push_back(0), h[0]=0;
    for(int a=1; a<n; a++)
    {
        scanf("%d", &pr[a]);
        pr[a]--, sv[pr[a]].push_back(a);
    }
    dfs(0), dfs2(0);
    for(int a=0; a<n; a++) scanf("%d", &si[a]);
    for(int a=0; a<n; a++)
    {
        if(sp[a].size())
        {
            bl[a]=ceil(sqrt(sp[a].size()));
            for(int b=0; b<sp[a].size(); b+=bl[a])
            {
                int rg=min(b+bl[a], int(sp[a].size()));
                sort(sp[a].begin()+b, sp[a].begin()+rg, comp);
                add[a].push_back(0), yk[a].push_back(b);
                int p=b;
                while(p<rg)
                {
                    int st=p;
                    while(p<rg)
                    {
                        if(si[sp[a][p]]==si[sp[a][st]]) p++;
                        else break;
                    }
                    int qq=p-st;
                    for(st; st<p; st++) q[a].push_back(qq);
                }
            }
        }
    }
    for(int a=0; a<m; a++)
    {
        int v, d=-1;
        scanf("%d", &v);
        if(v<0) d=1;
        v=abs(v)-1;
        int u=hld[v], prh=h[v]+1;
        while(prh>0)
        {
            for(int b=0, nu=0; b<sp[u].size(); b+=bl[u], nu++)
            {
                int rg=min(b+bl[u], int(sp[u].size()));
                if(h[u]+rg-1<prh-1)
                {
                    add[u][nu]+=d;
                    int p=yk[u][nu];
                    if(d==-1 and p<rg)
                    {
                        if(si[sp[u][p]]+add[u][nu]<0)
                        {
                            an+=q[u][p], yk[u][nu]+=q[u][p];
                        }
                    }
                    if(d==1 and p-1>=b)
                    {
                        if(si[sp[u][p-1]]+add[u][nu]>=0)
                        {
                            an-=q[u][p-1], yk[u][nu]-=q[u][p-1];
                        }
                    }
                }
                else
                {
                    an-=yk[u][nu]-b, yk[u][nu]=b;
                    vector <int> v1, v2;
                    int fo=0;
                    for(int c=b; c<rg; c++)
                    {
                        int i=sp[u][c];
                        si[i]+=add[u][nu];
                        if(i==v)
                        {
                            si[i]-=n*d, fo=1;
                        }
                        else
                        {
                            if(h[i]<prh)
                            {
                                si[i]+=d, v1.push_back(i);
                            }
                            else v2.push_back(i);
                        }
                    }
                    if(fo) sp[u][rg-1]=v;
                    add[u][nu]=0;
                    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), sp[u].begin()+b, comp);
                    for(int c=rg-2; c>=b; c--) if(si[sp[u][c]]>si[sp[u][c+1]]) swap(sp[u][c], sp[u][c+1]);
                    int p=b;
                    while(p<rg)
                    {
                        int st=p;
                        while(p<rg)
                        {
                            if(si[sp[u][p]]==si[sp[u][st]]) p++;
                            else break;
                        }
                        int qq=p-st;
                        if(si[sp[u][st]]<0)
                        {
                            yk[u][nu]+=qq, an+=qq;
                        }
                        for(st; st<p; st++) q[u][st]=qq;
                    }
                    break;
                }
            }
            prh=h[u], u=hld[pr[u]];
        }
        printf("%d ", an);
    }
}