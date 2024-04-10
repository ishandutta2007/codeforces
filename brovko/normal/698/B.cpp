#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int n, a[200005], p[200005];

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

    if(a[x] == x)
        p[y] = x;

    else p[x] = y;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    for(int i = 0; i < n; i++)
        p[i] = i;

    for(int i = 0; i < n; i++)
        unite(i, a[i]);

    int x = get(0);

    for(int i = 0; i < n; i++)
    {
        if(a[get(i)] == get(i))
            x = get(i);
    }

    int ans = 0;

    if(a[x] != x)
    {
        a[x] = x;
        ans++;
    }

    for(int i = 0; i < n; i++)
    {
        if(i == get(i) && a[i] != x)
        {
            a[i] = x;
            ans++;
        }
    }

    cout << ans << "\n";

    for(int i = 0; i < n; i++)
        cout << a[i] + 1 << ' ';
}