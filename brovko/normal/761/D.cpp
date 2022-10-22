#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, l, r, a[100005], p[100005], c[100005], b[100005];
vector <pair <int, int> > v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> r;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> p[i];

    for(int i = 0; i < n; i++)
        v.push_back({p[i], i});

    sort(v.begin(), v.end());

    int x = v[0].second;

    b[x] = l;
    c[x] = l - a[x];

    for(int i = 1; i < n; i++)
    {
        int y = v[i].second;

        b[y] = max(l, a[y] + c[x] + 1);
        c[y] = b[y] - a[y];

        x = y;
    }

    for(int i = 0; i < n; i++)
    {
        if(b[i] > r)
        {
            cout << -1;
            return 0;
        }
    }

    for(int i = 0; i < n; i++)
        cout << b[i] << ' ';
}