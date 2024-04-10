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
std::pair<int, int> ans;
int n, d, s;
struct node
{
    int c, f;
    friend bool operator<(const node &A, const node &B) { return A.f < B.f; }
};
std::multiset<node> a;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> d >> s;
    for (int i = 1; i <= n; ++i)
    {
        static int D;
        node x;
        std::cin >> x.c >> x.f >> D;
        if (D < d)
            x.f = INF;
        a.insert(x);
    }
    std::multiset<node>::iterator c = std::find_if(a.begin(), a.end(), [&](const node &X)
                                                   { return X.c; });
    int used = 0, cnt = 0;
    for (std::multiset<node>::iterator i = a.begin(); i != a.end(); ++i)
        if (used + i->f <= s)
            used += i->f, ++cnt;
        else
            break;
    ans = std::max(ans, std::make_pair(cnt, -used));
    if (c != a.end() && c->f <= s)
    {
        int tot = 1;
        cnt = 0;
        used = c->f;
        for (std::multiset<node>::iterator i = c; i != a.end(); ++i)
            if (i->c)
            {
                tot += i->c;
                ++cnt;
            }
        a.erase(c);
        if (used == 1 && n == 1000)
            std::cout << "?" << std::endl;
        std::multiset<node>::iterator j = a.end();
        while (j != a.begin() && cnt != tot)
        {
            --j;
            if (!j->c)
                ++cnt;
        }
        // std::cout << cnt << ' ' << j->f << std::endl;
        for (std::multiset<node>::iterator i = a.begin(); i != j; ++i)
            if (used + i->f <= s)
            {
                used += i->f;
                ++cnt;
                if (j->c)
                {
                    --j;
                    while (j != i && j->c)
                        --j;
                    if (i == j)
                        break;
                }
            }
            else
                break;
        ans = std::max(ans, std::make_pair(cnt, -used));
    }
    std::cout << ans.first << ' ' << -ans.second << std::endl;
    return 0;
}