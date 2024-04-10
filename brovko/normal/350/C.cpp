#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> x(n), y(n);

    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    vector <pair <li, int> > v;

    for(int i = 0; i < n; i++)
    {
        v.pb({abs(x[i]) + 0ll + abs(y[i]), i});
    }

    sort(v.begin(), v.end());

    int k = 6 * n;

    for(int i = 0; i < n; i++)
        if(x[i] == 0 || y[i] == 0)
            k -= 2;

    cout << k << "\n";

    for(auto p:v)
    {
        int i = p.y;

        if(x[i] > 0)
            cout << 1 << ' ' << x[i] << ' ' << 'R' << "\n";

        if(x[i] < 0)
            cout << 1 << ' ' << -x[i] << ' ' << 'L' << "\n";

        if(y[i] > 0)
            cout << 1 << ' ' << y[i] << ' ' << 'U' << "\n";

        if(y[i] < 0)
            cout << 1 << ' ' << -y[i] << ' ' << 'D' << "\n";

        cout << 2 << "\n";

        if(x[i] > 0)
            cout << 1 << ' ' << x[i] << ' ' << 'L' << "\n";

        if(x[i] < 0)
            cout << 1 << ' ' << -x[i] << ' ' << 'R' << "\n";

        if(y[i] > 0)
            cout << 1 << ' ' << y[i] << ' ' << 'D' << "\n";

        if(y[i] < 0)
            cout << 1 << ' ' << -y[i] << ' ' << 'U' << "\n";

        cout << 3 << "\n";
    }
}