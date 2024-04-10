#include <bits/stdc++.h>
#include <windows.h>
#define iter set <pair <long long, int> >::iterator
using namespace std;
const int sz=3e5+10;
vector <pair <int, int> > sv[sz], sv2[sz];
set <pair <long long, int> > se[sz];
iter pt[sz];
int q[sz], pr[sz], prw[sz];
long long su[sz], dp[sz][2];
void dfs(int v)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, w=sv[v][a].second;
        if(ne!=pr[v]) pr[ne]=v, prw[ne]=w, dfs(ne);
    }
}
void ins(int v, long long w, int to)
{
    if(pt[v]==se[v].end() or (*pt[v])>make_pair(w, to)) q[v]++, su[v]+=w;
    se[v].insert({w, to});
}

void del(int v, long long w, int to)
{
    if(pt[v]==se[v].end() or (*pt[v])>make_pair(w, to)) q[v]--, su[v]-=w;
    iter it=se[v].find({w, to});
    if(it==pt[v]) pt[v]++;
    se[v].erase(it);
}

void mov(int v, int qq)
{
    while(q[v]<qq) su[v]+=(*pt[v]).first, q[v]++, pt[v]++;

    while(q[v]>qq) q[v]--, pt[v]--, su[v]-=(*pt[v]).first;
}

void dfs2(int v, int x)
{
    int cut=sv[v].size()-x;
    dp[v][0]=0, dp[v][1]=0;
    for(int a=0; a<sv2[v].size(); a++)
    {
        int ne=sv2[v][a].first, w=sv2[v][a].second;
        dfs2(ne, x);
        if(dp[ne][0]>dp[ne][1]+w)
        {
            dp[v][0]+=dp[ne][1]+w, dp[v][1]+=dp[ne][1]+w;
            cut--;
        }
        else
        {
            dp[v][0]+=dp[ne][0], dp[v][1]+=dp[ne][0];
            ins(v, dp[ne][1]+w-dp[ne][0], ne);
        }
    }

    mov(v, max(0, cut));
    dp[v][0]+=su[v];
    mov(v, max(0, cut-1));
    dp[v][1]+=su[v];

    for(int a=0; a<sv2[v].size(); a++)
    {
        int ne=sv2[v][a].first, w=sv2[v][a].second;
        if(dp[ne][0]<=dp[ne][1]+w)
        {
            del(v, dp[ne][1]+w-dp[ne][0], ne);
        }
    }
}
main()
{
    int n;
    cin>>n;
    long long an[n];
    an[0]=0;
    for(int a=0; a<n-1; a++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--, v--;
        sv[u].push_back({v, w});
        sv[v].push_back({u, w});
        an[0]+=w;
    }
    dfs(0);
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            int to=sv[a][b].first, w=sv[a][b].second;
            if(to!=pr[a])
            {
                se[a].insert({w, to});
            }
        }
        pt[a]=se[a].begin(), q[a]=0, su[a]=0;
    }
    vector <int> sp[n+1], big;
    for(int a=0; a<n; a++) sp[sv[a].size()].push_back(a);

    for(int a=n-1; a; a--)
    {
        for(int b=0; b<sp[a+1].size(); b++)
        {
            int v=sp[a+1][b];
            for(int c=0; c<sv[v].size(); c++)
            {
                int to=sv[v][c].first;
                if(sv[to].size()>a+1 or (sv[to].size()==a+1 and pr[v]==to))
                {
                    int u1=v, u2=to;
                    if(pr[u1]==u2) swap(u1, u2);
                    sv2[u1].push_back({u2, prw[u2]});
                    del(u1, prw[u2], u2);
                }
            }
            big.push_back(v);
        }
        an[a]=0;
        for(int b=0; b<big.size(); b++)
        {
            int v=big[b];
            if(v==0 or sv[pr[v]].size()<=a)
            {
                dfs2(v, a);
                long long add=dp[v][0];
                if(v) add=min(add, dp[v][1]+prw[v]);
                an[a]+=add;
            }
        }
    }
    for(int a=0; a<n; a++) printf("%lld ", an[a]);
}