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
        vector<int> u(n+1,0);
        for(int i=1;i<=n;i++) cin >> u[i];
        vector<ll> s(n+1,0);
        for(int i=1;i<=n;i++) cin >> s[i];
        vector<vector<ll>> v(n+1);
        for(int i=1;i<=n;i++) v[u[i]].push_back(s[i]);
        vector<ll> res(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int m=v[i].size();
            sort(v[i].begin(),v[i].end(),greater<ll>());
            vector<ll> sum(m+1,0);
            for(int j=1;j<=m;j++) sum[j]=(sum[j-1]+v[i][j-1]);
            for(int k=1;k<=m;k++) res[k]+=(sum[(m/k)*k]);
        }
        for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    }
    return 0;
}