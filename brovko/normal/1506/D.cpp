#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

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

        sort(a, a + n);

        int k = 0;

        for(int i = 0; i < n; i++)
            if(a[i] == a[n / 2])
                k++;

        cout << max(n % 2, 2 * k - n) << "\n";
    }
}