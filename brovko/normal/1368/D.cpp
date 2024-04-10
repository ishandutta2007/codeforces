#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[200005], k[25];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];

        int x = 0;

        while(a[i])
        {
            k[x] += a[i] % 2;
            x++;

            a[i] /= 2;
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        int x = 0;

        for(int j = 0; j < 25; j++)
            if(k[j])
            {
                k[j]--;
                x += (1ll << j);
            }

        ans += x * x;
    }

    cout << ans;
}