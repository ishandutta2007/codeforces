#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
//#define y second
#define pb push_back

using namespace std;

int n, m, a[1005][1005], d[1000005];
set <int> s[1000005];
vector <int> ep;
map <pair <int, int>, int> q;

void rec(int v)
{
    if(s[v].empty())
    {
        ep.pb(v);
        return;
    }

    int u = (*s[v].begin());

    q[{v, u}]--;
    q[{u, v}]--;

    if(q[{v, u}] == 0)
    {
        s[v].erase(u);
        s[u].erase(v);
    }

    rec(u);
    rec(v);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 1; j < m; j++)
            if(a[i][j] && a[i][j - 1])
            {
                s[i * m + j].insert(i * m + j - 1);
                s[i * m + j - 1].insert(i * m + j);

                q[{i * m + j, i * m + j - 1}]++;
                q[{i * m + j - 1, i * m + j}]++;

                d[i * m + j]++;
                d[i * m + j - 1]++;
            }

    for(int i = 1; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] && a[i - 1][j])
            {
                s[i * m + j].insert(i * m + j - m);
                s[i * m + j - m].insert(i * m + j);

                q[{i * m + j, i * m + j - m}]++;
                q[{i * m + j - m, i * m + j}]++;

                d[i * m + j]++;
                d[i * m + j - m]++;
            }

    int cnt = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cnt += a[i][j];

    if(cnt < 3)
    {
        cout << -1;
        return 0;
    }

    int x = 0;

    while(x < n * m && d[x] % 2 == 0)
        x++;

    int y = n * m;

    if(x < n * m)
    {
        y = x + 1;

        while(y < n * m && d[y] % 2 == 0)
            y++;

        s[x].insert(y);
        s[y].insert(x);

        q[{x, y}]++;
        q[{y, x}]++;
    }

    for(int i = 0; i < n * m; i++)
        if(i != x && i != y && d[i] % 2)
        {
            cout << -1;
            return 0;
        }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == 1 && s[i * m + j].empty())
            {
                cout << -1;
                return 0;
            }

    int F = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] && F++ == 0)
                rec(i * m + j);

    for(int i = 0; i < n * m; i++)
        if(s[i].size())
        {
            cout << -1;
            return 0;
        }

    int ans = 0, k = 0, t = 0;

    for(int i = 1; i < ep.size(); i++)
    {
        int t2 = 0;

        if(abs(ep[i] - ep[i - 1]) == 1)
            t2 = 1;

        if(abs(ep[i] - ep[i - 1]) == m)
            t2 = 2;

        if(t == t2)
            k++;
        else
        {
            if(t)
                ans = __gcd(ans, k);

            k = 1;
            t = t2;
        }
    }

    if(t)
        ans = __gcd(ans, k);

    if(ans == 1)
    {
        cout << -1;
        return 0;
    }

    for(int i = 2; i <= ans; i++)
        if(ans % i == 0)
            cout << i << ' ';
}