#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m1, m2, p[1005][2], siz[1005][2];

int get(int x, int i)
{
    if(x == p[x][i])
        return x;

    p[x][i] = get(p[x][i], i);

    return p[x][i];
}

void unite(int x, int y, int i)
{
    x = get(x, i);
    y = get(y, i);

    if(x == y)
        return;

    if(siz[x][i] > siz[y][i])
        swap(x, y);

    p[x][i] = y;
    siz[y][i] += siz[x][i];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m1 >> m2;

    for(int i = 0; i < n; i++)
    {
        p[i][0] = i;
        p[i][1] = i;

        siz[i][0] = 1;
        siz[i][1] = 1;
    }

    for(int i = 0; i < m1; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        unite(u, v, 0);
    }

    for(int i = 0; i < m2; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        unite(u, v, 1);
    }

    vector <pair <int, int> > ans;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
        {
            if(get(i, 0) != get(j, 0) && get(i, 1) != get(j, 1))
            {
                ans.pb({i, j});
                unite(i, j, 0);
                unite(i, j, 1);
            }
        }

    cout << ans.size() << "\n";

    for(auto to:ans)
        cout << to.x + 1 << ' ' << to.y + 1 << "\n";
}