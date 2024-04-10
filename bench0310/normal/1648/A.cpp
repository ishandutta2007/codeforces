#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    const int N=100000;
    vector<int> x[N+1];
    vector<int> y[N+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int c;
            cin >> c;
            x[c].push_back(i);
            y[c].push_back(j);
        }
    }
    ll res=0;
    auto go=[&](vector<int> &v)
    {
        ll s=0;
        ranges::sort(v);
        for(int i=0;i<(int)v.size();i++)
        {
            res+=(ll(i)*v[i]-s);
            s+=v[i];
        }
    };
    for(int i=1;i<=N;i++)
    {
        go(x[i]);
        go(y[i]);
    }
    cout << res << "\n";
    return 0;
}