#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second

using namespace std;

int t, n, a[2005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        int k = 0;

        for(int i = 0; i < 2 * n; i++)
        {
            cin >> a[i];

            if(a[i] % 2)
                k++;
        }

        if(k == n)
            cout << "Yes\n";
        else cout << "No\n";
    }
}