#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int s = 0;

    for(int i = 0; i < n; i++)
        s += a[i];

    if(s > 0)
    {
        cout << "first";
        return 0;
    }

    if(s < 0)
    {
        cout << "second";
        return 0;
    }

    vector <int> v, u;

    for(int i = 0; i < n; i++)
    {
        if(a[i] > 0)
            v.pb(a[i]);
        else u.pb(-a[i]);
    }

    for(int i = 0; i < min(v.size(), u.size()); i++)
    {
        if(v[i] > u[i])
        {
            cout << "first";
            return 0;
        }

        if(v[i] < u[i])
        {
            cout << "second";
            return 0;
        }
    }

    if(a[n - 1] > 0)
        cout << "first";
    else cout << "second";
}