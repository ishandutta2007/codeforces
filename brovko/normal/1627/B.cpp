#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, m;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        vector <int> v;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                v.pb(max(i, n - 1 - i) + max(j, m - 1 - j));

        sort(v.begin(), v.end());

        for(auto x:v)
            cout << x << ' ';

        cout << "\n";
    }
}