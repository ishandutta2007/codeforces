#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
int k;
int ones;
ll ans;
vector<pair<int, int>> codif[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int tot;
        cin >> tot >> k;
        for (int i = 1; i < N; i++)
        {
                int j = i, sol = 1;
                for (int d = 2; d * d <= j; d++)
                {
                        int cnt = 0;
                        while (j % d == 0)
                        {
                                j /= d;
                                cnt++;
                        }
                        cnt %= k;
                        if (cnt)
                                codif[i].push_back({d, cnt});
                }
                if (j > 1)
                {
                        int cnt = 1 % k;
                        if (cnt)
                                codif[i].push_back({j, cnt});
                }
        }
        map<vector<pair<int, int>>, int> f;
        int fuf = 0;
        while (tot--)
        {
                int x;
                cin >> x;
                if (x == 1)
                        ans += ones++;
                else
                {
                        fuf += codif[x].empty();
                        vector<pair<int, int>> now = codif[x], inv = now;
                        for (auto &it : inv)
                                it.second = k - it.second;
                        ans += f[inv];
                        f[now]++;
                }
        }
        ans += fuf * (ll) ones;
        cout << ans << "\n";
}