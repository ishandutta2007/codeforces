#include <bits/stdc++.h>
#define int long long
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

        if(n % 2)
        {
            cout << "0\n";
            continue;
        }
        else
        {
            int x = 1;

            for(int i = 0; i < n / 2; i++)
                x = x * (i + 1) % 998244353;

            x = x * x % 998244353;

            cout << x << "\n";
        }
    }
}