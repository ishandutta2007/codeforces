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
int n, lim, x[100005], y[100005], rkx[100005], rky[100005], ans = INF;
int pulled[100005];
struct cmpx
{
    bool operator()(const int &A, const int &B) { return x[A] < x[B]; }
};
struct cmpy
{
    bool operator()(const int &A, const int &B) { return y[A] < y[B]; }
};
std::map<int, std::vector<int>> X;
std::map<int, std::vector<int>> Y;
std::multiset<int> ax, ay;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> lim;
    for (int i = 1; i <= n; ++i)
    {
        static int sx, sy, ex, ey;
        std::cin >> sx >> sy >> ex >> ey;
        x[i] = sx + ex;
        y[i] = sy + ey;
        X[x[i]].push_back(i);
        Y[y[i]].push_back(i);
        ax.insert(x[i]);
        ay.insert(y[i]);
    }
    int used = 0;
    for (auto i = X.begin(); true; ++i)
    {
        for (auto j = Y.begin(); true; ++j)
        {
            for (auto k = X.rbegin(); true; ++k)
            {
                for (auto l = Y.rbegin(); true; ++l)
                {
                    ans = std::min(ans, std::max(1ll, (*ax.rbegin() - *ax.begin() + 1) / 2) *
                                            std::max(1ll, (*ay.rbegin() - *ay.begin() + 1) / 2));
                    for (auto o : l->second)
                    {
                        if (!pulled[o])
                        {
                            ++used;
                            pulled[o] = 4;
                            ax.erase(ax.find(x[o]));
                            ay.erase(ay.find(y[o]));
                        }
                        if (used > lim)
                            break;
                    }
                    if (used > lim)
                    {
                        while (true)
                        {
                            for (auto o : l->second)
                            {
                                if (pulled[o] == 4)
                                {
                                    --used;
                                    pulled[o] = 0;
                                    ax.insert(x[o]);
                                    ay.insert(y[o]);
                                }
                            }
                            if (l == Y.rbegin())
                                break;
                            else
                                --l;
                        }
                        break;
                    }
                }
                for (auto o : k->second)
                {
                    if (!pulled[o])
                    {
                        ++used;
                        pulled[o] = 3;
                        ax.erase(ax.find(x[o]));
                        ay.erase(ay.find(y[o]));
                    }
                    if (used > lim)
                        break;
                }
                if (used > lim)
                {
                    while (true)
                    {
                        for (auto o : k->second)
                        {
                            if (pulled[o] == 3)
                            {
                                --used;
                                pulled[o] = 0;
                                ax.insert(x[o]);
                                ay.insert(y[o]);
                            }
                        }
                        if (k == X.rbegin())
                            break;
                        else
                            --k;
                    }
                    break;
                }
            }
            for (auto o : j->second)
            {
                if (!pulled[o])
                {
                    ++used;
                    pulled[o] = 2;
                    ax.erase(ax.find(x[o]));
                    ay.erase(ay.find(y[o]));
                }
                if (used > lim)
                    break;
            }
            if (used > lim)
            {
                while (true)
                {
                    for (auto o : j->second)
                    {
                        if (pulled[o] == 2)
                        {
                            --used;
                            pulled[o] = 0;
                            ax.insert(x[o]);
                            ay.insert(y[o]);
                        }
                    }
                    if (j == Y.begin())
                        break;
                    else
                        --j;
                }
                break;
            }
        }
        for (auto o : i->second)
        {
            if (!pulled[o])
            {
                ++used;
                pulled[o] = 1;
                ax.erase(ax.find(x[o]));
                ay.erase(ay.find(y[o]));
            }
            if (used > lim)
                break;
        }
        if (used > lim)
        {
            while (true)
            {
                for (auto o : i->second)
                {
                    if (pulled[o] == 1)
                    {
                        --used;
                        pulled[o] = 0;
                        ax.insert(x[o]);
                        ay.insert(y[o]);
                    }
                }
                if (i == X.begin())
                    break;
                else
                    --i;
            }
            break;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}