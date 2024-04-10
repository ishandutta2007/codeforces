#include <bits/stdc++.h>
using namespace std;
vector <pair <int, int> > sp;
vector <int> re[4][4];
int ve_su[4], re_su[4][4], rq[4][4];
bool ch[4], us[4];
void dfs(int v)
{
    us[v]=1;
    for(int a=0; a<4; a++) if(rq[v][a] and us[a]==0) dfs(a);
}
int an=0;
void rec(int i)
{
    if(i==sp.size())
    {
        for(int s=0; s<4; s++)
        {
            for(int f=s; f<4; f++)
            {
                ch[s]^=1, ch[f]^=1;
                for(int a=0; a<4; a++) us[a]=0;
                dfs(s);
                int ok=1, cu=0;
                for(int a=0; a<4; a++)
                {
                    if(us[a])
                    {
                        cu+=ve_su[a];
                        if(ch[a]) ok=0;
                    }
                }
                if(us[f]==0) ok=0;
                if(ok)
                {
                    for(int a=0; a<sp.size(); a++)
                    {
                        int u=sp[a].first, v=sp[a].second;
                        if(us[u] and us[v] and rq[u][v]) cu+=re_su[u][v];
                    }
                    an=max(an, cu);
                }
                ch[s]^=1, ch[f]^=1;
            }
        }
    }
    else
    {
        int u=sp[i].first, v=sp[i].second;
        for(int ty=0; ty<2; ty++)
        {
            if(ty==0) rec(i+1);
            if(ty==1)
            {
                if(re[u][v].size())
                {
                    re_su[u][v]-=re[u][v][0], rq[u][v]--, rq[v][u]--, ch[u]^=1, ch[v]^=1;
                    rec(i+1);
                    re_su[u][v]+=re[u][v][0], rq[u][v]++, rq[v][u]++, ch[u]^=1, ch[v]^=1;
                }
            }
            if(ty==2)
            {
                bool q=rq[u][v]%2;
                rq[u][v]=0, rq[v][u]=0, ch[u]^=q, ch[v]^=q;
                rec(i+1);
                rq[u][v]=re[u][v].size(), rq[v][u]=re[u][v].size(), ch[u]^=q, ch[v]^=q;
            }
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int u, v, pr;
        cin>>u>>pr>>v;
        u--, v--;
        if(u>v) swap(u, v);
        ch[u]^=1, ch[v]^=1;
        if(u==v) ve_su[u]+=pr;
        else
        {
            re_su[u][v]+=pr, rq[u][v]++, rq[v][u]++;
            re[u][v].push_back(pr);
        }
    }
    for(int a=0; a<4; a++)
    {
        for(int b=a+1; b<4; b++)
        {
            sp.push_back(make_pair(a, b));
            sort(re[a][b].begin(), re[a][b].end());
        }
    }
    rec(0);
    cout<<an;
}