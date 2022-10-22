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
int n, m, sum;
struct node
{
    int p, d;
    friend bool operator<(const node &A, const node &B) { return A.d < B.d; }
};
std::vector<node> a;
bool check_odd(const node &val) { return val.d & 1; }
bool check_is1(const node &val) { return val.d == 1; }
void connect(std::vector<node>::iterator A, std::vector<node>::iterator B)
{
    std::cout << 2 << ' ' << A->p << ' ' << B->p << std::endl;
    --A->d;
    --B->d;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i != n; ++i)
    {
        std::cin >> a[i].d;
        sum += a[i].d;
        if (!a[i].d)
            return std::cout << -1 << std::endl, 0;
        a[i].p = i + 1;
    }
    if (a.size() == 2 && std::count_if(a.begin(), a.end(), check_is1) == 2)
        return std::cout << 1 << std::endl, connect(a.begin(), --a.end()), 0;
    if (sum & 1)
        return std::cout << -1 << std::endl, 0;
    m = sum / 2;
    if (m - (n - 1) < 0 || 2 * (m - (n - 1)) > n - 1 -
                                                   std::max(std::count_if(a.begin(), a.end(), check_odd) / 2,
                                                            std::count_if(a.begin(), a.end(), check_is1)))
        return std::cout << -1 << std::endl, 0;
    std::cout << m << std::endl;
    while (!a.empty())
    {
        if (a.size() == 2 && std::count_if(a.begin(), a.end(), check_is1) == 2)
            return connect(a.begin(), --a.end()), 0;
        std::vector<node>::iterator x = std::min_element(a.begin(), a.end()), nxt;
        switch (x->d)
        {
        case 1:
            nxt = std::max_element(a.begin(), a.end());
            for (std::vector<node>::iterator i = a.begin(); i != a.end(); ++i)
                if (i->d != 1 && i->d & 1)
                    nxt = i;
            connect(x, nxt);
            break;
        case 2:
            nxt = std::max_element(a.begin(), a.end());
            if (nxt->d == 2)
                for (int i = 0; i != a.size(); ++i)
                    connect(a.begin() + i, a.begin() + (i + 1) % a.size());
            else
            {
                std::vector<node>::iterator y = x;
                do
                    ++y;
                while (y->d != 2);
                connect(x, y);
                connect(x, nxt);
                connect(y, nxt);
            }
            break;
        }
        for (std::vector<node>::iterator i = a.begin(); i != a.end(); ++i)
            if (!i->d)
                a.erase(i--);
    }
    return 0;
}