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

        int F = 0;

        int x = 0;

        while(x + 1 < n && (s[x + 1] < s[x] || s[x + 1] == s[x] && F == 1))
        {
            if(s[x + 1] < s[x])
                F = 1;

            x++;
        }

        for(int i = 0; i <= x; i++)
            cout << s[i];

        for(int i = x; i >= 0; i--)
            cout << s[i];

        cout << "\n";
    }
}