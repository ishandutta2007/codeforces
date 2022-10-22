#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string s;
int x, y;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> s;
    for(auto to:s)
    {
        if(to=='0')
        {
            x++;
            cout << x%2*2+1 << " 1\n";
        }
        else
        {
            y++;
            cout << y%4+1 << " 2\n";
        }
    }
}