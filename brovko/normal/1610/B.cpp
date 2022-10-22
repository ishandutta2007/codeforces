#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[200005];

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
            cin >> a[i];

        int x = 0;

        while(x < n && a[x] == a[n - 1 - x])
            x++;

        if(x == n)
        {
            cout << "YES\n";
            continue;
        }

        vector <int> v, u;

        for(int i = 0; i < n; i++)
        {
            if(a[i] != a[x])
                v.pb(a[i]);

            if(a[i] != a[n - 1 - x])
                u.pb(a[i]);
        }

        int F = 1;

        for(int i = 0; i < v.size(); i++)
            if(v[i] != v[(int)v.size() - 1 - i])
                F = 0;

        if(F)
        {
            cout << "YES\n";
            continue;
        }

        swap(v, u);
        F = 1;

        for(int i = 0; i < v.size(); i++)
            if(v[i] != v[(int)v.size() - 1 - i])
                F = 0;

        if(F)
            cout << "YES\n";
        else cout << "NO\n";
    }
}