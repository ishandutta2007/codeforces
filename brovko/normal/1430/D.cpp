#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, c[200005];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> s;

        c[0] = 1;
        int k = 1;

        vector <int> v;

        for(int i = 1; i < n; i++)
        {
            if(s[i] == s[i - 1])
            {
                c[i] = k;
                v.pb(k);
            }
            else
            {
                k++;
                c[i] = k;
            }
        }

        int ans = 0, d = 0, x = 0;

        while(d < k)
        {
            ans++;

            while(x < v.size() && v[x] <= d)
                x++;

            if(x < v.size())
                x++;
            else d++;

            d++;
        }

        cout << ans << "\n";
    }
}