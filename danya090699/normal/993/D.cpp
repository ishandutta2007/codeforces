#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=110, inf=1e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    map <int, vector <int> > ma;
    int ar[n][2];
    for(int a=0; a<2; a++) for(int b=0; b<n; b++) cin>>ar[b][a];
    for(int a=0; a<n; a++) ma[ar[a][0]].push_back(ar[a][1]);
    int m=ma.size();
    int dp[n+1][n*sz], dp2[n+1][n*sz];
    for(int a=0; a<=n; a++)
    {
        for(int b=0; b<n*sz; b++)
        {
            dp[a][b]=inf, dp2[a][b]=inf;
        }
    }
    dp[0][0]=0;
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        int mo=(*it).first;
        vector <int> &sp=(*it).second;
        sort(sp.begin(), sp.end(), greater <int>());
        int m=sp.size();
        for(int a=0; a<=n; a++)
        {
            for(int b=0; b<n*sz; b++)
            {
                if(dp[a][b]!=inf)
                {
                    int su=0;
                    for(int c=0; c<=m; c++)
                    {
                        int lef=max(0ll, a-c)+(m-c);

                        dp2[lef][b+su]=min(dp2[lef][b+su], dp[a][b]+mo*c);

                        if(c<m) su+=sp[c];
                    }
                }
            }
        }
        for(int a=0; a<=n; a++)
        {
            for(int b=0; b<n*sz; b++)
            {
                dp[a][b]=dp2[a][b], dp2[a][b]=inf;
            }
        }
    }
    int an=inf;
    for(int b=0; b<n*sz; b++)
    {
        if(dp[0][b]!=inf)
        {
            int x=dp[0][b];
            int cu=x/b, os=x%b;
            for(int i=0; i<3; i++)
            {
                os*=10, cu=cu*10+os/b;
                os%=b;
            }
            if(os) cu++;
            an=min(an, cu);
        }
    }
    cout<<an;
}