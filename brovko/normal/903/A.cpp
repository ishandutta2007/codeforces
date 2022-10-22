#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

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
        int f = 0;

        while(n >= 0)
            {
                if(n % 3 == 0)
                    f = 1;
                n -= 7;
            }

        if(f)
            cout << "YES\n";
        else cout << "NO\n";
    }
}