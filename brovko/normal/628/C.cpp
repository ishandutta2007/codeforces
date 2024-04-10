#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, k;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> s;
    string t;

    for(int i = 0; i < n; i++)
    {
        string c = "z";

        if(abs(s[i] - 'a') > abs(s[i] - 'z'))
            c = "a";

        if(abs(s[i] - c[0]) <= k)
        {
            k -= abs(s[i] - c[0]);
            t += c;
        }
        else
        {
            t += "a";

            for(char x = 'a'; x <= 'z'; x++)
            {
                if(abs(x - s[i]) == k)
                {
                    t[i] = x;
                    k = 0;
                    x = 'z' + 1;
                }
            }
        }
    }

    if(k == 0)
        cout << t;
    else cout << -1;
}