#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, x[200005], y[200005], t[2000005];
map <int, int> k, q;

int get(int v, int l, int r, int L, int R)
{
    if(L >= R)
        return 1e9;

    if(L == l && R == r)
        return t[v];

    int m = (l + r) / 2;

    return min(get(2 * v + 1, l, m, L, min(m, R)), get(2 * v + 2, m, r, max(L, m), R));
}

void update(int v, int l, int r, int pos, int val)
{
    if(r - l == 1)
    {
        t[v] = val;
        return;
    }

    int m = (l + r) / 2;

    if(pos < m)
        update(2 * v + 1, l, m, pos, val);
    else update(2 * v + 2, m, r, pos, val);

    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];

        k[y[i] - x[i]]++;
    }

    vector <pair <int, int> > v;

    for(int i = 0; i < n; i++)
    {
        int w;
        cin >> w;

        if(q[w] > k[w])
        {
            cout << "NO";
            return 0;
        }

        int x, y;

        if(w > 0)
        {
            x = 0;
            y = w;
        }
        else
        {
            x = -w;
            y = 0;
        }

        x += q[w];
        y += q[w];

        if(get(0, 0, 200001, 0, x) < y + 1)
        {
            cout << "NO";
            return 0;
        }

        update(0, 0, 200001, x, y + 1);

        v.pb({x, y});
        q[w]++;

        if(q[w] > k[w])
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES\n";

    for(auto to:v)
        cout << to.x << ' ' << to.y << "\n";
}