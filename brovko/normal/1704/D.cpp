#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;

using li = long long;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n][m];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];

        vector <int> s(n);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                s[i] += a[i][j] * j;

        int Min = min(s[0], s[1]);

        int x = 0;

        while(s[x] == Min)
            x++;

        cout << x + 1 << ' ' << s[x] - Min << "\n";
    }
}