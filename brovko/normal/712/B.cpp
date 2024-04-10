#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    if(s.size() % 2)
    {
        cout << -1;
        return 0;
    }

    int x = 0, y = 0;

    for(auto to:s)
    {
        if(to == 'L')
            x--;

        if(to == 'R')
            x++;

        if(to == 'D')
            y--;

        if(to == 'U')
            y++;
    }

    cout << (abs(x) + abs(y)) / 2;
}