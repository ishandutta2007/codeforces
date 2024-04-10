#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        string s;

        cin >> s;

        int ans = 0;

        for(int i = 0; i < 10; i++)
        {
            int k = 0;

            for(int j = 0; j < s.size(); j++)
            {
                if(s[j] - '0' == i)
                    k++;
            }

            ans = max(ans, k);
        }

        for(int x = 0; x < 10; x++)
            for(int y = 0; y < 10; y++)
        {
            if(x != y)
            {
                int k = 0;

                int f = 0;

                for(int i = 0; i < s.size(); i++)
                {
                    if(s[i] - '0' == x && f == 0)
                    {
                        f = 1;
                    }

                    if(s[i] - '0' == y && f == 1)
                    {
                        f = 0;
                        k += 2;
                    }
                }

                ans = max(ans, k);
            }
        }

        cout << s.size() - ans << "\n";
    }
}