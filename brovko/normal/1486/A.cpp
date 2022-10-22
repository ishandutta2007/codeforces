#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int t, n, a[105];

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

        int x = 0, f = 1;

        for(int i = 0; i < n; i++)
        {
            x += a[i] - i;

            if(x < 0)
                f = 0;
        }

        if(f)
            cout << "YES\n";
        else cout << "NO\n";
    }
}