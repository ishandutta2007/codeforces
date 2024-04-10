#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string s;

int gl(char c)
{
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'Y' || c == 'U');
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    s += 'A';

    int x = 0;
    int ans = 0;

    for(auto to:s)
    {
        if(gl(to))
            x = 0;
        else x++;

        ans = max(ans, x);
    }

    cout << ans + 1;
}