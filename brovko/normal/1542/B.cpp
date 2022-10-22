#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second

using namespace std;

int t, n, a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {

        cin >> n >> a >> b;

        int z = 1;
        int f = 0;

        for(int i = 0; (i < 35 && z <= n); i++)
        {
            if((n - z) % b == 0)
            {
                f = 1;
            }

            z *= a;
        }

        if(f)
            cout << "Yes\n";
        else cout << "No\n";

    }
}