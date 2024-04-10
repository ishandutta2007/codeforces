// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, m, F[405], from[805], cnt;
char c[25][25];
bool lin[25][25], col[25][25], in[805];
void clear(std::vector<int> &x) { x.clear(); }
int find(int now) { return F[now] == now ? now : F[now] = find(F[now]); }
std::vector<int> to[805];
void work()
{
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            lin[i][j] = !(c[i][j] == 'O' && c[i][j + 1] == 'O');
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            col[i][j] = !(c[i][j] == 'O' && c[i + 1][j] == 'O');
    bool flag;
    do
    {
        flag = false;
        std::vector<int> S, T, X, Y;
        for (int i = 0; i != n; ++i)
            for (int j = 0; j != m; ++j)
                if (c[i][j] == 'O' && c[i][j + 1] == 'O')
                    (lin[i][j] ? S : T).push_back(i * m + j);
        for (int i = 0; i != n; ++i)
            for (int j = 0; j != m; ++j)
                if (c[i][j] == 'O' && c[i + 1][j] == 'O')
                    (col[i][j] ? S : T).push_back(n * m + i * m + j);
        std::for_each(to, to + n * m * 2, clear);
        for (auto v : T)
        {
            std::iota(F, F + n * m, 0);
            int cnt = ::cnt;
            for (auto i : T)
                if (i != v)
                {
                    int x = i % (n * m), y = i % (n * m) + (i < n * m ? 1 : m);
                    if (find(x) != find(y))
                        F[find(x)] = find(y), --cnt;
                }
            if (cnt == 1)
                X.push_back(v);
            for (auto i : S)
            {
                int x = i % (n * m), y = i % (n * m) + (i < n * m ? 1 : m);
                if (cnt == 1 || (find(x) != find(y) && cnt == 2))
                    to[i].push_back(v);
            }
        }
        for (auto v : T)
        {
            std::fill(F, F + n * m, 0);
            int cnt = 0;
            for (auto i : T)
                if (i != v)
                {
                    int x = i % (n * m), y = i % (n * m) + (i < n * m ? 1 : m);
                    if (x && !((x / m + x % m) & 1))
                        ++F[x];
                    if (y && !((y / m + y % m) & 1))
                        ++F[y];
                }
            for (int i = 0; i != n; ++i)
                for (int j = 0; j != m; ++j)
                    if (i + j && !((i + j) & 1) && F[i * m + j] == 1)
                        ++cnt;
            if (cnt == 0)
                Y.push_back(v);
            for (auto i : S)
            {
                int x = i % (n * m), y = i % (n * m) + (i < n * m ? 1 : m);
                if (cnt - (x && !((x / m + x % m) & 1) && F[x] == 1) - (y && !((y / m + y % m) & 1) && F[y] == 1) == 0)
                    to[v].push_back(i);
            }
        }
        std::fill(from, from + n * m * 2, -1);
        std::fill(in, in + n * m * 2, false);
        std::queue<int> que({X.begin(), X.end()});
        for (auto i : X)
            from[i] = 114514;
        for (auto i : Y)
            in[i] = true;
        while (!que.empty())
        {
            int now = que.front();
            que.pop();
            if (in[now])
            {
                while (now != 114514)
                {
                    int tmp = now;
                    auto t = tmp < n * m ? lin : col;
                    tmp %= n * m;
                    t[tmp / m][tmp % m] ^= true;
                    now = from[now];
                }
                flag = true;
                break;
            }
            for (auto i : to[now])
                if (!~from[i])
                    from[i] = now, que.push(i);
        }
        // for (int i = 0; i != n; ++i)
        // {
        //     for (int j = 0; j != m; ++j)
        //         std::cout << c[i][j] << (lin[i][j] ? " \n"[j + 1 == m] : 'O');
        //     for (int j = 0; j != m; ++j)
        //         std::cout << (col[i][j] ? ' ' : 'O') << " \n"[j + 1 == m];
        // }
    } while (flag);
}
int calc()
{
    int res = 0;
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            res += !lin[i][j] + !col[i][j];
    return res;
}
bool check()
{
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            if (i + j && !((i + j) & 1) && !lin[i][j] + (j && !lin[i][j - 1]) + !col[i][j] + (i && !col[i - 1][j]) == 1)
                return false;
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        memset(c, 0, sizeof(c));
        cnt = 0;
        for (int i = 0; i != n; ++i)
            for (int j = 0; j != m; ++j)
                std::cin >> c[i][j], cnt += c[i][j] == 'O';
        work();
        if (cnt - 1 == calc() && check())
        {
            std::cout << "YES" << std::endl;
            for (int i = 0; i != n; ++i)
            {
                for (int j = 0; j != m; ++j)
                    std::cout << c[i][j] << (lin[i][j] ? " \n"[j + 1 == m] : 'O');
                if (i + 1 != n)
                    for (int j = 0; j != m; ++j)
                        std::cout << (col[i][j] ? ' ' : 'O') << " \n"[j + 1 == m];
            }
        }
        else
            std::cout << "NO" << std::endl;
    }
    return 0;
}