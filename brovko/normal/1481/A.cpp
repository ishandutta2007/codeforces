#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, px, py;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> px >> py >> s;
        int xl = 0, xr = 0, yl = 0, yr = 0;

        for(auto to:s)
        {
            if(to == 'R')
                xr++;

            if(to == 'L')
                xl--;

            if(to == 'U')
                yr++;

            if(to == 'D')
                yl--;
        }

        if(px >= xl && px <= xr && py >= yl && py <= yr)
            cout << "YES\n";
        else cout << "NO\n";
    }
}