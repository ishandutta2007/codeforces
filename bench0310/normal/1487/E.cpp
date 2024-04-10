#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    array<int,4> n;
    vector<ll> a[4];
    vector<ll> dp[4];
    const ll inf=(1ll<<60);
    for(int i=0;i<4;i++) cin >> n[i];
    for(int i=0;i<4;i++)
    {
        a[i].assign(n[i]+1,0);
        dp[i].assign(n[i]+1,inf);
        for(int j=1;j<=n[i];j++)
        {
            cin >> a[i][j];
            dp[i][j]=inf;
        }
    }
    for(int j=1;j<=n[0];j++) dp[0][j]=a[0][j];
    for(int i=1;i<=3;i++)
    {
        multiset<ll> s;
        for(int j=1;j<=n[i-1];j++) s.insert(dp[i-1][j]);
        int m;
        cin >> m;
        vector<int> v[n[i]+1];
        for(int j=0;j<m;j++)
        {
            int x,y;
            cin >> x >> y;
            v[y].push_back(x);
        }
        for(int j=1;j<=n[i];j++)
        {
            for(int x:v[j]) s.erase(s.find(dp[i-1][x]));
            if(!s.empty()) dp[i][j]=min(inf,a[i][j]+(*s.begin()));
            for(int x:v[j]) s.insert(dp[i-1][x]);
        }
    }
    ll res=inf;
    for(int j=1;j<=n[3];j++) res=min(res,dp[3][j]);
    if(res==inf) res=-1;
    cout << res << "\n";
    return 0;
}