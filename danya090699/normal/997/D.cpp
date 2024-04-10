#include <bits/stdc++.h>
using namespace std;
const int mod=998244353, sz=4e3+10, sz2=80;
int n[2], k;
int dp[sz2][sz], tr[sz2][sz2], q[2][sz2];
vector <int> sv[2][sz], sp;
int si[sz];
void siz(int i, int v, int pr)
{
    sp.push_back(v);
    si[v]=1;
    for(int a=0; a<sv[i][v].size(); a++)
    {
        int ne=sv[i][v][a];
        if(ne!=pr)
        {
            siz(i, ne, v);
            si[v]+=si[ne];
        }
    }
}
int find_ce(int i, int v, int pr, int qq)
{
    for(int a=0; a<sv[i][v].size(); a++)
    {
        int ne=sv[i][v][a];
        if(ne!=pr and si[ne]>qq/2) return find_ce(i, ne, v, qq);
    }
    if(pr!=-1) si[pr]=qq-si[v];
    return v;
}
void dfs2(int i, int v, int pr)
{
    sp.push_back(v);
    for(int a=0; a<sv[i][v].size(); a++)
    {
        int ne=sv[i][v][a];
        if(ne!=pr) dfs2(i, ne, v);
    }
}
void dfs(int i, int v, int qq)
{
    siz(i, v, -1);
    int ce=find_ce(i, v, -1, qq);

    int q0[k+1], q1[k+1];
    dp[0][ce]=1;
    for(int a=0; a<=k; a++)
    {
        q1[a]=dp[a][ce];
        for(int b=0; b<sp.size(); b++)
        {
            int v=sp[b];
            if(dp[a][v])
            {
                for(int c=0; c<sv[i][v].size(); c++)
                {
                    int ne=sv[i][v][c];
                    dp[a+1][ne]+=dp[a][v];
                    if(dp[a+1][ne]>=mod) dp[a+1][ne]-=mod;
                }
            }
        }
    }
    for(int a=0; a<=k; a++) for(int b=0; b<sp.size(); b++) dp[a][sp[b]]=0;
    sp.clear();


    for(int a=0; a<=k; a++) q0[a]=0;
    q0[0]=1;
    for(int a=0; a<sv[i][ce].size(); a++)
    {
        int ne=sv[i][ce][a];
        dp[1][ne]=1;
        sp.push_back(ce), dfs2(i, ne, ce);
        for(int b=1; b<=k; b++)
        {
            q0[b]=(q0[b]+1ll*(b-1)*dp[b][ce])%mod;
            for(int c=0; c<sp.size(); c++)
            {
                int v=sp[c];
                if(dp[b][v] and v!=ce)
                {
                    for(int d=0; d<sv[i][v].size(); d++)
                    {
                        int u=sv[i][v][d];
                        dp[b+1][u]+=dp[b][v];
                        if(dp[b+1][u]>=mod) dp[b+1][u]-=mod;
                    }
                }
            }
        }
        for(int b=0; b<=k; b++) for(int c=0; c<sp.size(); c++) dp[b][sp[c]]=0;
        sp.clear();
    }

    for(int a=0; a<=k; a++)
    {
        for(int b=0; a+b<=k; b++) q[i][a+b]=(q[i][a+b]+1ll*q0[a]*q1[b])%mod;
    }

    for(int a=0; a<sv[i][ce].size(); a++)
    {
        int ne=sv[i][ce][a];
        for(int b=0; b<sv[i][ne].size(); b++)
        {
            if(sv[i][ne][b]==ce) sv[i][ne].erase(sv[i][ne].begin()+b);
        }
        dfs(i, ne, si[ne]);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n[0]>>n[1]>>k;
    for(int a=0; a<=k; a++)
    {
        tr[a][0]=1, tr[a][a]=1;
        for(int b=1; b<a; b++) tr[a][b]=(tr[a-1][b-1]+tr[a-1][b])%mod;
    }
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<n[i]-1; a++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            sv[i][u].push_back(v);
            sv[i][v].push_back(u);
        }
        dfs(i, 0, n[i]);
    }

    int an=(1ll*n[0]*q[1][k])%mod;
    for(int a=2; a<=k; a++)
    {
        an=(an+1ll*((1ll*q[0][a]*q[1][k-a])%mod)*tr[k][a])%mod;
    }
    cout<<an;
}