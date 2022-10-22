#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n;
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

        int x = 0;
        int ans = 0;

        for(auto to:s)
        {
            if(to == '(')
                x++;
            else x--;

            ans = min(ans, x);
        }

        cout << -ans << "\n";
    }
}