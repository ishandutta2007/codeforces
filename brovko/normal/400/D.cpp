#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, k, c[505], u[100005], v[100005], w[100005], p[100005], siz[100005], ps[505], type[100005], d[505][505];

int get(int x)
{
    if(x == p[x])
        return x;

    p[x] = get(p[x]);
    return p[x];
}

void unite(int x, int y)
{
    x = get(x);
    y = get(y);

    if(x == y)
        return;

    if(siz[x] > siz[y])
        swap(x, y);

    p[x] = y;
    siz[y] += siz[x];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
    {
        p[i] = i;
        siz[i] = 1;
    }

    for(int i = 0; i < k; i++)
        cin >> c[i];

    for(int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];

        u[i]--;
        v[i]--;

        if(w[i] == 0)
            unite(u[i], v[i]);
    }

    ps[0] = 0;

    for(int i = 0; i < k; i++)
        ps[i + 1] = ps[i] + c[i];

    int x = 0;

    for(int i = 0; i < n; i++)
    {
        while(i >= ps[x])
            x++;

        type[i] = x - 1;

        if(get(i) != get(ps[x] - 1))
        {
            cout << "No";
            return 0;
        }
    }

//    for(int i = 0; i < n; i++)
//        cout << type[i] << ' ';
//
//    cout << endl;

    cout << "Yes\n";

    for(int i = 0; i < k; i++)
        for(int j = 0; j < k; j++)
            d[i][j] = 1e9;

    for(int i = 0; i < k; i++)
        d[i][i] = 0;

    for(int i = 0; i < m; i++)
    {
        u[i] = type[u[i]];
        v[i] = type[v[i]];

        d[u[i]][v[i]] = min(d[u[i]][v[i]], w[i]);
        swap(u[i], v[i]);
        d[u[i]][v[i]] = min(d[u[i]][v[i]], w[i]);
    }

    for(int z = 0; z < k; z++)
        for(int i = 0; i < k; i++)
            for(int j = 0; j < k; j++)
                d[i][j] = min(d[i][j], d[i][z] + d[z][j]);

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            if(d[i][j] > 1e8)
                cout << -1 << ' ';
            else cout << d[i][j] << ' ';
        }

        cout << "\n";
    }
}