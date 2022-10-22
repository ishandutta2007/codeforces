#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

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

        if(n % 3 == 0)
            cout << n / 3 << " 0 0\n";

        else if(n >= 5 && (n - 5) % 3 == 0)
            cout << (n - 5) / 3 << " 1 0\n";

        else if(n >= 7 && (n - 7) % 3 == 0)
            cout << (n - 7) / 3 << " 0 1\n";

        else cout << "-1\n";
    }
}