#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int q, n, m;
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

        n = s.size(), m = t.size();
        int f = 0;

        for(int L = 0; L < n; L++)
            for(int R = L; R < n; R++)
            {
                string x = s.substr(L, R - L + 1);

                int y = R - 1;

                while(y >= 0 && x.size() < m)
                {
                    x += s.substr(y, 1);
                    y--;
                }

                if(x == t)
                    f = 1;
            }

        if(f)
            cout << "YES\n";
        else cout << "NO\n";
    }
}