// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 Rand(seed);
int T, n, from[200005], ans[100005];
std::vector<int> p;
#ifdef debug
int val[100005], tim;
long long query(int x, int y) { return ++tim, 1ll * val[x] * val[y] / std::__gcd(val[x], val[y]); }
#else
long long query(int x, int y)
{
    std::cout << "? " << x << ' ' << y << std::endl;
    long long res;
    std::cin >> res;
    return res;
}
#endif
signed main()
{
#ifdef debug
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    for (int i = 2; i <= 200000; ++i)
    {
        if (!from[i])
            p.push_back(from[i] = i);
        for (auto j : p)
        {
            if (i * j > 200000)
                break;
            from[i * j] = j;
            if (i % j == 0)
                break;
        }
    }
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
#ifdef debug
        tim = 0;
        for (int i = 1; i <= n; ++i)
            std::cin >> val[i];
#endif
        std::fill(ans + 1, ans + 1 + n, -1);
        if (n < 100)
        {
            int min;
            std::priority_queue<std::pair<long long, std::pair<int, int>>> que;
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j < i; ++j)
                    que.push({query(i, j), {i, j}});
            std::pair<long long, std::pair<int, int>> now = que.top();
            que.pop();
            if ((static_cast<int>(std::sqrt(now.first)) % 2) ^
                (now.second.first == que.top().second.first || now.second.first == que.top().second.second))
                min = ans[now.second.second] = std::sqrt(now.first), ans[now.second.first] = std::sqrt(now.first) + 1;
            else
                min = ans[now.second.first] = std::sqrt(now.first), ans[now.second.second] = std::sqrt(now.first) + 1;
            while (!que.empty())
            {
                now = que.top();
                que.pop();
                if (ans[now.second.first] > min || ans[now.second.second] > min)
                    continue;
                if (~ans[now.second.first])
                    min = ans[now.second.second] = now.first / ans[now.second.first];
                if (~ans[now.second.second])
                    min = ans[now.second.first] = now.first / ans[now.second.second];
            }
            std::cout << '!';
            for (int i = 1; i <= n; ++i)
                std::cout << ' ' << ans[i];
            std::cout << std::endl;
        }
        else
        {
            int pos;
            auto rnd = [&](int x)
            {
                int res;
                do
                    res = Rand() % n + 1;
                while (res == x);
                return res;
            };
            while (true)
            {
                pos = Rand() % n + 1;
                long long v = query(pos, rnd(pos));
                for (int i = 0; i != 20; ++i)
                    v = std::__gcd(v, query(pos, rnd(pos)));
                if (std::binary_search(p.begin(), p.end(), v) && v > (n + 50) / 2)
                {
                    ans[pos] = v;
                    break;
                }
            }
            for (int i = 1; i <= n; ++i)
                if (i != pos)
                    ans[i] = query(i, pos) / ans[pos];
            if (*std::max_element(ans + 1, ans + 1 + n) > n)
                for (int i = 1; i <= n; ++i)
                    if (ans[i] < 5)
                        ans[i] *= ans[pos];
            std::cout << '!';
            for (int i = 1; i <= n; ++i)
                std::cout << ' ' << ans[i];
            std::cout << std::endl;
        }
#ifdef debug
        for (int i = 1; i <= n; ++i)
            assert(ans[i] == val[i]);
        std::cout << "Used times: " << tim << std::endl;
#endif
    }
    return 0;
}