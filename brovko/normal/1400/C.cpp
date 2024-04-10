#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int t, x;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> s >> x;
        int n = s.size();

        int f[n];

        for(int i = 0; i < n; i++)
            f[i] = 1;

        for(int i = 0; i < n; i++)
            if(s[i] == '0')
            {
                if(i - x >= 0)
                    f[i - x] = 0;

                if(i + x < n)
                    f[i + x] = 0;
            }

        int F = 1;

        for(int i = 0; i < n; i++)
            if(s[i] == '1')
            {
                int f2 = 0;

                if(i - x >= 0 && f[i - x] == 1)
                    f2 = 1;

                if(i + x < n && f[i + x] == 1)
                    f2 = 1;

                if(f2 == 0)
                    F = 0;
            }

        if(F == 0)
            cout << -1 << "\n";
        else
        {
            for(int i = 0; i < n; i++)
                cout << f[i];

            cout << "\n";
        }
    }
}