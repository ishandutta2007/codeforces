#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[200005], b[200005], c[200005], d[200005], k, u;
map <int, vector <int> > q;
map <int, int> ind, used;
vector <pair <int, int> > v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        used[a[i]] = 1;

    for(int i = 0; i < m; i++)
        cin >> b[i];

    for(int i = 0; i < n; i++)
        q[a[i]].push_back(i);

    for(int i = 0; i < m; i++)
        v.push_back({b[i], i});

    sort(v.begin(), v.end());

    for(auto to:v)
    {
        int x = to.first;
        int y = to.second;
        int z = 0;

        while(used[x] == 0 && x > 1)
            {
                z++;
                x = (x + 1) / 2;
            }

        if(used[x])
        {
            k++;
            u += z;

            c[y] = z;
            d[q[x][ind[x]]] = y + 1;

            ind[x]++;

            if(ind[x] >= q[x].size())
                used[x] = 0;
        }
    }

    cout << k << ' ' << u << "\n";

    for(int i = 0; i < m; i++)
        cout << c[i] << ' ';

    cout << "\n";

    for(int i = 0; i < n; i++)
        cout << d[i] << ' ';
}