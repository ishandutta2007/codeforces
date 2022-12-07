#include <bits/stdc++.h>
using namespace std;
const int inf=2e9+10;
int fr[1<<9], piz2[1<<9][3];
vector <pair <int, int> > piz[1<<9];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<n; a++)
    {
        int q, mask=0;
        scanf("%d", &q);
        for(int b=0; b<q; b++)
        {
            int i;
            scanf("%d", &i);
            mask+=(1<<(i-1));
        }
        fr[mask]++;
    }
    for(int a=0; a<m; a++)
    {
        int pr, q, mask=0;
        scanf("%d%d", &pr, &q);
        for(int b=0; b<q; b++)
        {
            int i;
            scanf("%d", &i);
            mask+=(1<<(i-1));
        }
        piz[mask].push_back({pr, a});
    }
    for(int a=0; a<(1<<9); a++)
    {
        sort(piz[a].begin(), piz[a].end());
        piz2[a][0]=inf;
    }
    for(int a=0; a<(1<<9); a++)
    {
        for(int b=0; b<(1<<9); b++)
        {
            if(piz[a].size() and piz[b].size())
            {
                int su=inf, i1, i2;
                if(a!=b)
                {
                    su=piz[a][0].first+piz[b][0].first;
                    i1=piz[a][0].second, i2=piz[b][0].second;
                }
                else if(piz[a].size()>1)
                {
                    su=piz[a][0].first+piz[a][1].first;
                    i1=piz[a][0].second, i2=piz[a][1].second;
                }
                if(su<piz2[a|b][0])
                {
                    piz2[a|b][0]=su;
                    piz2[a|b][1]=i1;
                    piz2[a|b][2]=i2;
                }
            }
        }
    }
    int be=-1, pri, bmask;
    for(int a=0; a<(1<<9); a++)
    {
        if(piz2[a][0]!=inf)
        {
            int q=0;
            for(int b=0; b<(1<<9); b++) if((b&a)==b) q+=fr[b];
            if(q>be or (q==be and piz2[a][0]<pri))
            {
                be=q, pri=piz2[a][0], bmask=a;
            }
        }
    }
    cout<<piz2[bmask][1]+1<<" "<<piz2[bmask][2]+1;
}