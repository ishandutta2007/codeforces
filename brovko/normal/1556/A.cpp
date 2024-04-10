#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int t, c, d;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> c >> d;

        if(c == 0 && d == 0)
            cout << "0\n";

        else if(c == d)
            cout << "1\n";

        else if((c + d) % 2 == 0)
            cout << "2\n";

        else cout << "-1\n";
    }
}