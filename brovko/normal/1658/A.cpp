#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        string s;
        cin >> s;

        vector <int> v;

        for(int i = 0; i < n; i++)
            if(s[i] == '0')
                v.pb(i);

        int ans = 0;

        for(int i = 1; i < v.size(); i++)
            ans += max(0ll, 3 - v[i] + v[i - 1]);

        cout << ans << "\n";
    }
}