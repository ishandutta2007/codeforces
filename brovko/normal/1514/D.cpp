#include <bits/stdc++.h>
//#define int long long
#define x first
#define y second

using namespace std;

int n, q, a[300005], l[300005], r[300005], t[300005], k[300005][35], c[300005];
vector <pair <int, int> > v[300005], u[300005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    mt19937 rnd(time(NULL));

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < q; i++)
    {
        cin >> l[i] >> r[i];

        l[i]--;
        r[i]--;

        map <int, int> m;

        for(int j = 0; j < 30; j++)
        {
            m[a[rnd() % (r[i] - l[i] + 1) + l[i]]]--;
        }

        for(auto to:m)
            v[i].push_back({to.y, to.x});

        sort(v[i].begin(), v[i].end());

        for(int j = 0; j < 30; j++)
            v[i].push_back({0, 0});

        u[r[i] + 1].push_back({i, 1});
        u[l[i]].push_back({i, -1});
    }

    for(int i = 0; i <= n; i++)
    {
        for(auto to:u[i])
        {
            for(int j = 0; j < 30; j++)
                k[to.x][j] += c[v[to.x][j].y] * to.y;
        }

        c[a[i]]++;
    }

    for(int i = 0; i < q; i++)
    {
        int Max = 0;

        for(int j = 0; j < 30; j++)
            Max = max(Max, k[i][j]);

        cout << max(1, 2 * Max - r[i] + l[i] - 2 + 1) << "\n";
    }
}