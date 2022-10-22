#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t;
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
        int n = s.size();

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(i > 0 && s[i - 1] == s[i])
            {
                ans++;
                s[i] = '?';
            }
            else
            if(i > 1 && s[i - 2] == s[i])
            {
                ans++;
                s[i] = '#';
            }
        }

        cout << ans << "\n";
    }
}