#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[300005], b[300005], p[300005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    int x = n - 1, y = n, F = 1;

    while(F && x >= 0)
    {
        F = 0;
        int z = x, pr = p[x];

//        cout << x << ' ' << y << endl;

        for(int i = x; i < y; i++)
            if(i + b[i] - a[i + b[i]] < x)
            {
                x = i + b[i] - a[i + b[i]];
                F = 1;
                pr = i;
            }

//        cout << x << ' ' << y << endl << endl;

        for(int i = x; i < z; i++)
            p[i + 1] = pr;

        y = z;

//        cout << "!" << endl;
    }

    if(x >= 0)
        cout << -1;
    else
    {
        vector <int> v;
        int x = -1;

        while(x < n - 1)
        {
            v.pb(x + 1);
            x = p[x + 1];
        }

        reverse(v.begin(), v.end());

        cout << v.size() << "\n";

        for(auto x:v)
            cout << x << ' ';
    }
}