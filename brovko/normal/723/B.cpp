#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    s += "_";

    int x = 0, y = 0, z = 0, t = 0;

    for(auto to:s)
    {
        if(to >= 'a' && to <= 'z' || to >= 'A' && to <= 'Z')
            t++;
        else
        {
            if(z)
            {
                if(t)
                    y++;
            }
            else x = max(x, t);

            t = 0;
        }

        if(to == '(')
            z = 1;

        if(to == ')')
            z = 0;
    }

    cout << x << ' ' << y;
}