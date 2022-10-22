#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
const int N = 1005;

int p[N], siz[N], d[N];

int get(int x)
{
    if(x == p[x])
        return x;

    return get(p[x]);
}

int dist(int x)
{
    if(x == p[x])
        return 0;

    return (d[x] ^ dist(p[x]));
}

void unite(int x, int y, int w)
{
    if(siz[get(x)] > siz[get(y)])
        swap(x, y);

    w ^= (dist(x) ^ dist(y));

    x = get(x);
    y = get(y);

    if(x == y)
    {
        assert(w == 0);
        return;
    }

    p[x] = y;
    siz[y] += siz[x];

    d[x] = w;
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
        int n;
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            p[i] = i;
            siz[i] = 1;
            d[i] = 0;
        }

        int a[n][n];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> a[i][j];

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
            {
                if(a[i][j] == a[j][i])
                    continue;

                int w = 0;

                if(a[i][j] > a[j][i])
                    w = 1;

                if(get(i) != get(j) || (dist(i) ^ dist(j)) == w)
                {
                    unite(i, j, w);

                    if(w)
                        swap(a[i][j], a[j][i]);
                }
                else if(w == 0)
                    swap(a[i][j], a[j][i]);
            }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout << a[i][j] << ' ';

            cout << "\n";
        }
    }
}