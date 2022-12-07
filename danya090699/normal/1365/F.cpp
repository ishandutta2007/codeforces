#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int ar[2][n];
        for(int i=0; i<2; i++)
        {
            for(int a=0; a<n; a++) scanf("%d", &ar[i][a]);
        }
        bool ok=1;
        if(n&1 and ar[0][n/2]!=ar[1][n/2]) ok=0;
        pair <int, int> sp[2][n/2];
        for(int i=0; i<2; i++)
        {
            for(int a=0; a<n/2; a++)
            {
                sp[i][a]={ar[i][a], ar[i][n-1-a]};
                if(sp[i][a].first>sp[i][a].second)
                {
                    swap(sp[i][a].first, sp[i][a].second);
                }
            }
            sort(sp[i], sp[i]+n/2);
        }
        for(int a=0; a<n/2; a++) if(sp[0][a]!=sp[1][a]) ok=0;
        printf(ok ? "Yes\n" : "No\n");
    }
}