#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, a[505], b[505];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> a[i];

        for(int i=0; i<n; i++)
            cin >> b[i];

        int k1 = 0;
        int k0 = 0;

        for(int i=0; i<n; i++)
        {
            if(b[i] == 0)
                k0++;
            else k1++;
        }

        int f = 1;
        for(int i=0; i<n-1; i++)
            if(a[i] > a[i + 1])
                f = 0;

        if(f == 0 && k0 * k1 == 0)
            cout << "No\n";
        else cout << "Yes\n";
    }
}