#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[5002], b[5002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];

    ll ans = 0;

    for(int i=1;i<=n;i++) ans += a[i] * b[i];
    ll org = ans, tmp = ans;

    for(int i=1;i<=n;i++)
    {
        tmp = org;
        for(int j=1;j<=min(i, n-i+1);j++)
        {
            tmp -= a[i+j-1] * b[i+j-1];
            tmp -= a[i-j+1] * b[i-j+1];

            tmp += a[i+j-1] * b[i-j+1];
            tmp += a[i-j+1] * b[i+j-1];

            ans = max(ans, tmp);
        }
    }

    for(int i=1;i<n;i++)
    {
        tmp = org;
        for(int j=1;j<=min(i, n-i);j++)
        {
            tmp -= a[i-j+1] * b[i-j+1];
            tmp -= a[i+j] * b[i+j];

            tmp += a[i+j] * b[i-j+1];
            tmp += a[i-j+1] * b[i+j];
            ans = max(ans, tmp);
        }
    }

    cout << ans;
}