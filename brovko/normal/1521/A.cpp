#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int a, b;
        cin >> a >> b;

        if(b == 1)
            cout << "NO\n";
        else
        {
            cout << "YES\n";

            cout << a << ' ' << a * b << ' ' << a * (b + 1) << "\n";
        }
    }
}