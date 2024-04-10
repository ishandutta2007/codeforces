#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int sm[n];
    for(int a=0; a<n; a++) sm[a]=(1<<a);
    for(int a=0; a<m; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sm[u]+=(1<<v), sm[v]+=(1<<u);
    }
    int dp[1<<n], pr[1<<n][2];
    for(int a=0; a<(1<<n); a++) dp[a]=inf;
    for(int a=1; a<(1<<n); a++)
    {
        int x=a;
        for(int b=0; b<n; b++) if(a&(1<<b)) x&=sm[b];
        if(x==a) dp[a]=0;
        for(int b=0; b<n; b++)
        {
            if(a&(1<<b))
            {
                if(dp[a|sm[b]]>dp[a]+1)
                {
                    dp[a|sm[b]]=dp[a]+1;
                    pr[a|sm[b]][0]=a;
                    pr[a|sm[b]][1]=b+1;
                }
            }
        }
    }
    int cu=(1<<n)-1;
    cout<<dp[cu]<<"\n";
    vector <int> an;
    while(dp[cu]>0)
    {
        an.push_back(pr[cu][1]);
        cu=pr[cu][0];
    }
    while(an.size())
    {
        cout<<an.back()<<" ";
        an.pop_back();
    }
}