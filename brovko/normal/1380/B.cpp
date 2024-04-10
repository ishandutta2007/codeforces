#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

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

        int P = 0, S = 0, R = 0;

        for(auto to:s)
        {
            if(to == 'R')
                R++;

            else if(to == 'P')
                P++;

            else S++;
        }

        int Max = max(S, max(R, P));

        char c;

        if(Max == R)
            c = 'P';

        else if(Max == S)
            c = 'R';

        else c = 'S';

        for(auto to:s)
            cout << c;

        cout << "\n";
    }
}