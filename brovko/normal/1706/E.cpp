#include <bits/stdc++.h>
//#define int long long
#define pb push_back

using li = long long;

using namespace std;

int used[100005], p[100005], siz[100005], st[100005][20], mx2[100005];

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

int get(int L, int R)
{
    int d = R - L;

    return max(st[L][mx2[d]], st[R - (1 << mx2[d])][mx2[d]]);
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
        int n, m, q;
        cin >> n >> m >> q;

        vector <int> u(m), v(m);

        for(int i = 0; i < m; i++)
        {
            cin >> u[i] >> v[i];
            u[i]--;
            v[i]--;
        }

        vector <int> L(n, -1), R(n, m), M(n);

        vector <int> Q[m];

        while(true)
        {
            bool F = 0;

            for(int i = 0; i < n; i++)
            {
                p[i] = i;
                siz[i] = 1;
            }

            for(int i = 0; i < m; i++)
                Q[i].clear();

            for(int i = 1; i < n; i++)
            {
                if(R[i] - L[i] > 1)
                {
                    M[i] = (L[i] + R[i]) / 2;
                    F = 1;

                    Q[M[i]].pb(i);
                }
            }

            if(!F)
                break;

            for(int i = 0; i < m; i++)
            {
                unite(u[i], v[i]);

                for(auto x:Q[i])
                    if(get(x) == get(x - 1))
                        R[x] = i;
                    else L[x] = i;
            }
        }

        for(int i = 1; i < n; i++)
            st[i][0] = R[i];

        for(int j = 1; j < 20; j++)
            for(int i = 1; i + (1 << j) <= n; i++)
                st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);

        for(int i = 2; i <= n; i++)
            mx2[i] = mx2[i / 2] + 1;

//        for(int i = 1; i < n; i++)
//            cout << R[i] + 1 << ' ';
//
//        cout << "\n";
//
//        for(int i = 1; i < n - 1; i++)
//            cout << st[i][1] + 1 << ' ';
//
//        cout << "\n";

        while(q--)
        {
            int l, r;
            cin >> l >> r;

            if(l == r)
                cout << "0 ";
            else cout << get(l, r) + 1 << ' ';
        }

        cout << "\n";
    }
}