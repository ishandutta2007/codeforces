#include <bits/stdc++.h>
using namespace std;
const double inf=1e18;
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n;
        double C, T;
        cin>>n>>C>>T;
        pair <int, int> ta[n];
        for(int a=0; a<n; a++) cin>>ta[a].first>>ta[a].second;
        sort(ta, ta+n, greater <pair <int, int> >());
        double dp[n+1][n*10+1], dp2[n+1][n*10+1];
        for(int a=0; a<=n; a++)
        {
            for(int b=0; b<=n*10; b++)
            {
                dp[a][b]=inf*2;
                dp2[a][b]=inf*2;
            }
        }
        dp[0][0]=0;
        for(int a=0; a<n; a++)
        {
            int di=ta[a].first, poi=ta[a].second;
            for(int b=0; b<=a; b++)
            {
                for(int c=0; c<=b*10; c++)
                {
                    if(dp[b][c]<inf)
                    {
                        dp2[b][c]=min(dp2[b][c], dp[b][c]);
                        dp2[b+1][c+poi]=min(dp2[b+1][c+poi], dp[b][c]+di/pow(0.9, b+1));
                    }
                }
            }
            for(int b=0; b<=a+1; b++)
            {
                for(int c=0; c<=b*10; c++) dp[b][c]=dp2[b][c], dp2[b][c]=inf*2;
            }
        }
        int an=0;
        for(int a=1; a<=n; a++)
        {
            for(int b=0; b<=a*10; b++)
            {
                if(dp[a][b]<inf)
                {
                    double l=0, r=T;
                    for(int i=0; i<30; i++)
                    {
                        double p1=l+(r-l)/3, p2=l+(r-l)/3*2;
                        double va1=p1+10*a+dp[a][b]/(1+C*p1);
                        double va2=p2+10*a+dp[a][b]/(1+C*p2);
                        if(va1>va2) l=p1;
                        else r=p2;
                    }
                    if((l+10*a+dp[a][b]/(1+C*l))<T) an=max(an, b);
                }
            }
        }
        cout<<an<<"\n";
    }
}