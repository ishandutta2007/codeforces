#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int x = 0, ans = 1;

    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] - '0' + s[i - 1] - '0' == 9)
            x++;
        else
        {
            if(x % 2 == 0 && x > 0)
                ans *= x / 2 + 1;

            x = 0;
        }
    }

    if(x % 2 == 0 && x > 0)
        ans *= x / 2 + 1;

    cout << ans;
}