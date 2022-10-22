// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, q, a[300005], b[600005];
long long k, ans[300005];
std::deque<int> que;
std::deque<std::pair<int, long long>> sta;
std::vector<std::pair<int, int>> query[600005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        while (!que.empty() && a[que.back()] > a[i])
            que.pop_back();
        que.push_back(i);
        while (que.front() <= i - k)
            que.pop_front();
        b[i] = a[que.front()];
    }
    for (int i = 1, l, r; i <= q; ++i)
        std::cin >> l >> r, ans[i] = a[l], query[l + k].push_back({(r - l % k) / k * k + l % k, i});
    for (int i = 0; i != k; ++i)
    {
        sta.clear();
        sta.push_front({((n - i) / k + 1) * k + i, 0});
        for (int j = (n - i) / k * k + i; j >= k; j -= k)
        {
            while (!sta.empty() && b[sta.front().first] >= b[j])
                sta.pop_front();
            sta.push_front({j, sta.front().second + (sta.front().first - j) / k * b[j]});
            std::sort(query[j].begin(), query[j].end());
            for (auto l : query[j])
            {
                while (sta.front().first <= l.first && a[j - k] <= b[sta.front().first])
                    sta.pop_front();
                if (sta.front().first > l.first)
                    ans[l.second] += ((l.first - j) / k + 1) * a[j - k];
                else
                {
                    std::deque<std::pair<int, long long>>::iterator iter =
                        --std::upper_bound(sta.begin(), sta.end(), std::make_pair(l.first, LLONG_MAX));
                    ans[l.second] += (sta.front().first - j) / k * a[j - k] + sta.front().second - iter->second -
                                     b[iter->first] * (iter->first / k - (l.first / k) - 1);
                }
            }
        }
    }
    for (int i = 1; i <= q; ++i)
        std::cout << ans[i] << std::endl;
    return 0;
}