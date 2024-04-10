#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n;
ll l[N], r[N], sum, sum_l;

bool cmp(int i, int j)
{
        return l[i] > l[j];
}

bool ok(ll x)
{
        int need = (n + 1) / 2;

        vector <int> ids;
        for (int i = 1; i <= n; i++)
                if (r[i] >= x)
                        ids.push_back(i);

        if ((int) ids.size() < need)
                return 0;

        ll rofl = sum_l;
        sort(ids.begin(), ids.end(), cmp);
        for (int j = 0; j < need; j++)
        {
                int i = ids[j];
                rofl += max(0LL, x - l[i]);
                if (rofl > sum)
                        return 0;
        }
        return 1;
}

int main()
{
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        int tst;
        cin >> tst;

        while (tst--)
        {
                sum_l = 0;
                cin >> n >> sum;
                for (int i = 1; i <= n; i++)
                {
                        cin >> l[i] >> r[i];
                        sum_l += l[i];
                }
                ll lo = 0, hi = (ll) 1e14, ans = 0;
                while (lo <= hi)
                {
                        ll mid = (lo + hi) / 2;
                        if (ok(mid))
                        {
                                ans = mid;
                                lo = mid + 1;
                        }
                        else
                                hi = mid - 1;
                }
                cout << ans << "\n";
        }

        return 0;
}