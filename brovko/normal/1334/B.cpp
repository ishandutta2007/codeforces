#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, x, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> x;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);

        int s = 0, k = 0;

        for(int i = n - 1; i >= 0; i--)
        {
            s += a[i];

            if(s >= x * (k + 1))
                k++;
            else break;
        }

        cout << k << "\n";
    }
}