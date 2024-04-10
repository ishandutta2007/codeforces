#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> l(n);
        vector<int> r(n);
        vector<array<int,3>> v;
        for(int i=0;i<n;i++)
        {
            cin >> l[i] >> r[i];
            v.push_back({l[i],i,0});
            v.push_back({r[i],i,1});
        }
        sort(v.begin(),v.end());
        int idx=1;
        for(int i=0;i<2*n;i++)
        {
            if(i>0&&v[i][0]!=v[i-1][0]) idx++;
            if(v[i][2]==0) l[v[i][1]]=idx;
            else r[v[i][1]]=idx;
        }
        vector<vector<int>> dp(idx+2,vector<int>(idx+2,0));
        vector<vector<int>> one(idx+1);
        vector<vector<int>> two(idx+1);
        for(int i=0;i<n;i++)
        {
            dp[l[i]][r[i]]=1;
            one[l[i]].push_back(r[i]);
            two[r[i]].push_back(l[i]);
        }
        for(int o=1;o<=idx;o++)
        {
            for(int a=1;a+o-1<=idx;a++)
            {
                int b=a+o-1;
                int seg=dp[a][b];
                dp[a][b]=max(dp[a+1][b],dp[a][b-1])+seg;
                vector<int> now;
                for(int x:one[a]) if(a<=x&&x<b) dp[a][b]=max(dp[a][b],seg+dp[a][x]+dp[x+1][b]);
                for(int x:two[b]) if(a<=x-1&&x-1<b) dp[a][b]=max(dp[a][b],seg+dp[a][x-1]+dp[x][b]);
            }
        }
        cout << dp[1][idx] << "\n";
    }
    return 0;
}