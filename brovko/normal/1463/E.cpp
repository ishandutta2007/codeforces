#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

int n, k, a[300005], nxt[300005], p[300005], u1[300005], u2[300005], pr[300005];

vector <int> g[300005], ans, g1[300005];

void dfs1(int v)
{
    if(v == -1)
        return;

    if(u1[v] == 1)
    {
        cout << 0;
        exit(0);
    }

    if(u1[v] == 2)
        return;

    u1[v] = 1;

    for(auto to:g1[v])
        dfs1(to);

    u1[v] = 2;
}

void dfs2(int v)
{
    if(v == -1)
        return;

    if(u2[v] == 1)
    {
        cout << 0;
        exit(0);
    }

    if(u2[v] == 2)
        return;

    u2[v] = 1;

    for(auto to:g[v])
        dfs2(to);

    u2[v] = 2;

    ans.pb(v);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    for(int i = 0; i < n; i++)
    {
        p[i] = i;
        nxt[i] = -1;
        pr[i] = -1;
    }

    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;

        x--;
        y--;

        if(nxt[x] != -1 || pr[y] != -1)
        {
            cout << 0;
            return 0;
        }

        nxt[x] = y;
        pr[y] = x;

        g1[y].pb(x);
    }

    for(int i = 0; i < n; i++)
        if(pr[i] == -1)
        {
            int x = i;

            while(nxt[x] > -1 && p[nxt[x]] != i)
            {
                x = nxt[x];
                p[x] = i;
            }
        }

    for(int i = 0; i < n; i++)
        g1[i].pb(a[i]);

    for(int i = 0; i < n; i++)
        dfs1(i);

    for(int i = 0; i < n; i++)
        if(a[i] > -1 && p[i] != p[a[i]])
            g[p[i]].pb(p[a[i]]);

//    for(int i = 0; i < n; i++)
//    {
//        cout << i + 1 << ':';
//
//        for(auto to:g[i])
//            cout << to + 1 << ' ';
//
//        cout << endl;
//    }

    for(int i = 0; i < n; i++)
        if(p[i] == i)
            dfs2(i);

    for(auto to:ans)
    {
        int x = to;

        while(x != -1)
        {
            cout << x + 1 << ' ';
            x = nxt[x];
        }
    }
}