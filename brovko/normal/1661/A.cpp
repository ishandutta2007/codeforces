#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[30], b[30];

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

        for(int i = 0; i < n; i++)
            cin >> b[i];

        for(int i = 0; i < n; i++)
            if(a[i] > b[i])
                swap(a[i], b[i]);

        int ans = 0;

        for(int i = 1; i < n; i++)
        {
            ans += abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]);
        }

        cout << ans << "\n";
    }
}