#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, x, a[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> x;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);

        int s = 0, k = 0;

        for(int i = 0; i < n; i++)
        {
            s += a[i];

            if(a[i] == x)
                k++;
        }

        if(a[0] == x && a[n - 1] == x)
            cout << 0;

        else if(s == x * n || k > 0)
            cout << 1;

        else cout << 2;

        cout << "\n";
    }
}