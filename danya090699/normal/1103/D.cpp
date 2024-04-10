#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, d=0;
    cin>>n>>k;
    int ar[n], ex[n];
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &ar[a]);
        d=__gcd(d, ar[a]);
    }
    for(int a=0; a<n; a++) scanf("%lld", &ex[a]);

    vector <int> di;
    for(int a=2; a*a<=d; a++)
    {
        if(d%a==0)
        {
            while(d%a==0) d/=a;
            di.push_back(a);
        }
    }
    if(d>1) di.push_back(d);

    int m=di.size();

    map <int, vector <int> > ma;
    for(int a=0; a<n; a++)
    {
        int x=ar[a], mask=1;
        for(int b=0; b<m; b++)
        {
            while(x%di[b]==0) x/=di[b], mask*=di[b];
        }
        vector <int> &ve=ma[mask];
        ve.push_back(ex[a]);
        sort(ve.begin(), ve.end());
        if(ve.size()>m) ve.pop_back();
    }

    int dp[1<<m][m+1], dp2[1<<m][m+1];
    for(int a=0; a<(1<<m); a++) for(int b=0; b<=m; b++) dp[a][b]=inf, dp2[a][b]=inf;
    dp[(1<<m)-1][0]=0;
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        int x=(*it).first, ok[1<<m];
        for(int b=0; b<(1<<m); b++)
        {
            int va=x;
            for(int c=0; c<m; c++)
            {
                if((b&(1<<c))==0)
                {
                    while(va%di[c]==0) va/=di[c];
                }
            }
            if(va<=k) ok[b]=1;
            else ok[b]=0;
        }
        vector <int> &sp=(*it).second;
        for(int b=0; b<sp.size(); b++)
        {
            int va=sp[b];
            for(int mask=0; mask<(1<<m); mask++)
            {
                for(int q=0; q<=m; q++)
                {
                    if(dp[mask][q]!=inf)
                    {
                        dp2[mask][q]=min(dp2[mask][q], dp[mask][q]);
                        for(int mask2=mask; mask2; mask2=(mask2-1)&mask)
                        {
                            if(ok[mask2]) dp2[mask-mask2][q+1]=min(dp2[mask-mask2][q+1], dp[mask][q]+va);
                        }
                    }
                }
            }
            for(int mask=0; mask<(1<<m); mask++)
            {
                for(int q=0; q<=m; q++) dp[mask][q]=dp2[mask][q], dp2[mask][q]=inf;
            }
        }
    }
    int be=inf;
    for(int a=0; a<=m; a++) if(dp[0][a]!=inf) be=min(be, dp[0][a]*a);
    if(be!=inf) cout<<be;
    else cout<<-1;
}