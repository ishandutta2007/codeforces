// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int xx[] = {0, +1, 0, -1}, yy[] = {+1, 0, -1, 0};
int n, m, w, a[2005][2005];
long long dis[2005][2005], sp1, sp2, ans;
std::vector<int> app;
int getx(int x) { return x / m + 1; }
int gety(int x) { return x % m + 1; }
int pull(int x, int y) { return (x - 1) * m + (y - 1); }
std::queue<int> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> w;
    memset(a, -1, sizeof(a));
    memset(dis, 0x3f, sizeof(dis));
    sp1 = LLONG_MAX / 2;
    sp2 = LLONG_MAX / 2;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            std::cin >> a[i][j];
            if (a[i][j] > 0)
                app.push_back(pull(i, j));
        }
    dis[1][1] = 0;
    que.push(pull(1, 1));
    while (!que.empty())
    {
        int now = que.front();
        const long long &v = dis[getx(now)][gety(now)];
        que.pop();
        for (int i = 0; i != 4; ++i)
            if (~a[getx(now) + xx[i]][gety(now) + yy[i]] && v + w < dis[getx(now) + xx[i]][gety(now) + yy[i]])
                dis[getx(now) + xx[i]][gety(now) + yy[i]] = v + w, que.push(pull(getx(now) + xx[i], gety(now) + yy[i]));
        if (a[getx(now)][gety(now)] > 0 && v + a[getx(now)][gety(now)] < sp1)
            sp1 = v + a[getx(now)][gety(now)];
    }
    ans = dis[n][m];
    dis[n][m] = 0;
    que.push(pull(n, m));
    while (!que.empty())
    {
        int now = que.front();
        const long long &v = dis[getx(now)][gety(now)];
        que.pop();
        for (int i = 0; i != 4; ++i)
            if (~a[getx(now) + xx[i]][gety(now) + yy[i]] && v + w < dis[getx(now) + xx[i]][gety(now) + yy[i]])
                dis[getx(now) + xx[i]][gety(now) + yy[i]] = v + w, que.push(pull(getx(now) + xx[i], gety(now) + yy[i]));
        if (a[getx(now)][gety(now)] > 0 && v + a[getx(now)][gety(now)] < sp2)
            sp2 = v + a[getx(now)][gety(now)];
    }
    // for (int i = 1; i <= n; ++i)
    //     for (int j = 1; j <= m; ++j)
    //         std::cout << dis[i][j] << " \n"[j == m];
    ans = std::min(ans, sp1 + sp2);
    std::cout << (ans >= LLONG_MAX / 4 ? -1 : ans) << std::endl;
    return 0;
}