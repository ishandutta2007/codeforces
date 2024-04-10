#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
#define pii pair <int, int>

using namespace std;

int t, n, m, x, a[100005], b[100005], c[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m >> x;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        set <pii> q;

        for(int i = 1; i <= m; i++)
            q.insert({0, i});

        for(int i = 0; i <= m; i++)
            c[i] = 0;

        for(int i = 0; i < n; i++)
        {
            int x = (*q.begin()).y;

            q.erase({c[x], x});

            c[x] += a[i];
            b[i] = x;

            q.insert({c[x], x});
        }

        cout << "YES\n";

        for(int i = 0; i < n; i++)
            cout << b[i] << ' ';

        cout << "\n";
    }
}