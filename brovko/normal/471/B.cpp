#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[2005], k[2005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector <pair <int, int> > v, u;

    for(int i = 0; i < n; i++)
    {
        k[a[i]]++;
        v.pb({a[i], i});
        u.pb({a[i], -i});
    }

    int f = 0;

    for(int i = 0; i < 2005; i++)
        f += max(k[i] - 1, 0ll);

    if(f < 2)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    sort(v.begin(), v.end());

    for(auto x:v)
        cout << x.y + 1 << ' ';

    cout << "\n";

    sort(u.begin(), u.end());

    for(auto x:u)
        cout << -x.y + 1 << ' ';

    cout << "\n";

    int x = 1;

    while(v[x].x != v[x - 1].x)
        x++;

    swap(v[x], v[x - 1]);

    for(auto x:v)
        cout << x.y + 1 << ' ';

    cout << "\n";
}