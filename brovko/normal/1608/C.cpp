#include <bits/stdc++.h>
#define li long long
#define pb push_back
#define x first
#define y second

using namespace std;

int t, n, a[100005], b[100005], dpx[100005], dpy[100005], used[100005], Maxy[100005];
vector <int> g[100005];

void dfs(int v)
{
    used[v] = 1;
    dpx[v] = v;
    dpy[v] = v;

    for(auto to:g[v])
    {
        if(used[to] == 0)
            dfs(to);

        if(a[dpx[to]] > a[dpx[v]])
            dpx[v] = dpx[to];

        if(b[dpy[to]] > b[dpy[v]])
            dpy[v] = dpy[to];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            g[i].clear();

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            cin >> b[i];

        vector <pair <int, int> > v;

        for(int i = 0; i < n; i++)
            v.pb({a[i], i});

        sort(v.begin(), v.end());

        int Max = -1;

        for(int i = 0; i < n; i++)
        {
            int j = v[i].y;

            if(b[j] > b[Max])
                Max = j;

            if(Max > -1)
                g[j].pb(Max);
        }

        vector <pair <int, int> > u;

        for(int i = 0; i < n; i++)
            u.pb({b[i], i});

        sort(u.begin(), u.end());

        Max = -1;

        for(int i = 0; i < n; i++)
        {
            int j = u[i].y;

            if(a[j] > a[Max])
                Max = j;

            if(Max > -1)
                g[j].pb(Max);
        }

        for(int i = 0; i < n; i++)
            used[i] = 0;

        for(int i = 0; i < n; i++)
            if(used[i] == 0)
                dfs(i);

//        for(auto to:g[1])
//            cout << to << ' ';
//
//        cout << endl;
//
//        for(int i = 0; i < n; i++)
//            cout << a[dpx[i]] << ' ';
//
//        cout << endl;
//
//        for(int i = 0; i < n; i++)
//            cout << b[dpy[i]] << ' ';
//
//        cout << endl;

        Max = -1;

        for(int i = n - 1; i >= 0; i--)
        {
            int j = v[i].y;

            Maxy[j] = Max;

            if(b[j] > b[Max])
                Max = j;
        }

        for(int i = 0; i < n; i++)
        {
            if(Maxy[dpx[i]] == -1 || b[dpy[i]] >= b[Maxy[dpx[i]]])
                cout << 1;
            else cout << 0;
        }

        cout << "\n";
    }
}