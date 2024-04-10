#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n;
string p[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> p[i];

    int ans = 0;

    for(char c = 'a'; c <= 'z'; c++)
    {
        int x = 0, k = 0;

        for(auto to:p[0])
        {
            if(to == c)
                k++;
            else k = 0;

            x = max(x, k);
        }

        for(int i = 1; i < n; i++)
        {
            int m = p[i].size();

            int L = 0, R = m - 1;

            while(L < m && p[i][L] == c)
                L++;

            while(R >= 0 && p[i][R] == c)
                R--;

            int y = 0;
            k = 0;

            for(auto to:p[i])
            {
                if(to == c)
                    k++;
                else k = 0;

                y = max(y, k);
            }

            y = max({y, L, m - 1 - R});

            if(x > 0)
                y = max(y, L + m - R);

            if(L == m)
                y = max(y, x + m * (x + 1));

            y = min(y, (int)1e9);
            x = y;
        }

        ans = max(ans, x);
    }

    cout << ans;
}