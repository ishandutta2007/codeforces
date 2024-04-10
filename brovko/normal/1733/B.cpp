#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        if(x > y)
            swap(x, y);

        if(x != 0 || y == 0 || (n - 1) % y)
        {
            cout << "-1\n";
            continue;
        }

        int k = y;

        for(int i = 2; i <= n; i += k)
            for(int j = 0; j < k; j++)
                cout << i << ' ';

        cout << "\n";
    }
}