#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

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
        string s;
        cin >> s;

        if(s.size() == 2)
        {
            cout << s[1] << "\n";
            continue;
        }

        int ans = 1e9;

        for(auto x:s)
            ans = min(ans, (int)x - '0');

        cout << ans << "\n";
    }
}