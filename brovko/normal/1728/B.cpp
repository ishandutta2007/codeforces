#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
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
        int n;
        cin >> n;

        if(n % 2 == 0)
        {
            for(int i = 2; i < n; i += 2)
                cout << i << ' ' << i - 1 << ' ';

            cout << n - 1 << ' ' << n << "\n";
        }
        else
        {
            cout << "1 2 3 ";

            for(int i = 5; i < n; i += 2)
                cout << i << ' ' << i - 1 << ' ';

            cout << n - 1 << ' ' << n << "\n";
        }
    }
}