#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[200005], b[200005], c[200005], used[200005];
vector <int> v[200005], u;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        v[a[i]].push_back(b[i]);
    }

    for(int i = 0; i < n; i++)
    {
        if(b[i] == v[a[i]][v[a[i]].size() - 1])
            u.push_back(i);
    }

    int q;
    cin >> q;

    while(q--)
    {
        int x;
        cin >> x;

        for(int i = 0; i < x; i++)
            {
                cin >> c[i];
                used[c[i]] = 1;
            }

        int y = u.size() - 1;

        while(y >= 0 && used[a[u[y]]] == 1)
            y--;

        if(y < 0)
        {
            cout << "0 0\n";
        }
        else
        {
            int w = a[u[y]];

            y--;
            while(y >= 0 && used[a[u[y]]] == 1)
                y--;

            int z = 0;

            if(y >= 0)
                z = b[u[y]];

            int L = -1;
            int R = v[w].size() - 1;

            while(R - L > 1)
            {
                int M = (L + R) / 2;

                if(v[w][M] > z)
                    R = M;
                else L = M;
            }

            cout << w << ' ' << v[w][R] << "\n";
        }

        for(int i = 0; i < x; i++)
            used[c[i]] = 0;
    }
}