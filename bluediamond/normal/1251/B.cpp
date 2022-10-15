#include <bits/stdc++.h>

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        int t;
        cin >> t;

        while (t--)
        {
                int n;
                cin >> n;
                int ans = 0, rofl = 0;
                bool is = 0;
                for (int i = 0; i < n; i++)
                {
                        string s;
                        cin >> s;
                        int f[2];
                        f[0] = f[1] = 0;
                        for (auto &c : s)
                                f[c - '0']++;
                        if ((f[0] % 2 == 0 && f[1] % 2 == 0) || (int) s.size() % 2)
                        {
                                if ((int) s.size() % 2 == 1)
                                        is = 1;
                                ans++;
                        }
                        else
                                rofl++;
                }
                cout << ans + rofl / 2 * 2 + ((rofl % 2) && is) << "\n";
        }

        return 0;
}