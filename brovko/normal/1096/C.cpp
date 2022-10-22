#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, x;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> x;

        int ans = -1;

        for(int i = 1; i <= 1000; i++)
            if(ans == -1 && x * i % 180 == 0 && x * i <= (i - 2) * 180)
                ans = i;

        cout << ans << "\n";
    }
}