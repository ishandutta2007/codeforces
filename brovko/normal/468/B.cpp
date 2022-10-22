#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, A, B, a[100005], p[100005], siz[100005], used[100005], c[100005];
map <int, int> pos;
vector <int> g[100005];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
        if(used[to] == 0)
        {
            c[to] = c[v];
            dfs(to);
        }
}

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

    cin >> n >> A >> B;

    for(int i = 0; i < n; i++)
        cin >> a[i];

//    if(n % 2)
//    {
//        cout << "NO";
//        return 0;
//    }

    for(int i = 0; i < n; i++)
    {
        p[i] = i;
        siz[i] = 1;
        pos[a[i]] = i + 1;
    }

    for(int i = 0; i < n; i++)
    {
        if(pos[A - a[i]] && a[i] * 2 != A)
        {
            int x = pos[A - a[i]] - 1;

            unite(i, x);
            g[i].pb(x);
        }

        if(pos[B - a[i]] && A != B && a[i] * 2 != B)
        {
            int x = pos[B - a[i]] - 1;

            unite(i, x);
            g[i].pb(x);
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(a[i] * 2 == A && used[i] == 0 && siz[get(i)] % 2)
            dfs(i);

        if(a[i] * 2 == B && used[i] == 0 && siz[get(i)] % 2)
        {
            c[i] = 1;
            dfs(i);
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(used[i] == 0 && siz[get(i)] % 2)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES\n";

//    for(int i = 0; i < n; i++)
//    {
//        for(auto to:g[i])
//            cout << to + 1 << ' ';
//
//        cout << endl;
//    }

    for(int i = 0; i < n; i++)
    {
        if(used[i] == 0 && g[i].size() == 1)
        {
            if(pos[B - a[i]] && a[i] * 2 != B)
                c[i] = 1;

            dfs(i);
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << c[i] << ' ';
        assert(used[i]);
    }
}

/*
4 6 7
2 5 3 4

*/