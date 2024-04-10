#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back

using namespace std;

int t, a, b, used[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> a >> b;

        for(int i = 0; i <= a; i++)
        {
            int ab = i, ap = a - i, bb = a + b - (a + b) / 2 - ap, bp = (a + b) / 2 - ab;

            if(ab >= 0 && ap >= 0 && bb >= 0 && bp >= 0 && ap + ab == a && bp + bb == b)
                used[ab + bb] = 1;
        }

        swap(a, b);

        for(int i = 0; i <= a; i++)
        {
            int ab = i, ap = a - i, bb = a + b - (a + b) / 2 - ap, bp = (a + b) / 2 - ab;

            if(ab >= 0 && ap >= 0 && bb >= 0 && bp >= 0 && ap + ab == a && bp + bb == b)
                used[ab + bb] = 1;
        }

        int ans = 0;

        for(int i = 0; i <= a + b; i++)
            if(used[i])
                ans++;

        cout << ans << "\n";

        for(int i = 0; i <= a + b; i++)
            if(used[i])
                cout << i << ' ';

        cout << "\n";

        for(int i = 0; i <= a + b; i++)
            used[i] = 0;
    }
}