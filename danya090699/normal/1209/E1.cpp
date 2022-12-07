#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, m;
        cin>>n>>m;
        int ar[m][n*2];
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<m; b++) scanf("%d", &ar[b][a]), ar[b][a+n]=ar[b][a];
        }
        vector <pair <int, int> > sp;
        for(int a=0; a<m; a++)
        {
            int ma=0;
            for(int b=0; b<n; b++) ma=max(ma, ar[a][b]);
            sp.push_back({ma, a});
        }
        sort(sp.begin(), sp.end());
        reverse(sp.begin(), sp.end());
        while(sp.size()>n) sp.pop_back();

        int be[sp.size()][1<<n], dp[sp.size()+1][1<<n];
        for(int a=0; a<sp.size(); a++)
        {
            for(int mask=0; mask<(1<<n); mask++)
            {
                be[a][mask]=0;
                for(int st=0; st<n; st++)
                {
                    int cu=0;
                    for(int i=0; i<n; i++) if(mask&(1<<i)) cu+=ar[sp[a].second][i+st];
                    be[a][mask]=max(be[a][mask], cu);
                }
            }
        }
        for(int a=0; a<=sp.size(); a++) for(int b=0; b<(1<<n); b++) dp[a][b]=0;
        for(int a=0; a<sp.size(); a++)
        {
            for(int b=0; b<(1<<n); b++)
            {
                int mask=(1<<n)-1-b;
                for(int c=mask; ; c=(c-1)&mask)
                {
                    dp[a+1][b+c]=max(dp[a+1][b+c], dp[a][b]+be[a][c]);
                    if(c==0) break;
                }
            }
        }
        cout<<dp[sp.size()][(1<<n)-1]<<"\n";
    }
}