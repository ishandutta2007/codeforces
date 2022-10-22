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

        int F = 1;

        for(int i = 0; i < n - 1; i++)
            if(a[i] > a[i + 1])
                F = 0;

        if(F)
        {
            cout << "0\n";
            continue;
        }

        if(a[n - 1] < 0 || a[n - 1] < a[n - 2])
        {
            cout << "-1\n";
            continue;
        }

        cout << n - 2 << "\n";

        for(int i = n - 3; i >= 0; i--)
            cout << i + 1 << ' ' << i + 2 << ' ' << n << "\n";
    }
}