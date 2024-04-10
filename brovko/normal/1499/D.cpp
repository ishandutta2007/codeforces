#include <bits/stdc++.h>
//#define int long long
#define ld long double

using namespace std;

int t, kp[20000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 2; i < 20000005; i++)
        if(kp[i] == 0)
            for(int j = i; j < 20000005; j += i)
                kp[j]++;

    cin >> t;

    while(t--)
    {
        int c, d, x;
        cin >> c >> d >> x;
        int ans = 0;

        for(int i = 1; i * i <= x; i++)
            if(x % i == 0)
            {
                int g = i;

                if((x / g + d) % c == 0)
                {
                    int pq = (x / g + d) / c;
                    ans += (1 << kp[pq]);
                }

                if(i * i != x)
                {
                    int g = x / i;

                    if((x / g + d) % c == 0)
                    {
                        int pq = (x / g + d) / c;
                        ans += (1 << kp[pq]);
                    }
                }
            }

        cout << ans << "\n";
    }
}