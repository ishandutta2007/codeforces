#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    ll res=(1ll<<60);
    for(int i=1;i<=n;i++)
    {
        ll now=0;
        ll x=0;
        for(int j=i+1;j<=n;j++)
        {
            ll c=(x+1+a[j]-1)/a[j];
            now+=c;
            x=c*a[j];
        }
        x=0;
        for(int j=i-1;j>=1;j--)
        {
            ll c=(x+1+a[j]-1)/a[j];
            now+=c;
            x=c*a[j];
        }
        res=min(res,now);
    }
    cout << res << "\n";
    return 0;
}