#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, q, a[200005], mu[500005], lp[500005], cnt[500005], used[200005], ans;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 2; i < 500005; i++)
        if(lp[i] == 0)
        {
            lp[i] = i;

            for(int j = i * i; j < 500005; j += i)
                if(lp[j] == 0)
                    lp[j] = i;
        }

    mu[1] = 1;

    for(int i = 2; i < 500005; i++)
    {
        if(lp[i] == lp[i / lp[i]])
            mu[i] = 0;
        else mu[i] = -mu[i / lp[i]];
    }

    for(int i = 0; i < q; i++)
    {
        int j;
        cin >> j;

        j--;
        used[j] ^= 1;

        vector <int> v;
        int x = a[j];

        while(x > 1)
        {
            v.pb(lp[x]);

            while(v.back() == lp[x])
                x /= v.back();
        }

        int k = v.size();

        for(int mask = 0; mask < (1 << k); mask++)
        {
            int y = 1;

            for(int i = 0; i < k; i++)
                if(mask & (1 << i))
                    y *= v[i];

            if(used[j])
            {
                ans += mu[y] * cnt[y];
                cnt[y]++;
            }
            else
            {
                cnt[y]--;
                ans -= mu[y] * cnt[y];
            }
        }

        cout << ans << "\n";
    }
}