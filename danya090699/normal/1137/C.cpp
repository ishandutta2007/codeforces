#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, sz2=52;
int n, m, d, cnu[sz][sz2], su[sz*sz2], cq=0;
bool us[sz][sz2], q[sz], dp[sz*sz2];
long long mask[sz];
vector <int> sv[sz], rsv[sz], csv[sz*sz2], sp;
vector <pair <int, int> > tout;
pair <int, int> st[sz*sz2];
int yk[sz*sz2], pt;
int main()
{
    //freopen("input.txt", "r", stdin);

    cin>>n>>m>>d;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        rsv[v].push_back(u);
    }
    for(int a=0; a<n; a++)
    {
        mask[a]=0;
        char s[d+1];
        scanf("%s", s);
        for(int i=0; i<d; i++) if(s[i]=='1') mask[a]+=(1ll<<i);
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<d; b++)
        {
            cnu[a][b]=-1;
            if(us[a][b]==0)
            {
                st[0]={a, b}, pt=1, yk[0]=0, us[a][b]=1;
                while(pt)
                {
                    int v=st[pt-1].first, t=st[pt-1].second;
                    if(yk[pt-1]<sv[v].size())
                    {
                        int nv=sv[v][yk[pt-1]], nt=(t+1)%d;
                        yk[pt-1]++;
                        if(us[nv][nt]==0)
                        {
                            us[nv][nt]=1;
                            st[pt]={nv, nt}, pt++;
                            yk[pt-1]=0;
                        }
                    }
                    else
                    {
                        tout.push_back({v, t});
                        pt--;
                    }
                }
            }
        }
    }

    reverse(tout.begin(), tout.end());
    for(int a=0; a<tout.size(); a++)
    {
        int v=tout[a].first, t=tout[a].second;
        if(cnu[v][t]==-1)
        {
            st[0]={v, t}, pt=1, yk[0]=0, cnu[v][t]=cq;
            while(pt)
            {
                int v=st[pt-1].first, t=st[pt-1].second;
                if(yk[pt-1]==0)
                {
                    if(mask[v]&(1ll<<t))
                    {
                        if(q[v]==0)
                        {
                            q[v]=1;
                            sp.push_back(v);
                        }
                    }
                }
                if(yk[pt-1]<rsv[v].size())
                {
                    int nv=rsv[v][yk[pt-1]], nt=(t-1);
                    if(nt<0) nt+=d;
                    yk[pt-1]++;
                    if(cnu[nv][nt]==-1)
                    {
                        cnu[nv][nt]=cq;
                        st[pt]={nv, nt}, pt++;
                        yk[pt-1]=0;
                    }
                }
                else pt--;
            }

            su[cq]=sp.size();
            while(sp.size()) q[sp.back()]=0, sp.pop_back();
            cq++;
        }
    }

    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            int ne=sv[a][b];
            for(int t=0; t<d; t++)
            {
                int nt=(t+1)%d;
                int c1=cnu[a][t], c2=cnu[ne][nt];
                if(c1!=c2) csv[c1].push_back(c2);
            }
        }
    }

    for(int a=0; a<tout.size(); a++)
    {
        int nu=cnu[tout[a].first][tout[a].second];
        if(dp[nu]==0)
        {
            dp[nu]=1, sp.push_back(nu);
        }
    }
    while(sp.size())
    {
        int nu=sp.back();
        int be=0;
        for(int b=0; b<csv[nu].size(); b++)
        {
            int ne=csv[nu][b];
            be=max(be, su[ne]);
        }
        su[nu]+=be;
        sp.pop_back();
    }
    cout<<su[cnu[0][0]];
}