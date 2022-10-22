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

    int t;
    cin >> t;

    while(t--)
    {
        int n, x;
        cin >> n >> x;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i]--;
        }

        sort(a.begin(), a.end());

        vector <li> ps(n + 1);

        for(int i = 0; i < n; i++)
            ps[i + 1] = ps[i] + a[i];

        li ans = 0;

        for(int i = n; i >= 1; i--)
            ans += max(0ll, x - ps[i]) / i;

        cout << ans << "\n";
    }
}