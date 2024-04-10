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
std::string s;
struct node
{
    int lson, rson, max[205], min[205], siz;
    node() { std::fill(max, max + 205, -INF), std::fill(min, min + 205, +INF); }
} p[10005];
int root, cnt, lim[2];
bool d;
int build(std::string::iterator L, std::string::iterator R)
{
    int now = cnt++;
    if (*L != '(' && *R != ')')
    {
        p[now].max[0] = p[now].min[0] = *L - '0';
        return now;
    }
    ++L;
    --R;
    if (*L == '(')
    {
        std::string::iterator i = L;
        int v = 0;
        while (true)
        {
            if (*i == '(')
            {
                ++v;
            }
            if (*i == ')')
            {
                --v;
                if (!v)
                {
                    p[now].lson = build(L, i);
                    break;
                }
            }
            ++i;
        }
    }
    else
    {
        p[now].lson = build(L, L);
    }
    if (*R == ')')
    {
        std::string::iterator i = R;
        int v = 0;
        while (true)
        {
            if (*i == ')')
            {
                ++v;
            }
            if (*i == '(')
            {
                --v;
                if (!v)
                {
                    p[now].rson = build(i, R);
                    break;
                }
            }
            --i;
        }
    }
    else
    {
        p[now].rson = build(R, R);
    }
    p[now].siz = p[p[now].lson].siz + p[p[now].rson].siz + 1;
    return now;
}
void vis(int now)
{
    if (!p[now].lson && !p[now].rson)
        return void(std::cout << p[now].max[0]);
    std::cout << '(';
    vis(p[now].lson);
    std::cout << '?';
    vis(p[now].rson);
    std::cout << ')';
}
void dfs(int now)
{
    if (!p[now].lson && !p[now].rson)
        return;
    dfs(p[now].lson);
    dfs(p[now].rson);
    for (int i = 0; i <= lim[d] && i <= p[p[now].lson].siz; ++i)
        for (int j = 0; j <= lim[d] && j <= p[p[now].rson].siz; ++j)
        {
            p[now].max[i + j + !d] = std::max(p[now].max[i + j + !d], p[p[now].lson].max[i] + p[p[now].rson].max[j]);
            p[now].max[i + j + d] = std::max(p[now].max[i + j + d], p[p[now].lson].max[i] - p[p[now].rson].min[j]);
            p[now].min[i + j + !d] = std::min(p[now].min[i + j + !d], p[p[now].lson].min[i] + p[p[now].rson].min[j]);
            p[now].min[i + j + d] = std::min(p[now].min[i + j + d], p[p[now].lson].min[i] - p[p[now].rson].max[j]);
        }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    root = build(s.begin(), --s.end());
    // vis(root);
    // std::cout << std::endl;
    std::cin >> lim[0] >> lim[1];
    d = lim[0] > lim[1];
    dfs(root);
    std::cout << p[root].max[lim[d]];
    return 0;
}