// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, son[4005][12], fa[4005], v[4005], root, cnt, dp[1 << 12][4005];
std::string gg[1 << 12][4005], ss[4005];
void cmax(int &A, int B) { A = std::max(A, B); }
template <class iterator>
void insert(int &now, int c, iterator l, iterator r)
{
    if (!now)
        now = ++cnt;
    if (l == r)
        return void(v[now] += c);
    insert(son[now][*l], c, l + 1, r);
}
void dfs(int now = root, std::string cc = "")
{
    std::cout << now << ' ' << cc << std::endl;
    for (int i = 0; i != 12; ++i)
        if (son[now][i])
            dfs(son[now][i], cc + char('a' + i));
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        static int c;
        static std::string s;
        std::cin >> c >> s;
        std::deque<int> que;
        que.push_back(s.front() - 'a');
        if (s.size() == 1)
            insert(root, c, que.begin(), que.end());
        else
        {
            que.push_front(s[1] - 'a');
            std::deque<int>::iterator iter = que.begin();
            bool flag = true;
            for (std::size_t j = 2; j != s.size(); ++j)
            {
                int x = s[j] - 'a';
                if (iter != que.begin() && x == iter[-1])
                    --iter;
                else if (iter != --que.end() && x == iter[1])
                    ++iter;
                else if (std::count(que.begin(), que.end(), x))
                    flag = false;
                else if (iter == que.begin())
                    que.push_front(x), --iter;
                else if (iter == --que.end())
                    que.push_back(x), ++iter;
                else
                    flag = false;
            }
            if (flag)
            {
                // for (auto i : que)
                //     std::cout << char('a' + i);
                // std::cout << std::endl;
                insert(root, c, que.begin(), que.end());
                insert(root, c, que.rbegin(), que.rend());
            }
            // else
            //     std::cout << -1 << std::endl;
        }
    }
    if (!root)
    {
        std::cout << "abcdefghijkl" << std::endl;
        return 0;
    }
    // dfs();
    std::queue<int> que;
    for (int i = 0; i != 12; ++i)
        if (int &t = son[root][i])
            fa[t] = root, que.push(t);
        else
            t = root;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        v[now] += v[fa[now]];
        for (int i = 0; i != 12; ++i)
            if (int &t = son[now][i])
                fa[t] = son[fa[now]][i], que.push(t);
            else
                t = son[fa[now]][i];
    }
    // for (int i = 1; i <= cnt; ++i, std::cout << std::endl)
    // {
    //     std::cout << i;
    //     for (int j = 0; j != 12; ++j)
    //         std::cout << ' ' << son[i][j];
    // }
    std::memset(dp, 0xf0, sizeof(dp));
    dp[0][root] = 0;
    for (int i = 0; i != 1 << 12; ++i)
        for (int j = 1; j <= cnt; ++j)
            for (int k = 0; k != 12; ++k)
                if (~i >> k & 1 && dp[i | 1 << k][son[j][k]] < dp[i][j] + v[son[j][k]])
                {
                    dp[i | 1 << k][son[j][k]] = dp[i][j] + v[son[j][k]];
                    gg[i | 1 << k][son[j][k]] = gg[i][j] + char('a' + k);
                }
    // std::cout << dp[0b101101111011][35] << std::endl;
    int max = 0;
    for (int i = 1; i <= cnt; ++i)
        if (dp[(1 << 12) - 1][i] > dp[(1 << 12) - 1][max])
            max = i;
    std::cout << gg[(1 << 12) - 1][max] << std::endl;
    return 0;
}