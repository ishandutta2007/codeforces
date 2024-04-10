#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        int x = 1, ans = 0;

        while(x < k)
        {
            ans++;
            x *= 2;
        }

        if(x >= n)
            cout << ans << "\n";
        else cout << ans + (n - x + k - 1) / k << "\n";
    }
}