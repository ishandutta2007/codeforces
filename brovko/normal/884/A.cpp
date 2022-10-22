#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, t, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        t -= 86400 - a[i];

        if(t <= 0)
        {
            cout << i + 1;
            return 0;
        }
    }
}