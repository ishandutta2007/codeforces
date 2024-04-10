#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, u1[100005], u2[100005];
vector <int> g[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            g[i].clear();

            int k;
            cin >> k;

            while(k--)
            {
                int x;
                cin >> x;

                x--;

                g[i].pb(x);
            }
        }

        for(int i = 0; i < n; i++)
        {
            u1[i] = 0;
            u2[i] = 0;
        }

        for(int i = 0; i < n; i++)
        {
            int x = 0;

            while(x < g[i].size() && u2[g[i][x]] == 1)
                x++;

            if(x < g[i].size())
            {
                u1[i] = 1;
                u2[g[i][x]] = 1;
            }
        }

        int m1 = 0, m2 = 0;

        while(m1 < n && u1[m1] == 1)
            m1++;

        while(m2 < n && u2[m2] == 1)
            m2++;

        if(m1 < n && m2 < n)
            cout << "IMPROVE\n" << m1 + 1 << ' ' << m2 + 1 << "\n";
        else cout << "OPTIMAL\n";
    }
}