#include <bits/stdc++.h>
#define ld long double
#define int long long

using namespace std;

int t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        int x = 0, ans = 0, k = 0;

        for(auto to:s)
            if(to == '(')
               k++;

        for(auto to:s)
        {
            if(to == ')' || to == '?' && k * 2 == s.size())
                x--;
            else
            {
                x++;
                if(to == '?')
                    k++;
            }

            ans = min(ans, x);
        }

        if(s.size() % 2 != 0 || ans < 0)
            cout << "NO\n";
        else cout << "YES\n";
    }
}