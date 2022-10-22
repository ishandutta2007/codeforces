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
int n, a[500005], b[500005], ans;
template <class Comp>
struct dddl : std::deque<std::pair<int, int>>
{
    void pop_until(int pos)
    {
        while (!empty() && front().second <= pos)
            pop_front();
    }
    void push(int val, int pos)
    {
        while (!empty() && !Comp()(back().first, val))
            pop_back();
        push_back(std::make_pair(val, pos));
    }
    int top()
    {
        return front().first;
    }
    int top(int x)
    {
        return empty() ? x : std::min(x, front().first, Comp());
    }
};
dddl<std::less<int>> min[2];
dddl<std::greater<int>> max[2];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i];
    for (int l = 0, r = 0; l != n;)
    {
        if ((r - l) & 1)
        {
            int m = (l + r - 1) >> 1;
            ans = std::max(ans, (r - l - 1) >> 1);
            if (r - l == 1)
                b[m] = a[l];
            else if (min[l & 1].top() > max[r & 1].top())
                b[m] = min[l & 1].top();
            else
                b[m] = max[l & 1].top();
            // std::cout << l << ' ' << m << ' ' << r << std::endl;
            // std::cout << min[0].top() << ' ' << min[1].top() << std::endl
            //           << max[0].top() << ' ' << max[1].top() << std::endl;
        }
        if (r != n && (l == r || min[r & 1].top(a[r]) > max[~r & 1].top() || max[r & 1].top(a[r]) < min[~r & 1].top()))
        {
            max[r & 1].push(a[r], r);
            min[r & 1].push(a[r], r);
            ++r;
        }
        else
        {
            max[l & 1].pop_until(l);
            min[l & 1].pop_until(l);
            ++l;
        }
    }
    std::cout << ans;
    for (int i = 0; i != n; ++i)
        std::cout << " \n"[!i] << b[i];
    std::cout << std::endl;
    return 0;
}