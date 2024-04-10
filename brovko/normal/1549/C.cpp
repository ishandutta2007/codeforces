#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, a[200005], ans;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        if(u < v)
        {
            a[u]++;

            if(a[u] == 1)
                ans++;
        }
        else
        {
            a[v]++;

            if(a[v] == 1)
                ans++;
        }
    }

    int q;
    cin >> q;

    while(q--)
    {
        int t, u, v;
        cin >> t;

        if(t == 3)
            cout << n - ans << "\n";
        else if(t == 1)
        {
            cin >> u >> v;

            u--;
            v--;

            if(u > v)
                swap(u, v);

            a[u]++;

            if(a[u] == 1)
                ans++;
        }
        else
        {
            cin >> u >> v;

            u--;
            v--;

            if(u > v)
                swap(u, v);

            a[u]--;

            if(a[u] == 0)
                ans--;
        }
    }
}