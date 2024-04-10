#include <bits/stdc++.h>
#define int long long
#define ld long double

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

        int a[n];

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int x = 0;

        for(int i = 0; i < n; i++)
            if(a[i] < a[x])
                x = i;

        cout << n - 1 << "\n";

        for(int i = 0; i < n; i++)
            if(i != x)
        {
            cout << i + 1 << ' ' << x + 1 << ' ' << a[x] + abs(x - i) % 2 << ' ' << a[x] << "\n";
        }
    }
}