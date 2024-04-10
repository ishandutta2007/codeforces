#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int k = 0, ans = 0;

        for(int i = 1; i < n - 1; i++)
        {
            k += (a[i] % 2 == 0);
            ans += (a[i] + 1) / 2;
        }

        if(k || n > 3  && ans > n - 2)
            cout << ans << "\n";
        else cout << "-1\n";
    }
}