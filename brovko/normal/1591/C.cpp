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

    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector <int> pos, neg;

        for(int i = 0; i < n; i++)
        {
            if(a[i] > 0)
                pos.pb(a[i]);
            else neg.pb(a[i]);
        }

        sort(pos.rbegin(), pos.rend());
        sort(neg.begin(), neg.end());

        vector <int> v;

        for(int i = 0; i < pos.size(); i += k)
            v.pb(pos[i]);

        for(int i = 0; i < neg.size(); i += k)
            v.pb(-neg[i]);

        sort(v.begin(), v.end());

        int ans = 0;

        for(int i = 0; i < v.size(); i++)
            ans += 2 * v[i];

        ans -= v.back();

        cout << ans << "\n";
    }
}