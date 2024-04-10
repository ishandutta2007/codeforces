#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, d, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> d;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);

        if(a[0] + a[1] <= d || a[n - 1] <= d)
            cout << "YES\n";
        else cout << "NO\n";
    }
}