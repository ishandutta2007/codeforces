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
enum Type
{
    Widget,
    VBox,
    HBox
} type[105];
int n, fa[105], width[105], height[105], border[105], spacing[105];
bool did[105];
std::vector<int> son[105];
std::map<std::string, int> map;
std::string str;
void dfs(int now)
{
    did[now] = true;
    if (type[now] == Widget || son[now].empty())
        return;
    else if (type[now] == VBox)
    {
        for (auto i : son[now])
        {
            if (!did[i])
                dfs(i);
            width[now] = std::max(width[now], width[i]);
            height[now] += height[i] + spacing[now];
        }
        width[now] += 2 * border[now];
        height[now] += 2 * border[now] - spacing[now];
    }
    else if (type[now] == HBox)
    {
        for (auto i : son[now])
        {
            if (!did[i])
                dfs(i);
            width[now] += width[i] + spacing[now];
            height[now] = std::max(height[now], height[i]);
        }
        width[now] += 2 * border[now] - spacing[now];
        height[now] += 2 * border[now];
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    memset(fa, -1, sizeof(fa));
    std::cin >> n;
    std::getline(std::cin, str);
    for (int i = 1; i <= n; ++i)
    {
        static int x, y;
        std::getline(std::cin, str);
        for (int i = 0; i != (int)str.size(); ++i)
            if (!isalpha(str[i]) && !isdigit(str[i]))
                str[i] = ' ';
        std::stringstream in(str);
        in >> str;
        if (str == "Widget")
        {
            in >> str >> x >> y;
            int now = map[str] = map.size();
            type[now] = Widget;
            width[now] = x;
            height[now] = y;
        }
        else if (str == "VBox")
        {
            in >> str;
            int now = map[str] = map.size();
            type[now] = VBox;
        }
        else if (str == "HBox")
        {
            in >> str;
            int now = map[str] = map.size();
            type[now] = HBox;
        }
        else
        {
            int A = map[str];
            in >> str;
            if (str == "pack")
            {
                in >> str;
                int B = map[str];
                son[A].push_back(B);
            }
            else if (str == "set")
            {
                in >> str;
                if (str == "border")
                {
                    in >> x;
                    border[A] = x;
                }
                else if (str == "spacing")
                {
                    in >> x;
                    spacing[A] = x;
                }
                else
                    return -1;
            }
            else
                return -1;
        }
    }
    for (auto i : map)
        if (!did[i.second])
            dfs(i.second);
    for (auto i : map)
        std::cout << i.first << ' ' << width[i.second] << ' ' << height[i.second] << std::endl;
    return 0;
}