#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

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
        int n, k;
        cin >> n >> k;

        if(n == 4 && k == 3)
            cout << "-1\n";
        else if(k < n - 1)
        {
            cout << n - 1 << ' ' << k << "\n";
            if(k)
                cout << n - 1 - k << ' ' << 0 << "\n";

            for(int i = 1; i < n / 2; i++)
                if(i != k && i != n - 1 - k)
                    cout << i << ' ' << n - 1 - i << "\n";
        }
        else
        {
            cout << 0 << ' ' << n / 2  << "\n" << 1 << ' ' << n / 2 - 1 << "\n" << n - 1 << ' ' << n - 2 << "\n";

            for(int i = 2; i < n / 2 - 1; i++)
                cout << i << ' ' << n - 1 - i << "\n";
        }
    }
}