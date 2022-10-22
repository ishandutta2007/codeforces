#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int t, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        if(n < 31)
            cout << "NO\n";
        else
        {
            cout << "YES\n";

            if(n == 36)
                cout << "5 10 15 6\n";

            else if(n == 40)
                cout << "6 9 10 15\n";

            else if(n == 44)
                cout << "6 10 13 15\n";

            else cout << "6 10 14 " << n - 30 << "\n";
        }
    }
}