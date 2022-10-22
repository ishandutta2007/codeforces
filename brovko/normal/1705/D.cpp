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
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        int x = 0, y = 0;
        li ans = 0;

        if(s[0] != t[0])
        {
            cout << "-1\n";
            continue;
        }

        while(x < n && y < n)
        {
            ans += abs(x - y);

            char c = s[x];

            while(x < n && s[x] == c)
                x++;

            c = t[y];

            while(y < n && t[y] == c)
                y++;
        }

        if(x == n && y == n)
            cout << ans << "\n";
        else cout << "-1\n";
    }
}