#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n, cnt[N];
vector <int> cost[N];

int main()
{
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        int tst;
        cin >> tst;

        while (tst--)
        {
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                        cnt[i] = 0;
                        cost[i].clear();
                }
                for (int i = 1; i <= n; i++)
                {
                        int x, c;
                        cin >> x >> c;
                        cost[x].push_back(c);
                        cnt[x]++;
                }

                for (int i = 1; i < n; i++)
                        cnt[i] += cnt[i - 1];

                ll ans = 0;
                int take = 0;
                multiset <int> vals;
                for (int i = n - 1; i >= 0; i--)
                {
                        for (auto &c : cost[i])
                                vals.insert(c);
                        while (i && take < i - cnt[i - 1])
                        {
                                take++;
                                ans += *vals.begin();
                                vals.erase(vals.begin());
                        }
                }
                cout << ans << "\n";
        }

        return 0;
}