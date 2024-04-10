#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, a[200005], b[200005];

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

        b[0] = a[0];

        for(int i = 1; i < n; i++)
            b[i] = a[i] - b[i - 1];

        int k = 0;

        for(int i = 0; i < n; i++)
            if(b[i] < 0)
                k++;

        int x = b[n - 1];
        int y = x;

        b[n - 1] -= x / 2;
        int f = 1 - abs(x % 2);

        if(x == 0 && k == 0)
            f = 2;

        for(int i = n - 2; i >= 0; i--)
        {
            if(b[i] < 0)
                k--;

            if(b[i + 1] < 0)
                k--;

            b[i] += x / 2;
            b[i + 1] -= x / 2;

            if(b[i] < 0)
                k++;

            if(b[i + 1] < 0)
                k++;

            int z = a[i] - a[i + 1];

            if(i % 2 != (n - 1) % 2)
                z = -z;

            if(k == 0 && f == 1 && z * 2 == y)
                f = 2;

            x = -x;
        }

        if(f == 2)
            cout << "YES\n";
        else cout << "NO\n";
    }
}