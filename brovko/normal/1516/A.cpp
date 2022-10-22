#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int t, n, k, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < k; i++)
        {
            int x = 0;

            while(a[x] == 0 && x < n)
                x++;

            if(x == n)
                x--;

            a[x]--;
            a[n - 1]++;
        }

        for(int i = 0; i < n; i++)
            cout << a[i] << ' ';

        cout << "\n";
    }
}