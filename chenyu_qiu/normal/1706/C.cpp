#include "bits/stdc++.h"
using namespace std;
 
int t, n, h[100100], p[100100];
long long r[100100], l[100100];
 
int cost(int i)
{
    int x = 1 + max(h[i-1], h[i+1]) - h[i];
    return (x > 0 ? x : 0);
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
    freopen("i", "r", stdin); freopen("o", "w", stdout);
#endif
 
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> h[i];
 
        if (n&1)
        {
            long long ans = 0;
            for (int i = 1; i < n - 1; i += 2)
                ans += cost(i);
            cout << ans << '\n';
        }
        else
        {
            memset(p, 0, n << 2);
            memset(r, 0, n << 3);
            memset(l, 0, n << 3);
 
            for (int i = 1; i < n - 1; ++i)
                p[i] = cost(i);
 
            for (int i = 2; i < n; i += 2)
                l[i] = l[i - 2] + p[i - 1];
            
            for (int i = n - 3; i > 0; i -= 2)
                r[i] = r[i + 2] + p[i + 1];
 
            long long ans = r[1];
            for (int i = 0; i < n; i += 2)
                ans = min(ans, l[i] + r[i + 1]);
 
            cout << ans << '\n';
        }
    }
 
    return 0;
}