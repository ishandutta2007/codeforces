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
struct hero
{
    int s, h, p;
    friend bool operator<(const hero &A, const hero &B) { return A.s < B.s; }
} h[105];
int n, m, v[105];
void work(int pos)
{
    int mid = std::lower_bound(h + 1, h + 1 + m, hero{pos, 0}) - h;
    int tmp[105];
    std::vector<int> frt, lst;

    bool flag = true;
    std::copy(v + 1, v + 1 + n, tmp + 1);
    for (int i = mid - 1; i >= 1; --i)
    {
        int hp = h[i].h;
        for (int j = h[i].s; j <= pos; ++j)
        {
            hp += tmp[j];
            if (hp < 0)
                break;
        }
        if (hp < 0)
            lst.push_back(i);
        else
            std::fill(tmp + h[i].s, tmp + 1 + pos, 0), frt.push_back(i);
    }
    for (int i = mid; i <= m; ++i)
    {
        int hp = h[i].h;
        for (int j = h[i].s; j >= pos; --j)
        {
            hp += tmp[j];
            if (hp < 0)
                break;
        }
        if (hp < 0)
            lst.push_back(i);
        else
            std::fill(tmp + pos, tmp + 1 + h[i].s, 0), frt.push_back(i);
    }
    for (auto i : lst)
    {
        if (h[i].s <= pos)
        {
            int hp = h[i].h;
            for (int j = h[i].s; j <= pos; ++j)
            {
                hp += tmp[j];
                if (hp < 0)
                    break;
            }
            if (hp < 0)
                flag = false;
        }
        else
        {
            int hp = h[i].h;
            for (int j = h[i].s; j >= pos; --j)
            {
                hp += tmp[j];
                if (hp < 0)
                    break;
            }
            if (hp < 0)
                flag = false;
        }
    }
    if (flag)
    {
        std::cout << pos << std::endl;
        for (auto i : frt)
            std::cout << h[i].p << ' ';
        for (auto i : lst)
            std::cout << h[i].p << ' ';
        std::cout << std::endl;
        exit(0);
    }

    frt.clear();
    lst.clear();
    flag = true;
    std::copy(v + 1, v + 1 + n, tmp + 1);
    for (int i = mid; i <= m; ++i)
    {
        int hp = h[i].h;
        for (int j = h[i].s; j >= pos; --j)
        {
            hp += tmp[j];
            if (hp < 0)
                break;
        }
        if (hp < 0)
            lst.push_back(i);
        else
            std::fill(tmp + pos, tmp + 1 + h[i].s, 0), frt.push_back(i);
    }
    for (int i = mid - 1; i >= 1; --i)
    {
        int hp = h[i].h;
        for (int j = h[i].s; j <= pos; ++j)
        {
            hp += tmp[j];
            if (hp < 0)
                break;
        }
        if (hp < 0)
            lst.push_back(i);
        else
            std::fill(tmp + h[i].s, tmp + 1 + pos, 0), frt.push_back(i);
    }
    for (auto i : lst)
    {
        if (h[i].s <= pos)
        {
            int hp = h[i].h;
            for (int j = h[i].s; j <= pos; ++j)
            {
                hp += tmp[j];
                if (hp < 0)
                    break;
            }
            if (hp < 0)
                flag = false;
        }
        else
        {
            int hp = h[i].h;
            for (int j = h[i].s; j >= pos; --j)
            {
                hp += tmp[j];
                if (hp < 0)
                    break;
            }
            if (hp < 0)
                flag = false;
        }
    }
    if (flag)
    {
        std::cout << pos << std::endl;
        for (auto i : frt)
            std::cout << h[i].p << ' ';
        for (auto i : lst)
            std::cout << h[i].p << ' ';
        std::cout << std::endl;
        exit(0);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        std::cin >> h[i].s >> h[i].h, h[i].p = i;
    std::sort(h + 1, h + 1 + m);
    for (int i = 1; i <= n; ++i)
        std::cin >> v[i];
    for (int i = 1; i <= n; ++i)
        work(i);
    std::cout << -1 << std::endl;
    return 0;
}