// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int INF = INT_MAX >> 1;
struct node
{
    int t, c;
    friend bool operator<(const node &A, const node &B) { return A.c < B.c; }
} a[300005];
int n, k;
long long ans, sum;
std::priority_queue<int, std::vector<int>, std::greater<int>> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i].t >> a[i].c;
    std::sort(a + 1, a + 1 + n);
    for (int i = n; i; --i)
    {
        sum += a[i].t;
        que.push(a[i].t);
        while ((int)que.size() > k)
            sum -= que.top(), que.pop();
        ans = std::max(ans, a[i].c * sum);
    }
    std::cout << ans << std::endl;
    return 0;
}