#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int U[202];

int match(pair<int, int> x, pair<int, int> y)
{
    int ret = 0;
    if(x.first < y.first && y.first < x.second) ret++;
    if(x.first < y.second && y.second < x.second) ret++;
    return ret%2;
}

void solve()
{
    int n, k; cin >> n >> k;
    vector<pair<int, int>> E;
    vector<int> v;
    for(int i=1;i<=2*n;i++) U[i] = 0;
    for(int i=1;i<=k;i++)
    {
        int x, y; cin >> x >> y;
        if(x > y) swap(x, y);
        E.push_back({x, y});
        U[x] = 1;
        U[y] = 1;
    }
    for(int i=1;i<=2*n;i++)
    {
        if(!U[i]) v.push_back(i);
    }
    int m = v.size();

    for(int i=0;i<m/2;i++)
    {
        E.push_back({v[i], v[i+m/2]});
    }

    int ans = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ans += match(E[i], E[j]);
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
}