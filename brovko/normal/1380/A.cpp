#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, a[1005];

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

        int x = 1;

        while(x < n && a[x] < a[x - 1])
            x++;

        while(x < n && a[x] > a[x - 1])
            x++;

        x--;

        if(x == n - 1 || x == 0)
            cout << "NO\n";

        else cout << "YES\n" << x << ' ' << x + 1 << ' ' << x + 2 << "\n";
    }
}