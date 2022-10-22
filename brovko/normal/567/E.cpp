#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, m, s, t, a[100005], b[100005], l[100005], used[100005], d[100005], d2[100005], pr[100005], siz[100005], p[100005], u[100005], ans[100005], F[100005];
vector <int> g[100005], gr[100005];
vector <int> g2[100005];

int get(int x)
{
    if(x == pr[x])
        return x;

    pr[x] = get(pr[x]);
    return pr[x];
}

void unite(int x, int y)
{
    x = get(x);
    y = get(y);

    if(x == y)
        return;

//    if(siz[x] > siz[y])
//        swap(x, y);

    pr[x] = y;
    siz[y] += siz[x];
}

void dfs(int v)
{
    u[v] = 1;

    for(auto to:g2[v])
    {
        if(to == p[v])
        {
            F[v]++;

            if(F[v] > 1)
                unite(v, to);
        }

        if(to != p[v] && u[to] == 1)
        {
            int x = v;

            while(get(x) != get(to))
            {
//                cout << x + 1 << ' ' << p[x] + 1 << ' ' << to + 1 << endl;

                unite(x, p[x]);
                x = get(x);
            }
        }

        if(u[to] == 0)
        {
            p[to] = v;
            dfs(to);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s >> t;

    s--;
    t--;

    for(int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i] >> l[i];

        a[i]--;
        b[i]--;

        g[a[i]].pb(i);
        gr[b[i]].pb(i);
    }

    set <pair <int, int> > q;

    for(int i = 0; i < n; i++)
    {
        if(i == s)
            d[i] = 0;
        else d[i] = 1e18;

        q.insert({d[i], i});
    }

    while(!q.empty())
    {
        pair <int, int> p = *(q.begin());

        q.erase(p);
        used[p.y] = 1;

        for(auto e:g[p.y])
        {
            int to = b[e];

            if(used[to] == 0 && d[p.y] + l[e] < d[to])
            {
                q.erase({d[to], to});
                d[to] = min(d[to], d[p.y] + l[e]);
                q.insert({d[to], to});
            }
        }
    }



    for(int i = 0; i < n; i++)
    {
        if(i == t)
            d2[i] = 0;
        else d2[i] = 1e18;

        q.insert({d2[i], i});
    }

    for(int i = 0; i < n; i++)
        used[i] = 0;

    while(!q.empty())
    {
        pair <int, int> p = *(q.begin());

        q.erase(p);
        used[p.y] = 1;

        for(auto e:gr[p.y])
        {
            int to = a[e];

            if(used[to] == 0 && d2[p.y] + l[e] < d2[to])
            {
                q.erase({d2[to], to});
                d2[to] = min(d2[to], d2[p.y] + l[e]);
                q.insert({d2[to], to});
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        if(d[a[i]] < 1e15 && d[a[i]] + l[i] + d2[b[i]] == d[t])
        {
            g2[a[i]].pb(b[i]);
            g2[b[i]].pb(a[i]);
        }
    }

    for(int i = 0; i < n; i++)
    {
        p[i] = i;
        pr[i] = i;
        siz[i] = 1;
    }

    for(int i = 0; i < n; i++)
        if(u[i] == 0)
            dfs(i);

    for(int i = 0; i < m; i++)
    {
        if(d[a[i]] < 1e15 && d[a[i]] + l[i] + d2[b[i]] == d[t] && get(a[i]) != get(b[i]))
            ans[i] = 1;
    }

    for(int i = 0; i < m; i++)
    {
        if(ans[i] == 1)
            cout << "YES\n";
        else
        {
            int l2 = d[t] - d[a[i]] - d2[b[i]] - 1;

            if(l2 > 0)
                cout << "CAN " << l[i] - l2 << "\n";
            else cout << "NO\n";
        }
    }
}