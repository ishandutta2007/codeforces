#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, m, Min[200005], Max[200005], ps[200005], mx[200005], mn[200005];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m >> s;

        Min[n] = 0;
        Max[n] = 0;

        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '-')
            {
                Min[i] = min(0ll, Min[i + 1] - 1);
                Max[i] = max(0ll, Max[i + 1] - 1);
            }
            else
            {
                Min[i] = min(0ll, Min[i + 1] + 1);
                Max[i] = max(0ll, Max[i + 1] + 1);
            }
        }

        ps[0] = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '-')
                ps[i + 1] = ps[i] - 1;
            else ps[i + 1] = ps[i] + 1;
        }

        mx[0] = 0;
        mn[0] = 0;

        int y = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '-')
            {
                y--;
                mn[i + 1] = min(mn[i], y);
                mx[i + 1] = max(mx[i], y);
            }
            else
            {
                y++;
                mn[i + 1] = min(mn[i], y);
                mx[i + 1] = max(mx[i], y);
            }
        }

        while(m--)
        {
            int l, r;
            cin >> l >> r;

            l--;
            r--;

            int x = ps[l];
            cout << max(mx[l], x + Max[r + 1]) - min(mn[l], x + Min[r + 1]) + 1 << "\n";
        }
    }
}