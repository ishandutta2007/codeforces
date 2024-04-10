#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

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
        int n;
        cin >> n;

        int x[n], y[n];

        for(int i = 0; i < n; i++)
            cin >> x[i] >> y[i];

        sort(x, x + n);
        sort(y, y + n);

        if(n % 2 != 0)
            cout << 1 << "\n";
        else cout << (x[n / 2] - x[n / 2 - 1] + 1) * (y[n / 2] - y[n / 2 - 1] + 1) << "\n";
    }
}