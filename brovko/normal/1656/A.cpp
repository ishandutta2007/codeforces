#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[100005];

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

        vector <pair <int, int> > v;

        for(int i = 0; i < n; i++)
            v.pb({a[i], i});
            
        sort(v.begin(), v.end());

        cout << v[0].y + 1 << ' ' << v.back().y + 1 << "\n";
    }
}