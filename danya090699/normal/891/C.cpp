#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10, bsz=1e7;
char buf[bsz];
int byk;
void g_in(int &x)
{
    x=0;
    while(buf[byk]>='0' and buf[byk]<='9')
    {
        x=x*10+buf[byk]-'0', byk++;
    }
    byk++;
}
void nst()
{
    gets(buf), byk=0;
}

int pr[sz], si[sz], us[sz];
vector <pair <int, int> > sv[sz];
vector <pair <int, pair <int, int> > > zap[sz];
vector <pair <int, int> > re[sz];
int re2[sz][3];
bool an[sz], fo;
int find_se(int v)
{
    if(pr[v]==v) return v;
    else
    {
        pr[v]=find_se(pr[v]);
        return pr[v];
    }
}
void unite(int u, int v)
{
    u=find_se(u), v=find_se(v);
    if(u!=v)
    {
        if(si[u]<si[v]) swap(u, v);
        si[u]+=si[v], pr[v]=u;
    }
}
void dfs(int v, int pre)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, nu=sv[v][a].second;
        if(nu!=pre)
        {
            if(us[ne]) fo=1;
            else dfs(ne, nu);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q;
    nst(), g_in(n), g_in(m);
    for(int a=0; a<n; a++)
    {
        pr[a]=a, si[a]=1;
    }
    for(int a=0; a<m; a++)
    {
        int u, v, pri;
        nst(), g_in(u), g_in(v), g_in(pri);
        u--, v--;
        re[pri].push_back(make_pair(u, v));
        re2[a][0]=u, re2[a][1]=v, re2[a][2]=pri;
    }
    nst(), g_in(q);
    for(int a=0; a<q; a++)
    {
        int qq;
        nst(), g_in(qq);
        for(int b=0; b<qq; b++)
        {
            int nu;
            g_in(nu);
            nu--;
            int u=re2[nu][0], v=re2[nu][1], pri=re2[nu][2];
            zap[pri].push_back(make_pair(a, make_pair(u, v)));
        }
    }
    for(int a=0; a<sz; a++)
    {
        int yk=0;
        while(yk<zap[a].size())
        {
            fo=0;
            int st=yk, nu=zap[a][yk].first, qq=0;
            while(yk<zap[a].size())
            {
                if(zap[a][yk].first==nu)
                {
                    int u=zap[a][yk].second.first, v=zap[a][yk].second.second;
                    u=find_se(u), v=find_se(v);
                    zap[a][yk].second.first=u, zap[a][yk].second.second=v;
                    sv[u].push_back(make_pair(v, qq)), sv[v].push_back(make_pair(u, qq));
                    yk++, qq++;
                }
                else break;
            }
            for(int b=st; b<yk; b++)
            {
                int u=zap[a][b].second.first, v=zap[a][b].second.second;
                if(us[u]==0) dfs(u, -1);
            }
            if(fo) an[nu]=1;
            for(int b=st; b<yk; b++)
            {
                int u=zap[a][b].second.first, v=zap[a][b].second.second;
                us[u]=0, us[v]=0;
                sv[u].clear(), sv[v].clear();
            }
        }
        for(int b=0; b<re[a].size(); b++)
        {
            unite(re[a][b].first, re[a][b].second);
        }
    }
    char ok[]="YES", nok[]="NO";
    for(int a=0; a<q; a++)
    {
        if(an[a]) puts(nok);
        else puts(ok);
    }
}