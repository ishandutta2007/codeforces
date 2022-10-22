#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[200005];

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

        int ans = 0;
        a[n] = 0;

        for(int i = 1; i < n - 1; i++)
            if(a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                a[i + 1] = max(a[i], a[i + 2]);
                ans++;
            }

        cout << ans << "\n";

        for(int i = 0; i < n; i++)
            cout << a[i] << ' ';

        cout << "\n";
    }
}