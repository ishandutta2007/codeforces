#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int t, n, a[55];

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

        for(int i = 0; i < n; i++)
            if(a[i] != 2)
                ans++;

        cout << ans << "\n";
    }
}