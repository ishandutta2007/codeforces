#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, q, t, k, d, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    while(q--)
    {
        cin >> t >> k >> d;
        int x = 0;

        for(int i = 0; i < n; i++)
            {
                if(a[i] <= t)
                {
                    x++;
                }
            }

        if(x < k)
        {
            cout << "-1\n";
        }
        else
        {
            int s = 0;

            for(int i = 0; i < n; i++)
            {
                if(a[i] <= t && k > 0)
                {
                    k--;
                    s += i + 1;
                    a[i] = t + d;
                }
            }

            cout << s << "\n";
        }
    }
}