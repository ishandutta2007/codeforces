#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int T, n, m, a[200005], b[200005], ma[200005], mb[200005];
string s, t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    T = 1;

    while(T--)
    {
        cin >> n >> m >> s >> t;

        a[0] = (s[0] == t[0]);

        for(int i = 1; i < n; i++)
        {
            a[i] = a[i - 1];

            if(s[i] == t[a[i]])
                a[i]++;
        }

        b[n - 1] = m + (s[n - 1] != t[m - 1]);

        for(int i = n - 2; i >= 0; i--)
        {
            b[i] = b[i + 1];

            if(s[i] == t[b[i] - 2])
                b[i]--;
        }

//        for(int i = 0; i < n; i++)
//            cout << b[i] << ' ';
//
//        cout << endl;

        for(int i = 0; i < m + 3; i++)
        {
            ma[i] = 1e9;
            mb[i] = -1e9;
        }

        ma[0] = -1;
        mb[n + 2] = n;

        for(int i = 0; i < n; i++)
            ma[a[i]] = min(ma[a[i]], i);

        for(int i = 0; i < n; i++)
            mb[b[i]] = max(mb[b[i]], i);

        int ans = 0;

        for(int i = 1; i < m; i++)
            ans = max(ans, mb[i + 1] - ma[i]);

        cout << ans << "\n";
    }
}