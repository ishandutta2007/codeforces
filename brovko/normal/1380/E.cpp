#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[200005], p[200005];
vector <int> v[200005];

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

    p[x] = y;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            v[a[i]].push_back(i);
        }

    for(int i = 1; i <= m; i++)
        p[i] = i;

    int ans = n - 1;

    for(int i = 0; i < n - 1; i++)
        if(a[i] == a[i + 1])
            ans--;

    cout << ans << "\n";

    for(int i = 0; i < m - 1; i++)
    {
        int x, y;

        cin >> x >> y;

        x = get(x);
        y = get(y);

        if(v[x].size() > v[y].size())
            swap(x, y);

        //cout << x << ' ' << y << "\n";

        for(auto to:v[x])
        {
            v[y].push_back(to);

            if(to > 0 && get(a[to - 1]) == y)
                ans--;

            if(to < n - 1 && get(a[to + 1]) == y)
                ans--;
        }

        unite(x, y);
        cout << ans << "\n";
    }
}