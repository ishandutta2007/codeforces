#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    double dp[10][10];
    dp[9][0]=0;
    vector <pair <int, int> > sp;
    int ar[10][10];
    for(int r=9; r>=0; r--)
    {
        for(int a=0; a<10; a++) cin>>ar[r][a];
        if(r&1)
        {
            for(int c=0; c<10; c++) sp.push_back({r, c});
        }
        else
        {
            for(int c=9; c>=0; c--) sp.push_back({r, c});
        }
    }
    for(int a=1; a<sp.size(); a++)
    {
        int r=sp[a].first, c=sp[a].second, bad=0;
        //cout<<r<<" "<<c<<"\n";
        dp[r][c]=0;
        for(int b=1; b<=6; b++)
        {
            if(a>=b)
            {
                int nr=sp[a-b].first, nc=sp[a-b].second, l=ar[nr][nc];
                double cu=dp[nr][nc];
                if(l)
                {
                    cu=min(cu, dp[nr+l][nc]);
                }

                dp[r][c]+=cu;
            }
            else bad++;
        }
        dp[r][c]/=(6-bad);
        dp[r][c]+=1+(1.0*bad/(6-bad));
        //cout<<dp[r][c]<<"\n";
    }
    cout<<fixed<<setprecision(10)<<dp[0][0];
}