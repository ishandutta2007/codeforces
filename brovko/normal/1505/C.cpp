#include <bits/stdc++.h>
#define int long long

using namespace std;

string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    for(int i = 2; i < s.size(); i++)
    {
        if(s[i] - 'A' != (s[i - 1] + s[i - 2] - 2 * 'A') % 26)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}