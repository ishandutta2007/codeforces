#include <cstdio>
#include <cstdlib>
#include <cmath>
  
#include <vector>
#include <set>
#include <queue>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
  
typedef long long ll;

const int modulo = 1e9 + 9;
const int max_n = 3e5 + 10;

inline int msum(int a, int b)
{
    a += b;
    if (a >= modulo) a -= modulo;
    return a;
}

struct matr2
{
    int a[2][2];
};

matr2 mult2(const matr2&a, const matr2& b)
{
    matr2 res;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            res.a[i][j] = 0;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                res.a[i][j] = msum(res.a[i][j], (1LL * a.a[i][k] * b.a[k][j]) % modulo);
    return res;
}

matr2 m2[max_n];

struct matr3
{
    int a[3][3];
};

matr3 mult3(const matr3& a, const matr3& b)
{
    matr3 res;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            res.a[i][j] = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                res.a[i][j] = msum(res.a[i][j], (1LL * a.a[i][k] * b.a[k][j]) % modulo);
    return res;
}

matr3 m3[max_n];

int n, m;
int a[max_n];

pair<int, int> op[4 * max_n];
int s[4 * max_n];

pair<int, int> get_mth_elem(pair<int, int> op, int m)
{
    pair<int, int> nop;
    
    nop.first = (1LL * op.first * m2[m].a[0][0]) % modulo;
    nop.first = msum(nop.first, (1LL * op.second * m2[m].a[1][0]) % modulo);
    
    nop.second = (1LL * op.first * m2[m].a[0][1]) % modulo;
    nop.second = msum(nop.second, (1LL * op.second * m2[m].a[1][1]) % modulo);
    
    return nop;
}

int get_sum(pair<int, int> op, int len)
{
    if (len == 1) 
        return op.first;
    if (len == 2) {
        return msum(op.first, op.second);
    }
    int S0 = msum(op.first, op.second);
    int S = (1LL * S0 * m3[len - 2].a[0][0]) % modulo;
    S = msum(S, (1LL * op.first * m3[len - 2].a[1][0]) % modulo);
    S = msum(S, (1LL * op.second * m3[len - 2].a[2][0]) % modulo);
    return S;
}

void build(int v, int tl, int tr)
{
    if (tl == tr) {
        op[v].first = a[tl];
        op[v].second = 0;
        s[v] = 0;
    } else {
        int tm = (tl + tr) >> 1;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        op[v].first = op[v].second = 0;
        s[v] = msum(msum(s[2 * v], s[2 * v + 1]), msum(op[2 * v].first, op[2 * v + 1].first));
    }
}

int get(int v, int tl, int tr, int l, int r)
{
    if (tl == l && tr == r) {
        return msum(get_sum(op[v], tr - tl + 1), s[v]);
    } else {
        int res = get_sum(get_mth_elem(op[v], l - tl), r - l + 1);
        int tm = (tl + tr) >> 1;
        if (r <= tm)
            res = msum(res, get(2 * v, tl, tm, l, r));
        else if (l > tm)
            res = msum(res, get(2 * v + 1, tm + 1, tr, l, r));
        else {
            res = msum(res, msum(get(2 * v, tl, tm, l, tm), get(2 * v + 1, tm + 1, tr, tm + 1, r)));
        }
        return res;
    }
}

void update(int v, int tl, int tr, int l, int r, pair<int, int> cop)
{
    if (tl == l && tr == r) {
        op[v].first = msum(op[v].first, cop.first);
        op[v].second = msum(op[v].second, cop.second);
    } else {
        int tm = (tl + tr) >> 1;
        if (r <= tm) 
            update(2 * v, tl, tm, l, r, cop);
        else if (l > tm)
            update(2 * v + 1, tm + 1, tr, l, r, cop);
        else {
            update(2 * v, tl, tm, l, tm, cop);
            update(2 * v + 1, tm + 1, tr, tm + 1, r, get_mth_elem(cop, tm + 1 - l));
        }
        s[v] = msum(s[v], get_sum(cop, r - l + 1));
    }
}    

int main()
{
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            if (i == j) {
                m2[0].a[i][j] = 1;
            } else {
                m2[0].a[i][j] = 0;
            }
    m2[1].a[0][0] = 0;
    m2[1].a[0][1] = 1;
    m2[1].a[1][0] = 1;
    m2[1].a[1][1] = 1;
    for (int i = 2; i < max_n; ++i)
        m2[i] = mult2(m2[i - 1], m2[1]);
        
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (i == j) {
                m3[0].a[i][j] = 1;
            } else {
                m3[0].a[i][j] = 0;
            }
    m3[1].a[0][0] = 1;
    m3[1].a[0][1] = 0;
    m3[1].a[0][2] = 0;
    m3[1].a[1][0] = 1;
    m3[1].a[1][1] = 0;
    m3[1].a[1][2] = 1;
    m3[1].a[2][0] = 1;
    m3[1].a[2][1] = 1;
    m3[1].a[2][2] = 1;
    for (int i = 2; i < max_n; ++i)
        m3[i] = mult3(m3[i - 1], m3[1]);
        
 //   freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
        
    build(1, 0, n - 1);
    
    for (int i = 0; i < m; ++i) {
        int tp, l, r;
        scanf("%d%d%d", &tp, &l, &r);
        --l; --r;
        if (tp == 1) {
            update(1, 0, n - 1, l, r, make_pair(1, 1));
        } else {
            printf("%d\n", get(1, 0, n - 1, l, r));
        }
    }

    return 0;
}