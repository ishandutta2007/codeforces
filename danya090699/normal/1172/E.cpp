#include <bits/stdc++.h>
using namespace std;
const int sz=4e5+10;

struct el
{
    vector <pair <int, int> > su;
    map <int, int> on;
    int tot;
    long long sq;
    vector <int> sp, fen;
};

void fen_cha(vector <int> &fen, int p, int va)
{
    while(p<fen.size())
    {
        fen[p]+=va, p=p|(p+1);
    }
}
int fen_que(vector <int> &fen, int p)
{
    int re=0;
    while(p>=0)
    {
        re+=fen[p], p=(p&(p+1))-1;
    }
    return re;
}

int col[sz];

map <int, el> ver[sz];

int si[sz], pr[sz], h[sz], hld[sz];

vector <int> sta, last[sz], sv[sz];
set <int> dif[sz];

void dfs(int v)
{
    sta.push_back(v);
    for(auto it=dif[v].begin(); it!=dif[v].end(); it++)
    {
        int c=(*it);
        if(last[c].size())
        {
            int i=last[c].back();
            el &str=ver[sta[i]][c];
            if(!(str.su.size() and str.su.back().first==sta[i+1]))
            {
                str.su.push_back({sta[i+1], 0});
            }
        }
        last[c].push_back(sta.size()-1);
    }
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v])
        {
            pr[ne]=v, h[ne]=h[v]+1, dfs(ne), si[v]+=si[ne];
        }
    }
    sta.pop_back();
    for(auto it=dif[v].begin(); it!=dif[v].end(); it++) last[*it].pop_back();
}
void dfs2(int v)
{
    int be=-1;
    long long q=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v])
        {
            q+=1ll*si[ne]*si[ne];
            if(be==-1 or si[ne]>si[be]) be=ne;
        }
    }
    int out=(be==-1) ? 0 : si[be];
    q-=1ll*out*out;
    for(auto it=dif[v].begin(); it!=dif[v].end(); it++)
    {
        int c=(*it);
        el &str=ver[v][c];
        str.tot=si[v]-1-out;
        str.sq=q;
        for(int a=0; a<str.su.size(); a++)
        {
            if(str.su[a].first==be)
            {
                str.su.erase(str.su.begin()+a);
                break;
            }
        }
        sort(str.su.begin(), str.su.end());
        for(int a=0; a<str.su.size(); a++)
        {
            int ne=str.su[a].first;
            str.su[a].second=si[ne];
        }
        el &str2=ver[hld[v]][c];
        str2.sp.push_back(h[v]);
        str2.fen.push_back(out);
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v])
        {
            if(ne==be) hld[ne]=hld[v];
            else hld[ne]=ne;
            dfs2(ne);
        }
    }
}
pair <int, long long> get(int v, int c)
{
    el &str=ver[hld[v]][c];
    int p=lower_bound(str.sp.begin(), str.sp.end(), h[v])-str.sp.begin();
    int q=fen_que(str.fen, p);

    el &str2=ver[v][c];
    return make_pair(str2.tot+q, str2.sq+1ll*q*q);
}
long long an;
void cha(int v, int va)
{
    int c=col[v], u=-1;
    pair <int, long long> tr1 = get(v, c), tr2;
    int add=(tr1.first+1)*va;
    an-=tr1.second*va;

    if(va==-1) ver[hld[v]][c].on[h[v]]=v;
    else ver[hld[v]][c].on.erase(h[v]);

    while(u==-1)
    {
        int lg=0, rg=0;
        auto it=ver[hld[v]].find(c);
        if(it!=ver[hld[v]].end())
        {
            el &str=(*it).second;

            rg=lower_bound(str.sp.begin(), str.sp.end(), h[v])-str.sp.begin();

            auto it2=str.on.lower_bound(h[v]);
            if(it2!=str.on.begin())
            {
                it2--;
                int h=(*it2).first;
                lg=lower_bound(str.sp.begin(), str.sp.end(), h)-str.sp.begin();
                u=(*it2).second;

                tr2=get(u, c);
                an-=tr2.second;
            }
        }
        v=hld[v];
        if(u==-1)
        {
            if(dif[pr[v]].find(c)!=dif[pr[v]].end())
            {
                el &str2=ver[hld[pr[v]]][c];
                auto it=str2.on.find(h[pr[v]]);
                if(it!=str2.on.end())
                {
                    u=(*it).second;

                    tr2=get(u, c);
                    an-=tr2.second;
                }
                el &str=ver[pr[v]][c];
                str.tot+=add;
                int p=lower_bound(str.su.begin(), str.su.end(), make_pair(v, 0))-str.su.begin();
                int prva=str.su[p].second;
                str.sq-=1ll*prva*prva;
                str.sq+=1ll*(prva+add)*(prva+add);
                str.su[p].second+=add;
            }
        }
        if(lg<rg)
        {
            fen_cha((*it).second.fen, lg, add);
            fen_cha((*it).second.fen, rg, -add);
        }
        v=pr[v];
    }
    tr2=get(u, c);
    an+=tr2.second;
}
main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin>>n>>m;
    for(int a=1; a<=n; a++)
    {
        scanf("%d", &col[a]);
        dif[a].insert(col[a]);
        dif[0].insert(a);
    }
    sv[0].push_back(1);
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    int zap[m][2];
    for(int a=0; a<m; a++)
    {
        int v, c;
        scanf("%d%d", &v, &c);
        dif[v].insert(c);
        zap[a][0]=v, zap[a][1]=c;
    }
    dfs(0), dfs2(0);
    for(int a=0; a<=n; a++)
    {
        for(auto it=ver[a].begin(); it!=ver[a].end(); it++)
        {
            el &str=(*it).second;
            if(str.sp.size())
            {
                vector <int> sp(str.sp.size());
                for(int b=0; b<str.fen.size(); b++) sp[b]=str.fen[b], str.fen[b]=0;
                str.fen.resize(str.fen.size()+1);
                for(int b=0; b<sp.size(); b++)
                {
                    fen_cha(str.fen, b, sp[b]);
                    fen_cha(str.fen, b+1, -sp[b]);
                }
            }
        }
    }
    an=1ll*n*n*n;
    for(int a=1; a<=n; a++) ver[0][a].on[0]=0;
    for(int a=1; a<=n; a++) cha(a, -1);
    printf("%lld\n", 1ll*n*n*n-an);

    for(int a=0; a<m; a++)
    {
        int v=zap[a][0], x=zap[a][1];
        cha(v, 1);
        col[v]=x;
        cha(v, -1);
        printf("%lld\n", 1ll*n*n*n-an);
    }
}