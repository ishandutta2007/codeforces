#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, l, r, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> l >> r;

        for(int i = l; i <= r; i++)
            cin >> a[i];

        int x = 0;

        for(int j = 0; j < 17; j++)
        {
            int zero = 0, one = 0;

            for(int i = l; i <= r; i++)
                if(a[i] & (1 << j))
                    one++;
                else zero++;

            if(one > zero)
                x += (1 << j);
        }

        cout << x << "\n";
    }
}