#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n;
char a[205][205];

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
            for(int j = 0; j < n; j++)
                cin >> a[i][j];

        int x = a[0][1] + a[1][0] - a[n - 1][n - 2] - a[n - 2][n - 1];

        vector <pair <int, int> > v;

        if(a[0][1] == '0' && x >= 0 || a[0][1] == '1' && x < 0)
            v.pb({1, 2});

        if(a[1][0] == '0' && x >= 0 || a[1][0] == '1' && x < 0)
            v.pb({2, 1});

        if(a[n - 1][n - 2] == '1' && x >= 0 || a[n - 1][n - 2] == '0' && x < 0)
            v.pb({n, n - 1});

        if(a[n - 2][n - 1] == '1' && x >= 0 || a[n - 2][n - 1] == '0' && x < 0)
            v.pb({n - 1, n});

        cout << v.size() << "\n";

        for(auto to:v)
            cout << to.x << ' ' << to.y << "\n";
    }
}