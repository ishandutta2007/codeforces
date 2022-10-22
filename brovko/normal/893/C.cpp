#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[100005], p[100005], Min[100005], siz[100005], used[100005];

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
    if(siz[x] > siz[y])
        swap(x, y);

    if(x == y)
        return;

    p[x] = y;
    siz[y] += siz[x];
    Min[y] = min(Min[x], Min[y]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        p[i] = i;
        siz[i] = 1;
        Min[i] = a[i];
    }

    for(int i=0; i<m; i++)
    {
        int x, y;
        cin >> x >> y;

        x--;
        y--;
        unite(x, y);
    }

    int ans = 0;
    for(int i=0; i<n; i++)
        if(used[get(i)] == 0)
    {
        used[get(i)] = 1;
        ans += Min[get(i)];
    }

    cout << ans;
}