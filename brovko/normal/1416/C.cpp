#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 goerohgerigegoihr
#define y0 peowjfefwepojfewe

using namespace std;

int n, a[300005], ans, m[50000005];
long long k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < 30; i++)
    {
        int x = (1 << i);
        int l = 0, r = 0;

        if(i < 6)
        {
            map <int32_t, int32_t> m;

            for(int j = 0; j < n; j++)
            {
                int y = a[j] / x;
                m[y]++;

                if((y & 1) == 0)
                    l += m[y + 1];
                else r += m[y - 1];
            }

            if(r < l)
                ans += x;

            k += 1ll * min(l, r);
        }
        else
        {
            for(int j = 0; j < n; j++)
            {
                int y = a[j] / x;

                m[y]++;

                if((y & 1) == 0)
                    l += m[y + 1];
                else r += m[y - 1];
            }

            if(r < l)
                ans += x;

            k += 1ll * min(l, r);

            for(int j = 0; j < n; j++)
            {
                int y = a[j] / x;
                m[y] = 0;
            }
        }

    }

    cout << k << ' ' << ans;
}