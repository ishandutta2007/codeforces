// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
// #define int long long
// #define double long double
const long double PI = acos(-1);
const long double eps = 1e-10;
#ifdef int
const long long INF = LLONG_MAX >> 1;
#else
const int INF = INT_MAX >> 1;
#endif
bool has[100005];
int n, cnt[100005], from[100005];
long long ans = 1;
std::vector<int> stack, p;
template <class FUN>
void dfs(int now, int val, const std::vector<int> &app, FUN F)
{
    if (now == (int)app.size())
    {
        F(val);
        return;
    }
    dfs(now + 1, val, app, F);
    dfs(now + 1, val * -p[app[now]], app, F);
}
void add(int now, int d)
{
    std::vector<int> app;
    for (int i = now; ~from[i]; i /= p[from[i]])
        if (app.empty() || app.back() != from[i])
            app.push_back(from[i]);
    dfs(0, 1, app, [&](const int &val)
        { cnt[abs(val)] += d; });
}
signed main()
{
    std::ios::sync_with_stdio(false);
    memset(from, -1, sizeof(from));
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        static int x;
        std::cin >> x;
        has[x] = true;
    }
    for (int i = 100000; i; --i)
        for (int j = i; j <= 100000 && !has[i]; j += i)
            has[i] |= has[j];
    for (int i = 2; i <= 100000; ++i)
    {
        if (!~from[i])
            from[i] = p.size(), p.push_back(i);
        for (int j = 0; j != (int)p.size(); ++j)
        {
            if (p[j] * i > 100000)
                break;
            from[p[j] * i] = j;
            if (from[i] == j)
                break;
        }
    }
    for (int i = 100000; i; --i)
        if (has[i])
        {
            std::vector<int> app;
            for (int j = i; ~from[j]; j /= p[from[j]])
                if (app.empty() || app.back() != from[j])
                    app.push_back(from[j]);
            int tmp = 0;
            dfs(0, 1, app, [&](const int &val)
                { tmp += val < 0 ? -cnt[-val] : cnt[val]; });
            if (tmp)
                while (tmp)
                {
                    const int &val = stack.back();
                    if (std::__gcd(val, i) == 1)
                    {
                        --tmp;
                        ans = std::max(ans, 1ll * i * val);
                    }
                    add(val, -1);
                    stack.pop_back();
                }
            else
                add(i, +1), stack.push_back(i);
        }
    std::cout << ans << std::endl;
    return 0;
}