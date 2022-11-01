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
        int n,m;
        cin >> n >> m;
        vector<array<int,2>> v[2];
        for(int i=0;i<n;i++)
        {
            string s;
            cin >> s;
            for(int j=0;j<m;j++) if(s[j]=='1') v[(i+j)&1].push_back({i+j,i-j});
        }
        int res=0;
        for(auto &u:v)
        {
            ranges::sort(u,greater<>());
            vector<int> dp(n+m,(1<<30));
            dp[0]=-n-m;
            int lis=0;
            for(auto [x,y]:u)
            {
                int p=(ranges::lower_bound(dp,y)-dp.begin());
                dp[p]=y;
                lis=max(lis,p);
            }
            res+=lis;
        }
        cout << res << "\n";
    }
    return 0;
}