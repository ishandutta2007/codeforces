#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using namespace std;

pair <int, int> f(vector <int> s)
{
    int n = s.size();

    int x = 0;

    while(x < n - 1 && s[x] <= s[x + 1])
        x++;

    if(x == n - 1)
        return {0, 0};

    int y = n - 1;

    while(y >= 0 && s[y] >= s[x])
        y--;

    swap(s[x], s[y]);

    bool F = 1;

    for(int i = 0; i < n - 1; i++)
        F &= (s[i] <= s[i + 1]);

    if(F)
        return {x, y};

    swap(s[x], s[y]);

    y = x + 1;

    x = 0;

    while(s[x] <= s[y])
        x++;

//    cout << x << ' ' << y << endl;

    return {x, y};
}

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

        vector <int> s(m);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                s[j] += a[i][j];

        pair <int, int> p = f(s);

        for(int i = 0; i < n; i++)
            swap(a[i][p.x], a[i][p.y]);

        bool F = 1;

        for(int i = 0; i < n; i++)
            for(int j = 1; j < m; j++)
                F &= (a[i][j] >= a[i][j - 1]);

        if(F)
            cout << p.x + 1 << ' ' << p.y + 1 << "\n";
        else cout << -1 << "\n";
    }
}