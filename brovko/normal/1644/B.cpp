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
        int n;
        cin >> n;

        for(int i = 2; i <= n + 1; i++)
        {
            for(int j = n; j >= i; j--)
            {
                cout << j << ' ';
            }

            cout << 1 << ' ';

            for(int j = i - 1; j >= 2; j--)
                cout << j << ' ';

            cout << "\n";
        }
    }
}