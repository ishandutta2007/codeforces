#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, m, l[200005], r[200005], a[200005], ans[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> l[i] >> r[i];

    for(int i = 0; i < m; i++)
        cin >> a[i];

    vector <pair <int, int> > v;

    for(int i = 0; i < m; i++)
        v.pb(mp(a[i], i));

    sort(v.begin(), v.end());

    vector <pair <int, int> > u;

    for(int i = 1; i < n; i++)
        u.pb(mp(l[i] - r[i - 1], i));

    sort(u.begin(), u.end());

    set <pair <int, int> > q;

    int x = 0;

//    for(auto p:v)
//        cout << p.x << ' ';
//
//    cout << endl;
//
//    for(int i = 0; i < n - 1; i++)
//        cout << u[i].x << ' ';
//
//    cout << endl;

    for(int i = 0; i < m; i++)
    {
        while(x < n - 1 && u[x].x <= v[i].x)
        {
            q.insert({r[u[x].y] - l[u[x].y - 1], u[x].y});
            x++;
        }

        if(q.empty())
            continue;

        pair <int, int> p = (*q.begin());

        if(p.x < v[i].x)
        {
//            cout << "! " << i << ' ' << x << endl;
            cout << "No";
            return 0;
        }

//        cout << p.x << ' ' << p.y << endl;

        ans[p.y] = v[i].y + 1;
        q.erase(p);
    }
    
    if(x < n - 1)
    {
        cout << "No";
        return 0;
    }

    cout << "Yes\n";

    for(int i = 1; i < n; i++)
        cout << ans[i] << ' ';
}