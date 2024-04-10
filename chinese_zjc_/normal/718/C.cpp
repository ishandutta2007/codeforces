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
const int MOD = 1000000007;
struct vector
{
    int v[2];
    vector() { v[0] = v[1] = 0; }
    int &operator()(const int &X) { return v[X]; }
    const int &operator()(const int &X) const { return v[X]; }
    friend vector operator+(const vector &A, const vector &B)
    {
        vector res;
        for (int i = 0; i != 2; ++i)
            res(i) = (A(i) + B(i)) % MOD;
        return res;
    }
} sum[1 << 18];
struct matrix
{
    int v[2][2];
    matrix() { v[0][0] = v[0][1] = v[1][0] = v[1][1] = 0; }
    int &operator()(const int &A, const int &B) { return v[A][B]; }
    const int &operator()(const int &A, const int &B) const { return v[A][B]; }
    void init() { v[0][0] = v[1][1] = 1, v[1][0] = v[0][1] = 0; }
    friend matrix operator*(const matrix &A, const matrix &B)
    {
        matrix res;
        for (int i = 0; i != 2; ++i)
            for (int j = 0; j != 2; ++j)
                for (int k = 0; k != 2; ++k)
                    res(i, j) = (res(i, j) + A(i, k) * B(k, j)) % MOD;
        return res;
    }
    friend matrix power(matrix A, int B)
    {
        matrix res;
        res.init();
        while (B)
        {
            if (B & 1)
                res = res * A;
            B >>= 1;
            A = A * A;
        }
        return res;
    }
    friend vector operator*(const vector &A, const matrix &B)
    {
        vector res;
        for (int i = 0; i != 2; ++i)
            for (int j = 0; j != 2; ++j)
                res(i) = (res(i) + A(j) * B(j, i)) % MOD;
        return res;
    }
} cha, tag[1 << 18];
vector get(int x)
{
    vector res;
    res(0) = 1;
    return res * power(cha, x);
}
int n, m, a[100005];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void pushup(int now)
{
    sum[now] = sum[lson] + sum[rson];
}
void pushdown(int now)
{
    sum[lson] = sum[lson] * tag[now];
    sum[rson] = sum[rson] * tag[now];
    tag[lson] = tag[lson] * tag[now];
    tag[rson] = tag[rson] * tag[now];
    tag[now].init();
}
void build(int now = 1, int l = 1, int r = n)
{
    tag[now].init();
    if (l == r)
    {
        sum[now] = get(a[l] - 1);
        return;
    }
    build(lson, l, lmid);
    build(rson, rmid, r);
    pushup(now);
}
void add(int L, int R, matrix val, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return;
    if (L <= l && r <= R)
    {
        sum[now] = sum[now] * val;
        tag[now] = tag[now] * val;
        return;
    }
    pushdown(now);
    add(L, R, val, lson, l, lmid);
    add(L, R, val, rson, rmid, r);
    pushup(now);
}
vector query(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return vector();
    if (L <= l && r <= R)
        return sum[now];
    pushdown(now);
    return query(L, R, lson, l, lmid) + query(L, R, rson, rmid, r);
}
#undef lson
#undef rson
#undef lmid
#undef rmid
signed main()
{
    std::ios::sync_with_stdio(false);
    cha(0, 0) = cha(0, 1) = cha(1, 0) = 1;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    build();
    for (int i = 1; i <= m; ++i)
    {
        static int opt, l, r, x;
        std::cin >> opt >> l >> r;
        switch (opt)
        {
        case 1:
            std::cin >> x;
            add(l, r, power(cha, x));
            break;
        case 2:
            std::cout << query(l, r)(0) << std::endl;
            break;
        }
        // std::cout << query(4, 4)(0) << ' ' << query(5, 5)(0) << std::endl;
        // std::cout << cha(0, 0) << ' ' << cha(0, 1) << std::endl;
        // std::cout << cha(1, 0) << ' ' << cha(1, 1) << std::endl;
    }
    return 0;
}