#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<array<int,3>> edges(m);
    for(int i=0;i<m;i++) scanf("%d%d%d",&edges[i][1],&edges[i][2],&edges[i][0]);
    sort(edges.begin(),edges.end(),greater<array<int,3>>());
    int idx=0;
    vector<int> dp(n+1,0);
    while(idx<m)
    {
        int one=idx;
        vector<array<int,2>> now;
        while(idx<m&&edges[one][0]==edges[idx][0])
        {
            auto [w,a,b]=edges[idx];
            now.push_back({a,dp[b]+1});
            idx++;
        }
        for(auto [a,b]:now) dp[a]=max(dp[a],b);
    }
    int res=0;
    for(int i=1;i<=n;i++) res=max(res,dp[i]);
    printf("%d\n",res);
    return 0;
}