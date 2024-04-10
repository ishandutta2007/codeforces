#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    ll g=0;
    for(int i=2;i<=n;i++) g=gcd(g,a[i]-a[i-1]);
    for(int i=1;i<=m;i++)
    {
        ll b;
        cin >> b;
        cout << gcd(g,a[n]+b) << " \n"[i==m];
    }
    return 0;
}