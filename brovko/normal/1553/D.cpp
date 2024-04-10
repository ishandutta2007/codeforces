#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int q;
string s, t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while(q--)
    {
        cin >> s >> t;
        int n = s.size(), m = t.size();

        int x = 0, y = 0;

        for(int i = 0; i < n; i++)
        {
            if(x < m && i % 2 == x % 2 && s[i] == t[x])
                x++;

            if(y < m && i % 2 != y % 2 && s[i] == t[y])
                y++;
        }

        if(n % 2 != m % 2 && y >= m || n % 2 == m % 2 && x >= m)
            cout << "YES\n";
        else cout << "NO\n";
    }
}