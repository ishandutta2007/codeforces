/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 100002;

int n, k;

ll a[N_MAX], b[N_MAX];

ll aux[N_MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    if(k == 0)
    {
        ll sum = 0;
        ll ans = 0;
        for(int i = n; i >= 1; i--)
        {
            sum += a[i];
            ans = max(ans, sum - b[i]);
        }
        cout << ans << "\n";
    }
    if(k == 1)
    {
        ll ans = 0;
        ll sum = 0;
        for(int i = n; i >= 2; i--)
        {
            sum += a[i];
            ans = max(ans, sum - b[i]);
        }
        sum += a[1];
        ll suff = 0;
        for(int i = n; i >= 1; i--)
        {
            suff += a[i];
            aux[i] = max(aux[i + 1], suff - b[i]);
        }
        ll bmin = LLONG_MAX;
        ll pref = 0;
        for(int i = 1; i < n; i++)
        {
            pref += a[i];
            bmin = min(bmin, b[i]);
            ans = max(ans, pref - bmin);
            ans = max(ans, pref - bmin + aux[i + 1]);
        }
        ll amin = LLONG_MAX;
        for(int i = 2; i <= n; i++)
            amin = min(amin, a[i]);
        ans = max(ans, sum - amin - b[1]);
        cout << ans << "\n";
    }
    if(k >= 2)
    {
        ll ans = 0;
        ans = max(ans, a[n] - b[n]);
        ll bmin = LLONG_MAX;
        for(int i = 1; i < n; i++)
            bmin = min(bmin, b[i]);
        ll asum = 0;
        for(int i = 1; i <= n; i++)
            asum += a[i];
        ans = max(ans, asum - bmin);
        cout << ans << "\n";
    }
    return 0;
}