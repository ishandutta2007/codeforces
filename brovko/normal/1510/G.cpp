#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, k, p[105], d[105], Max, used[105], c;
vector <int> g[105], u, ans;

void dfs(int v)
{
//    cout << v << endl;

    for(auto to:g[v])
        if(used[to] == 0 && c < k)
        {
            c++;
            ans.pb(to);

            dfs(to);

            ans.pb(v);
        }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        for(int i = 0; i < n; i++)
        {
            used[i] = 0;
            p[i] = 0;
            d[i] = 0;
            g[i].clear();
        }

        c = Max = 0;

        u.clear();
        ans.clear();

        for(int i = 1; i < n; i++)
        {
            cin >> p[i];
            p[i]--;

            g[p[i]].pb(i);
            d[i] = d[p[i]] + 1;

            if(d[i] > d[Max])
                Max = i;
        }

        int x = Max;

        while(x != 0)
        {
            used[x] = 1;
            u.pb(x);
            c++;

            x = p[x];
        }

        u.pb(0);
        c++;

        reverse(u.begin(), u.end());

        used[0] = 1;

        for(int i = 0; i < n; i++)
            if(used[i])
            {
                ans.pb(i);
                dfs(i);
            }

//        cout << c << ' ' << k << endl;

        if(c == k)
        {
            cout << ans.size() - 1 << "\n";

            for(auto x:ans)
                cout << x + 1 << ' ';
                
            cout << "\n";
        }
        else
        {
            cout << k - 1 << "\n";

            for(int i = 0; i < k; i++)
                cout << u[i] + 1 << ' ';

            cout << "\n";
        }
    }
}

/*

1
6 6
1 1 2 2 3

*/