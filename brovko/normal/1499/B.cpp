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

        int f = 0;

        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == '1' && s[i - 1] == '1' && f == 0)
                f = 1;

            if(s[i] == '0' && s[i - 1] == '0' && f == 1)
                f = 2;
        }

        if(f == 2)
            cout << "NO\n";
        else cout << "YES\n";
    }
}