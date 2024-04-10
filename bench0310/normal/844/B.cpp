#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> a[i][j];
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        array<ll,2> c={0,0};
        for(int j=1;j<=m;j++) c[a[i][j]]++;
        res+=((1ll<<c[0])-1);
        res+=((1ll<<c[1])-1);
    }
    for(int j=1;j<=m;j++)
    {
        array<ll,2> c={0,0};
        for(int i=1;i<=n;i++) c[a[i][j]]++;
        res+=((1ll<<c[0])-1);
        res+=((1ll<<c[1])-1);
    }
    cout << res-n*m << "\n";
    return 0;
}