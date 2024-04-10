#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back

using namespace std;

int t, n, l, r;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> l >> r;

        int x = 0, y = 0;

        while(l > y)
        {
            x++;

            if(x == n)
                y++;
            else y += 2 * (n - x);
        }

        if(x == n)
            y--;
        else y -= 2 * (n - x);

        y++;

//        cout << "!" << x << ' ' << y << endl;

        vector <int> ans;

        while(x <= n && ans.size() <= r - y)
        {
            for(int i = x + 1; i <= n; i++)
            {
                ans.pb(x);
                ans.pb(i);
            }

            if(x == n)
                ans.pb(1);

            x++;
        }

        for(int i = l - y; i <= r - y; i++)
            cout << ans[i] << ' ';

        cout << "\n";
    }
}