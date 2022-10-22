#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, k, a[200005], b[200005];

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

        sort(a, a + n);

        for(int i = 0; i < k; i++)
            cin >> b[i];

        sort(b, b + k);

        int s = 0;
        int x = 0;
        int y = n - 1;

        for(int i = 0; i < k; i++)
        {
            if(b[i] == 1)
            {
                s += a[y];
                y--;
            }
        }

        for(int i = k - 1; i >= 0; i--)
        {
            if(b[i] != 1)
            {
                s += a[x];
                x += b[i] - 1;
            }
        }

        for(int i = n - k; i < n; i++)
            s += a[i];

        cout << s << "\n";
    }
}