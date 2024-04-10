#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

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

        for(int i = 1; i < n; i++)
            if(s[i] == '?' && s[i - 1] != '?')
                s[i] = 'R' + 'B' - s[i - 1];

        if(s[n - 1] == '?')
            s[n - 1] = 'B';

        for(int i = n - 2; i >= 0; i--)
        {
            if(s[i] == '?' && s[i + 1] != '?')
                s[i] = 'R' + 'B' - s[i + 1];
        }

        cout << s << "\n";
    }
}