#include <bits/stdc++.h>
#define int long long

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

        int f = 0;

        for(int i = 0; i < n; i++)
            if(round(sqrt(a[i])) * round(sqrt(a[i])) != a[i])
                f = 1;

        if(f)
            cout << "YES\n";
        else cout << "NO\n";
    }
}