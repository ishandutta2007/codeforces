#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, u[305], v[305], w[305], p[55], siz[55], k[1000005], b[1000005];

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

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];

        u[i]--;
        v[i]--;
    }

    vector <int> pos;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < i; j++)
            if(w[i] != w[j])
                pos.pb((w[i] + w[j]) / 2);

    for(int i = 0; i < m; i++)
        pos.pb(w[i]);

    pos.pb(-3);

    sort(pos.begin(), pos.end());

    auto it = unique(pos.begin(), pos.end());

    pos.erase(it, pos.end());

    vector <pair <int, int> > V;

    for(int i = 0; i < m; i++)
    {
        V.pb({w[i], i});
    }

    for(int i = 0; i < pos.size(); i++)
    {
        int x = pos[i] + 1;

        for(int j = 0; j < m; j++)
            V[j].x = abs(x - w[V[j].y]);

        sort(V.begin(), V.end());

        int y = 0, z = 0;

        for(int j = 0; j < n; j++)
        {
            p[j] = j;
            siz[j] = 1;
        }

        for(auto e:V)
        {

            if(get(u[e.y]) != get(v[e.y]))
            {
                unite(u[e.y], v[e.y]);

                if(x >= w[e.y])
                {
                    y++;
                    z -= w[e.y];
                }
                else
                {
                    y--;
                    z += w[e.y];
                }
            }
        }

        k[i] = y;
        b[i] = z;
    }

    int P, K, A, B, C;
    cin >> P >> K >> A >> B >> C;

    int Q;

    vector <int> queries;

    while(P--)
    {
        cin >> Q;
        queries.pb(Q);
    }

    for(int i = P + 1; i <= K; i++)
    {
        Q = (Q * 1ll * A + B) % C;
        queries.pb(Q);
    }

    long long ans = 0;

    for(int i = 0; i < K; i++)
    {
        int j = lower_bound(pos.begin(), pos.end(), queries[i]) - pos.begin();
        j--;

        ans ^= k[j] * 1ll * queries[i] + b[j];
    }

    cout << ans;
}