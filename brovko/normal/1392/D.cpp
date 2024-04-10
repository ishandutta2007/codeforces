#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

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

        int f = 0;

        for(int i = 0; i < n - 1; i++)
            if(s[i] != s[i + 1])
                f = 1;

        if(f == 0)
        {
            cout << 1 + (n - 1) / 3 << "\n";
        }
        else
        {
            int l = 0;

            while(s[l] == s[l + 1])
                l++;

            l++;

            char c = 'A';
            int k = 0;
            int ans = 0;

            for(int i = 0; i < n; i++)
            {
                if(c == s[(i + l) % n])
                    k++;
                else
                {
                    ans += k / 3;
                    k = 1;
                }

                c = s[(i + l) % n];
            }

            ans += k / 3;

            cout << ans << "\n";
        }
    }
}