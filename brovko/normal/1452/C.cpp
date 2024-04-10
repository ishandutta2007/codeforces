#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

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
        cin >> s;

        int x = 0, ans = 0;

        for(auto to:s)
        {
            if(to == '(')
                x++;

            if(to == ')' && x > 0)
            {
                x--;
                ans++;
            }
        }

        x = 0;

        for(auto to:s)
        {
            if(to == '[')
                x++;

            if(to == ']' && x > 0)
            {
                x--;
                ans++;
            }
        }

        cout << ans << "\n";
    }
}