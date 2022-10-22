#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        string a, b;
        cin >> a >> b;

        x = min(x, 2 * y);

        vector <int> v;

        for(int i = 0; i < n; i++)
            if(a[i] != b[i])
                v.pb(i);

        if(v.size() % 2)
        {
            cout << "-1\n";
            continue;
        }

        if(v.size() == 2 && v[0] + 1 == v[1])
            cout << x << "\n";
        else cout << y * v.size() / 2 << "\n";
    }
}