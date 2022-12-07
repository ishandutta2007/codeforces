#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n[3];
        scanf("%d%d%d", &n[0], &n[1], &n[2]);
        vector <int> sp[3];
        for(int i=0; i<3; i++)
        {
            sp[i].resize(n[i]);
            for(int a=0; a<n[i]; a++) scanf("%d", &sp[i][a]);
            sort(sp[i].begin(), sp[i].end());
        }
        long long an=4e18;
        for(int c=0; c<3; c++)
        {
            for(int l=0; l<3; l++)
            {
                for(int r=0; r<3; r++)
                {
                    if(c!=l and c!=r and l!=r)
                    {
                        int ykl=-1, ykr=0;
                        for(int a=0; a<n[c]; a++)
                        {
                            while(ykl+1<n[l] and sp[l][ykl+1]<=sp[c][a]) ykl++;

                            while(ykr<n[r] and sp[r][ykr]<sp[c][a]) ykr++;

                            if(ykl!=-1 and ykr<n[r])
                            {
                                int x=sp[l][ykl], y=sp[c][a], z=sp[r][ykr];
                                long long cu=1ll*(x-y)*(x-y)+1ll*(x-z)*(x-z)+1ll*(y-z)*(y-z);
                                an=min(an, cu);
                            }
                        }
                    }
                }
            }
        }
        printf("%lld\n", an);
    }
}