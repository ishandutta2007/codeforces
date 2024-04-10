#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        int n = s.size();

        vector <int> ps(n + 1);

        for(int i = 0; i < n; i++)
            ps[i + 1] = ps[i] + s[i] - '0';

        int ans = 1e9;

        for(int i = 0; i < n; i++)
        {
            int L = i - 1, R = n;

            while(R - L > 1)
            {
                int M = (L + R) / 2;

                if(ps[n] >= (M - i + 1))
                    L = M;
                else R = M;
            }

            ans = min(ans, ps[n] - ps[R] + ps[i]);
        }

        cout << ans << "\n";
    }
}