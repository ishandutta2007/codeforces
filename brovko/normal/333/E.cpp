#include <bits/stdc++.h>
//#define int long long
#define ld double
#define f first
#define s second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector <int> x(n), y(n);

    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    vector <pair <ld, pair <int, int> > > v;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
            v.pb({sqrt((ld)(x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])), {i, j}});

    sort(v.rbegin(), v.rend());

    bitset <3005> b[n];

    for(int i = 0; i < v.size(); i++)
    {
        int x = v[i].s.f;
        int y = v[i].s.s;

        b[x][y] = 1;
        b[y][x] = 1;

        if((b[x] & b[y]).count())
        {
            cout << setprecision(20) << v[i].f / 2;
            return 0;
        }
    }
}