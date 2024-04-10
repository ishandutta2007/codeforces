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

        if(k > (n - 1) / 2)
            cout << -1;
        else
        {
            for(int i = 0; i < n; i++)
                a[i] = i + 1;

            for(int i = 2; i < 2 + 2 * k; i += 2)
                swap(a[i], a[i - 1]);

            for(int i = 0; i < n; i++)
                cout << a[i] << ' ';
        }

        cout << "\n";
    }
}