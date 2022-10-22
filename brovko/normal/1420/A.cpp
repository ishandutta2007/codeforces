#include <bits/stdc++.h>
#define int long long

using namespace std;

int t, n, a[50005], b[50005];

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
        {
            cin >> a[i];
            b[i] = a[i];
        }

        sort(a, a + n);

        int f = 0;

        for(int i = 0; i < n; i++)
        {
            if(a[i] != b[n - 1 - i] || (i != 0 && a[i] == a[i - 1]))
                f = 1;
        }

        if(f)
            cout << "YES\n";
        else cout << "NO\n";
    }
}