#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int dp[n+1], mo[n];
    pair <int, int> ho[m];
    for(int a=0; a<n; a++) cin>>mo[a];
    sort(mo, mo+n);
    for(int a=0; a<m; a++) cin>>ho[a].first>>ho[a].second;
    sort(ho, ho+m);
    for(int a=1; a<=n; a++) dp[a]=inf;
    dp[0]=0;
    for(int a=0; a<m; a++)
    {
        int suf=0;
        for(int b=0; b<n; b++) suf+=abs(ho[a].first-mo[b]);
        deque <pair <int, int> > qu;
        for(int b=0; b<=n; b++)
        {
            while(qu.size() and qu.back().first>dp[b]+suf) qu.pop_back();
            qu.push_back({dp[b]+suf, b});
            if(qu.front().second<b-ho[a].second) qu.pop_front();
            dp[b]=min(inf, qu.front().first-suf);
            if(b<n) suf-=abs(ho[a].first-mo[b]);
        }
    }
    if(dp[n]!=inf) cout<<dp[n];
    else cout<<-1;
}