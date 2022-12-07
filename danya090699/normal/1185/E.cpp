#include <bits/stdc++.h>
using namespace std;
const int inf=2e9+10;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T)
    {
        T--;
        int n, m, ok=1;
        scanf("%d%d", &n, &m);
        char fi[n][m+1];
        for(int a=0; a<n; a++) scanf("%s", fi[a]);
        vector <pair <pair <int, int>, pair <int, int> > > an;
        for(char sy='z'; sy>='a'; sy--)
        {
            int l1=inf, r1=-inf, l2=inf, r2=-inf;
            for(int a=0; a<n; a++)
            {
                for(int b=0; b<m; b++)
                {
                    if(fi[a][b]==sy)
                    {
                        l1=min(l1, a), r1=max(r1, a), l2=min(l2, b), r2=max(r2, b);
                    }
                }
            }
            if(l1==inf)
            {
                if(an.size()) an.push_back(an.back());
            }
            else
            {
                if(l1==r1)
                {
                    for(int a=l2; a<=r2; a++) if(fi[l1][a]=='.' or fi[l1][a]<sy) ok=0;
                    an.push_back({{l1, l2}, {l1, r2}});
                }
                else if(l2==r2)
                {
                    for(int a=l1; a<=r1; a++) if(fi[a][l2]=='.' or fi[a][l2]<sy) ok=0;
                    an.push_back({{l1, l2}, {r1, l2}});
                }
                else ok=0;
            }
            if(ok==0) break;
        }
        if(ok)
        {
            reverse(an.begin(), an.end());
            printf("YES\n%d\n", an.size());
            for(int a=0; a<an.size(); a++)
            {
                printf("%d %d %d %d\n", an[a].first.first+1, an[a].first.second+1, an[a].second.first+1, an[a].second.second+1);
            }
        }
        else printf("NO\n");
    }
}