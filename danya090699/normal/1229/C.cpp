#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, sqr=500;
bool sm[410][sz], us[sz], fo[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector <int> sv[n];
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    int q=0, nu[n], va[n], bq[n], sq[n];
    long long an=0;
    for(int a=0; a<n; a++)
    {
        va[a]=a, bq[a]=0, sq[a]=0;
        if(sv[a].size()>sqr)
        {
            nu[a]=q++;
        }
        for(int b=0; b<sv[a].size(); b++)
        {
            int ne=sv[a][b];
            if(ne<a) sq[a]++;
            else bq[a]++;
            if(sv[a].size()>sqr) sm[nu[a]][ne]=1;
        }
        an+=1ll*bq[a]*sq[a];
    }
    printf("%lld\n", an);
    int qq;
    cin>>qq;
    int sp[qq];
    for(int a=0; a<qq; a++)
    {
        scanf("%d", &sp[a]);
        sp[a]--;
        int v=sp[a];
        if(sv[v].size()>sqr and fo[v])
        {
            for(int b=a-1; (b>=0 and sp[b]!=v); b--)
            {
                int ne=sp[b];
                if(us[ne]==0 and sm[nu[v]][ne] and va[ne]>va[v])
                {
                    an-=1ll*bq[ne]*sq[ne];
                    bq[ne]++, sq[ne]--;
                    an+=1ll*bq[ne]*sq[ne];
                    us[ne]=1;
                }
            }
            for(int b=a-1; (b>=0 and sp[b]!=v); b--) us[sp[b]]=0;
        }
        else
        {
            for(int b=0; b<sv[v].size(); b++)
            {
                int ne=sv[v][b];
                if(va[ne]>va[v])
                {
                    an-=1ll*bq[ne]*sq[ne];
                    bq[ne]++, sq[ne]--;
                    an+=1ll*bq[ne]*sq[ne];
                }
            }
        }
        fo[v]=1, va[v]=n+a, an-=1ll*bq[v]*sq[v], bq[v]=0, sq[v]=sv[v].size();

        printf("%lld\n", an);
    }
}