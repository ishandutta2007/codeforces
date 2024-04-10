#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int t, n, a[200005], p[200005], siz[200005], used[200005], Min[200005];

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

    p[x] = y;
    siz[y] += siz[x];

    Min[y] = min(Min[y], Min[x]);
}

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
            cin >> a[i];

        for(int i = 0; i <= n; i++)
        {
            p[i] = i;
            siz[i] = 1;
            used[i] = 0;
            Min[i] = i;
        }

        int x = 1;

        for(int i = 0; i < n; i++)
        {
            if(used[a[i]] == 0)
            {
                cout << a[i] << ' ';
                used[a[i]] = 1;
            }
            else
            {
                while(used[x])
                    x++;

                cout << x << ' ';
                used[x] = 1;
            }
        }

        cout << "\n";

        for(int i = 0; i <= n; i++)
            used[i] = 0;

        for(int i = 0; i < n; i++)
        {
            int y = a[i];

            if(used[y])
                y = Min[get(y)] - 1;

            used[y] = 1;
            cout << y << ' ';

            if(y > 1 && used[y - 1] == 1)
                unite(y, y - 1);

            if(y < n && used[y + 1] == 1)
                unite(y, y + 1);
        }

        cout << "\n";
    }
}