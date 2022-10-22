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
int n, k, a[200005][5], m;
struct segmenttree
{
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
    struct node
    {
        int min, max;
    } t[1 << 19];
    void pushup(int now)
    {
        t[now].min = std::min(t[lson].min, t[rson].min);
        t[now].max = std::max(t[lson].max, t[rson].max);
    }
    template <class Function>
    void build(Function F, int now = 1, int l = 1, int r = n)
    {
        if (l == r)
            return void(t[now].max = t[now].min = F(l));
        build(F, lson, l, lmid);
        build(F, rson, rmid, r);
        pushup(now);
    }
    template <class Function>
    void modify(int pos, Function F, int now = 1, int l = 1, int r = n)
    {
        if (l == r)
            return void(t[now].max = t[now].min = F(l));
        if (pos <= lmid)
            modify(pos, F, lson, l, lmid);
        else
            modify(pos, F, rson, rmid, r);
        pushup(now);
    }
    int min(int L, int R, int now = 1, int l = 1, int r = n)
    {
        if (R < l || r < L)
            return +INF;
        if (L <= l && r <= R)
            return t[now].min;
        return std::min(min(L, R, lson, l, lmid), min(L, R, rson, rmid, r));
    }
    int max(int L, int R, int now = 1, int l = 1, int r = n)
    {
        if (R < l || r < L)
            return -INF;
        if (L <= l && r <= R)
            return t[now].max;
        return std::max(max(L, R, lson, l, lmid), max(L, R, rson, rmid, r));
    }
} t[1 << 5];
// constexpr int gcd(int A, int B)
// {
//     return B ? gcd(B, A % B) : A;
// }
// constexpr int check(int x){
//     for(int i=1;;i++)if(i*i==x)return i;
//     return 0;
// }
// constexpr int sss = gcd(100000,10100000000);
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j != k; ++j)
            std::cin >> a[i][j];
    for (int i = 0; i != 1 << k; ++i)
        t[i].build([&](const int &x)
                   {
                       int res = 0;
                       for (int j = 0; j != k; ++j)
                           res += a[x][j] * (i & 1 << j ? +1 : -1);
                       return res;
                   });
    // for (int i = 1; i <= n; ++i)
    //     std::cout << t[0].max(i, i) << " \n"[i == n];
    std::cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        static int opt, A, B, x;
        std::cin >> opt;
        switch (opt)
        {
        case 1:
            std::cin >> x;
            for (int j = 0; j != k; ++j)
                std::cin >> a[x][j];
            for (int j = 0; j != 1 << k; ++j)
                t[j].modify(x, [&](const int &y)
                            {
                                int res = 0;
                                for (int l = 0; l != k; ++l)
                                    res += a[y][l] * (j & 1 << l ? +1 : -1);
                                return res;
                            });
            break;
        case 2:
            std::cin >> A >> B;
            x = 0;
            for (int j = 0; j != 1 << k; ++j)
                x = std::max(x, t[j].max(A, B) - t[j].min(A, B));
            std::cout << x << std::endl;
            break;
        }
    }
    return 0;
}