#include <bits/stdc++.h>
using namespace std;
const int sz=1e6, inf=1e9;
int q[sz], us[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    vector <int> di[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        int x=ar[a];
        for(int b=2; b*b<=x; b++)
        {
            if(x%b==0)
            {
                while(x%b==0) x/=b;
                di[a].push_back(b);
            }
        }
        if(x>1) di[a].push_back(x);
        int m=di[a].size();
        for(int mask=0; mask<(1<<m); mask++)
        {
            int cu=1;
            for(int i=0; i<m; i++) if(mask&(1<<i)) cu*=di[a][i];
            q[cu]++;
        }
    }
    int an=inf;
    for(int a=0; a<n; a++)
    {
        //if(us[ar[a]]==0)
        //{
            int m=di[a].size();
            int dp[1<<m], dp2[1<<m], qq[1<<m];
            for(int b=0; b<(1<<m); b++) dp[b]=inf, dp2[b]=inf;
            dp[(1<<m)-1]=0;
            for(int mask=(1<<m)-1; mask>=0; mask--)
            {
                int cu=1;
                for(int i=0; i<m; i++) if(mask&(1<<i)) cu*=di[a][i];
                qq[mask]=q[cu];
                for(int mask2=mask+1; mask2<(1<<m); mask2++) if((mask2&mask)==mask) qq[mask]-=qq[mask2];
                if(qq[mask])
                {
                    for(int b=0; b<(1<<m); b++)
                    {
                        if(dp[b]!=inf)
                        {
                            dp2[b&mask]=min(dp2[b&mask], dp[b]+1);
                            dp2[b]=min(dp2[b], dp[b]);
                        }
                    }
                    for(int b=0; b<(1<<m); b++) dp[b]=dp2[b], dp2[b]=inf;
                }
            }
            an=min(an, dp[0]+1);
            us[ar[a]]=1;
        //}
    }
    if(an==inf) cout<<-1;
    else cout<<an;
}