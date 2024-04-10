#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> s;

        int ans = 10;

        int d = 0;

        for(int i = 0; i < 10; i++)
        {
            if(i % 2 == 0 && s[i] != '0')
                d++;

            if(i % 2 != 0 && s[i] == '1')
                d--;

            if(d > (10 - i) / 2)
                ans = min(ans, i + 1);
        }

        d = 0;

         for(int i = 0; i < 10; i++)
        {
            if(i % 2 != 0 && s[i] != '0')
                d++;

            if(i % 2 == 0 && s[i] == '1')
                d--;

            if(d > (9 - i) / 2)
                ans = min(ans, i + 1);
        }

        cout << ans << "\n";
    }
}