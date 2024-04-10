#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;
const int N = 1005;

int p[N], siz[N];

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

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector <int> d(n);

        for(int i = 0; i < n; i++)
            cin >> d[i];

        vector <pair <int, int> > v;

        for(int i = 0; i < n; i++)
        {
            v.pb({d[i], i});
        }

        sort(v.rbegin(), v.rend());

        for(int i = 0; i < n; i++)
        {
            p[i] = i;
            siz[i] = 1;
        }

        vector <int> used(n);

        for(auto p:v)
        {
            int i = p.s;

            if(used[i] == 0)
            {
                used[i] = 1;

                for(int j = 0; j < d[i]; j++)
                {
                    cout << "? " << i + 1 << endl;

                    int x;
                    cin >> x;
                    x--;

                    unite(x, i);

                    if(used[x])
                        break;

                    used[x] = 1;
                }
            }
        }

        cout << "! ";

        for(int i = 0; i < n; i++)
            cout << get(i) + 1 << ' ';

        cout << endl;
    }
}