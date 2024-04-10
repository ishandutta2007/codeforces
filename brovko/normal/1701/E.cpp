#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define f first
#define s second

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
        int n, m;
        cin >> n >> m;

        string s, t;
        cin >> s >> t;

        int ans = 1e9;

        int lcp = 0;

        while(lcp < m && s[lcp] == t[lcp])
            lcp++;

        vector <int> pref(n + 1), suf(n + 1);

        int x = 0;

        for(int i = 0; i < n; i++)
        {
            if(x < m && s[i] == t[x])
                x++;

            pref[i] = x;
        }

        x = m - 1;

        for(int i = n - 1; i >= 0; i--)
        {
            if(x >= 0 && s[i] == t[x])
                x--;

            suf[i] = x;
        }

        if(suf[0] != -1)
        {
            cout << "-1\n";
            continue;
        }

        int LCP[n + 1][m + 1] = {};

        for(int i = n - 1; i >= 0; i--)
            for(int j = m - 1; j >= 0; j--)
                LCP[i][j] = (s[i] == t[j] ? 1 + LCP[i + 1][j + 1] : 0);

        ans = n - lcp;
        suf[n] = m - 1;

        for(int i = 1; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                int d = LCP[i][j];

                if(pref[i - 1] >= j && suf[i + d] < j + d)
                    ans = min(ans, n - d + 1 + i - j);
            }

        cout << ans << "\n";
    }
}