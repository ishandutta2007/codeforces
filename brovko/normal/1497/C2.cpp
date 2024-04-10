#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;
        
        while(k > 3)
        {
            k--;
            n--;
            cout << 1 << ' ';
        }

        if(n % 2)
            cout << 1 << ' ' << n / 2 << ' ' << n / 2 << "\n";

        else if(n % 4)
            cout << 2 << ' ' << (n - 2) / 2 << ' ' << (n - 2) / 2 << "\n";

        else cout << n / 4 << ' ' << n / 4 << ' ' << n / 2 << "\n";
    }
}