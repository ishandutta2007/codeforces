#include <bits/stdc++.h>
#define int long long
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

        sort(a, a + n);

        int x = 2, y = n - 2, s1 = a[0] + a[1], s2 = a[n - 1];

        while(x < y)
        {
            s1 += a[x];
            s2 += a[y];

            x++;
            y--;
        }

        if(s1 < s2)
            cout << "YES\n";
        else cout << "NO\n";
    }
}