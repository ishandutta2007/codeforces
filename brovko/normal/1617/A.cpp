#include <bits/stdc++.h>
#define int long long
#define ld long double

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

        int n = s.size();

        string t;
        cin >> t;

        sort(s.begin(), s.end());

        if(t != "abc" || s[0] != 'a')
            cout << s << "\n";
        else
        {
            for(int i = 0; i < n; i++)
                if(s[i] == 'a' || s[i] == 'c')
                    cout << s[i];

            for(int i = 0; i < n; i++)
                if(s[i] != 'a' && s[i] != 'c')
                    cout << s[i];

            cout << "\n";
        }
    }
}