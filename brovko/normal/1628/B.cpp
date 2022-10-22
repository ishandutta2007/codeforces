#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n;
string s[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> s[i];

        map <string, int> m;
        bool F = 0;

        for(int i = 0; i < n; i++)
        {
            m[s[i]]++;

            if(s[i][0] == s[i].back())
                F = 1;

            string t = s[i];

            reverse(t.begin(), t.end());

            if(m[t])
                F = 1;

            if(t.size() == 3 && m[t.substr(0, 2)])
                F = 1;
        }

        m.clear();

        for(int i = n - 1; i >= 0; i--)
        {
            m[s[i]]++;

            string t = s[i];
            reverse(t.begin(), t.end());

            if(t.size() == 3 && m[t.substr(1, 2)])
                F = 1;
        }

        cout << (F ? "YES\n" : "NO\n");
    }
}