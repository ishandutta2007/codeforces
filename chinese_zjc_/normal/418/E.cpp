// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
const int B = 316;
int n, m, a[100005], c[100005], ans[100005], cnt[200005], sum[100005];
std::vector<int> app;
struct oper
{
    int f, x, y;
} b[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], app.push_back(a[i]);
    std::cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> b[i].f >> b[i].x >> b[i].y;
        if (b[i].f == 1)
            app.push_back(b[i].x);
        else if (b[i].x > 1)
            b[i].x = (b[i].x - 2) % 2 + 2;
    }
    std::sort(app.begin(), app.end());
    app.erase(std::unique(app.begin(), app.end()), app.end());
    for (int i = 1; i <= n; ++i)
        a[i] = std::lower_bound(app.begin(), app.end(), a[i]) - app.begin();
    for (int i = 1; i <= m; ++i)
        if (b[i].f == 1)
            b[i].x = std::lower_bound(app.begin(), app.end(), b[i].x) - app.begin();
    for (int i = 0; i * B < n; ++i)
    {
        std::fill(cnt, cnt + app.size(), 0);
        std::fill(sum, sum + n, 0);
        std::copy(a + 1, a + 1 + n, c + 1);
        for (int j = 1; j <= i * B; ++j)
            ++cnt[c[j]];
        for (int j = 0; j != int(app.size()); ++j)
            ++sum[cnt[j]];
        for (int j = n; j--;)
            sum[j] += sum[j + 1];
        for (int j = 1; j <= m; ++j)
            switch (b[j].f)
            {
            case 1:
                if (b[j].y <= i * B)
                {
                    --sum[cnt[c[b[j].y]]--];
                    ++sum[++cnt[b[j].x]];
                }
                c[b[j].y] = b[j].x;
                break;
            case 2:
                if (i * B < b[j].y && b[j].y <= (i + 1) * B)
                {
                    for (int k = i * B; ++k <= b[j].y;)
                        ++sum[++cnt[c[k]]];
                    // std::cout << i + 1 << std::endl;
                    // for (int j = 0; j <= n; ++j)
                    //     std::cout << sum[j] << " \n"[j == n];
                    switch (b[j].x)
                    {
                    case 1:
                        ans[j] = app[c[b[j].y]];
                        break;
                    case 2:
                        ans[j] = cnt[c[b[j].y]];
                        break;
                    case 3:
                        ans[j] = sum[cnt[c[b[j].y]]];
                        break;
                    }
                    for (int k = b[j].y; k > i * B; --k)
                        --sum[cnt[c[k]]--];
                }
                break;
            }
    }
    for (int i = 1; i <= m; ++i)
        if (ans[i])
            std::cout << ans[i] << '\n';
    return 0;
}