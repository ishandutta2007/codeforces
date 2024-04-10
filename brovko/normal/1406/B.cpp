#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 goerohgerigegoihr
#define y0 peowjfefwepojfewe

using namespace std;

int t, n, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector <int> pos, neg;

        for(int i = 0; i < n; i++)
        {
            if(a[i] >= 0)
                pos.push_back(a[i]);
            else neg.push_back(a[i]);
        }

        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());

        int ans = -1e18;

        for(int p = 0; p <= 5; p++)
            if(pos.size() >= p && neg.size() >= 5 - p)
            {
                if(p % 2 == 0)
                {
                    int x = 1;

                    for(int i = 0; i < p; i++)
                        x *= pos[i];

                    for(int i = 0; i < 5 - p; i++)
                        x *= neg[neg.size() - 1 - i];

                    ans = max(ans, x);
                }
                else
                {
                    int x = 1;

                    for(int i = 0; i < p; i++)
                        x *= pos[pos.size() - 1 - i];

                    for(int i = 0; i < 5 - p; i++)
                        x *= neg[i];

                    ans = max(ans, x);
                }
            }

        cout << ans << "\n";
    }
}