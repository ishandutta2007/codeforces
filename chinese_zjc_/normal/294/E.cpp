//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, a[5005], b[5005], v[5005], belong[5005], sum[5005], s[5005], siz[5005], ans = INF;
std::vector<int> son[5005];
void dfs1(int now, int no, int root)
{
    belong[now] = root;
    s[now] = 0;
    siz[now] = 1;
    for (auto i : son[now])
    {
        if (i == no)
            continue;
        int to = a[i] ^ b[i] ^ now;
        dfs1(to, i, root);
        siz[now] += siz[to];
        s[now] += siz[to] * v[i] + s[to];
    }
}
void dfs2(int now, int no, int dis, int root)
{
    sum[now] = s[now] + dis;
    for (auto i : son[now])
    {
        if (i == no)
            continue;
        int to = a[i] ^ b[i] ^ now;
        dfs2(to, i, dis + s[now] - s[to] + (siz[root] - siz[to] * 2) * v[i], root);
    }
}
void work(int now, int no)
{
    dfs1(now, no, now);
    dfs2(now, no, 0, now);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i < n; ++i)
    {
        std::cin >> a[i] >> b[i] >> v[i];
        son[a[i]].push_back(i);
        son[b[i]].push_back(i);
    }
    for (int i = 1; i < n; ++i)
    {
        work(a[i], i);
        work(b[i], i);
        int A = a[i], B = b[i], tmp = 0;
        for (int j = 1; j <= n; ++j)
        {
            tmp += sum[j];
            if (belong[j] == a[i] && (sum[A] > sum[j]))
                A = j;
            if (belong[j] == b[i] && (sum[B] > sum[j]))
                B = j;
        }
        tmp /= 2;
        // for (int j = 1; j <= n; ++j)
        //     std::cout << sum[j] << " \n"[j == n];
        // std::cout << tmp << std::endl;
        // std::cout << sum[A] << ' ' << sum[B] << std::endl;
        // std::cout << tmp + siz[a[i]] * sum[B] + siz[b[i]] * sum[A] + siz[a[i]] * siz[b[i]] * v[i] << std::endl;
        ans = std::min(ans, tmp + siz[a[i]] * sum[B] + siz[b[i]] * sum[A] + siz[a[i]] * siz[b[i]] * v[i]);
    }
    std::cout << ans << std::endl;
    return 0;
}