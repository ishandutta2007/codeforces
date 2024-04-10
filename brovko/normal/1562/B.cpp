#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int t, k;
string s;

int f(int x)
{
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0)
            return 0;

    if(x == 1)
        return 0;

    return 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> k >> s;

        if(s.size() <= 4)
        {
            int ans = 1e9, x = 0;

            for(int mask = 0; mask < (1 << k); mask++)
            {
                int y = 0, z = 0;

                for(int i = 0; i < k; i++)
                    if(mask & (1 << i))
                    {
                        z++;
                        y = 10 * y + s[i] - '0';
                    }

                if(f(y) == 0 && z < ans)
                {
                    ans = z;
                    x = y;
                }
            }

            cout << ans << "\n" << x << "\n";
        }
        else
        {
            int F = 0;

            for(int i = 0; i < k; i++)
                if(f(s[i] - '0') == 0 && F == 0)
                {
                    F = 1;
                    cout << "1\n" << s[i] << "\n";
                }

            int c[10];

            for(int i = 0; i < 10; i++)
                c[i] = 0;

            for(int i = 0; i < k; i++)
                c[s[i] - '0']++;

            if(F == 0)
            {
                if(c[2] > 1)
                    cout << "2\n22\n";

                else if(c[3] > 1)
                    cout << "2\n33\n";

                else if(c[5] > 1)
                    cout << "2\n55\n";

                else cout << "2\n77\n";
            }
        }
    }
}