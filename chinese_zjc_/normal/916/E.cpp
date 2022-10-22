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
#define getchar myGetchar
#define putchar myPutchar
namespace IO
{
    static const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;

    inline char myGetchar()
    {
        static char buf[IN_BUF], *ps = buf, *pt = buf;
        if (ps == pt)
        {
            ps = buf, pt = buf + fread(buf, 1, IN_BUF, stdin);
        }
        return ps == pt ? EOF : *ps++;
    }

    template <typename T>
    inline void read(T &x)
    {
        bool op = 0;
        char ch = getchar();
        x = 0;
        for (; !isdigit(ch); ch = getchar())
            op ^= (ch == '-');
        for (; isdigit(ch); ch = getchar())
            x = x * 10 + (ch - '0');
        x = op ? -x : x;
    }

    template <class T, class... Args>
    void read(T &__Val, Args &...args)
    {
        read(__Val);
        read(args...);
    }

    inline int readStr(char *s)
    {
        int n = 0;
        char ch = getchar();
        for (; isspace(ch) && ch != EOF; ch = getchar())
            ;
        for (; !isspace(ch) && ch != EOF; ch = getchar())
        {
            s[n++] = ch;
        }
        s[n] = '\0';
        return n;
    }

    inline void myPutchar(char x)
    {
        static char pbuf[OUT_BUF], *pp = pbuf;
        struct _flusher
        {
            ~_flusher()
            {
                fwrite(pbuf, 1, pp - pbuf, stdout);
            }
        };
        static _flusher outputFlusher;
        if (pp == pbuf + OUT_BUF)
        {
            fwrite(pbuf, 1, OUT_BUF, stdout);
            pp = pbuf;
        }
        *pp++ = x;
    }

    template <typename T>
    inline void print_(T x)
    {
        if (x == 0)
        {
            putchar('0');
            return;
        }
        static int num[40];
        if (x < 0)
        {
            putchar('-');
            x = -x;
        }
        for (*num = 0; x; x /= 10)
        {
            num[++*num] = x % 10;
        }
        while (*num)
        {
            putchar(num[*num] ^ '0');
            --*num;
        }
    }

    template <typename T>
    inline void print(T x, char ch = '\n')
    {
        print_(x);
        putchar(ch);
    }

    inline void printStr_(const char *s, int n = -1)
    {
        if (n == -1)
        {
            n = strlen(s);
        }
        for (int i = 0; i < n; ++i)
        {
            putchar(s[i]);
        }
    }

    inline void printStr(const char *s, int n = -1, char ch = '\n')
    {
        printStr_(s, n);
        putchar(ch);
    }
}

int n, v[300005], in[300005], out[300005], dfn[300005], siz[300005],
    depth[300005], fa[300005], ol[600005], ST[20][600005], q, root = 1, lg[600005];
std::vector<int> son[300005], app[300005];
void init(int now)
{
    static int cnt = 0, cnto = 0;
    dfn[in[now] = ++cnt] = now;
    ol[++cnto] = now;
    app[now].push_back(cnto);
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        if (fa[now] == son[now][i])
        {
            std::swap(son[now][i--], son[now].back());
            son[now].pop_back();
            continue;
        }
        fa[son[now][i]] = now;
        depth[son[now][i]] = depth[now] + 1;
        init(son[now][i]);
        ol[++cnto] = now;
        app[now].push_back(cnto);
        siz[now] += siz[son[now][i]];
    }
    out[now] = cnt;
}
bool init(int fa, int son) { return in[fa] <= in[son] && in[son] <= out[fa]; }
int tag[1 << 20], sum[1 << 20];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
inline void pushup(int now)
{
    sum[now] = sum[lson] + sum[rson];
}
inline void pushdown(int now, int l, int r)
{
    if (tag[now])
    {
        sum[lson] += tag[now] * (lmid - l + 1);
        tag[lson] += tag[now];
        sum[rson] += tag[now] * (r - rmid + 1);
        tag[rson] += tag[now];
        tag[now] = 0;
    }
}
void build(int now = 1, int l = 1, int r = n)
{
    if (l == r)
        return void(sum[now] = v[dfn[l]]);
    build(lson, l, lmid);
    build(rson, rmid, r);
    pushup(now);
}
void add(int L, int R, int val, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return;
    if (L <= l && r <= R)
    {
        tag[now] += val;
        sum[now] += val * (r - l + 1);
        return;
    }
    pushdown(now, l, r);
    add(L, R, val, lson, l, lmid);
    add(L, R, val, rson, rmid, r);
    pushup(now);
}
int s(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return 0;
    if (L <= l && r <= R)
        return sum[now];
    pushdown(now, l, r);
    int res = s(L, R, lson, l, lmid) + s(L, R, rson, rmid, r);
    pushup(now);
    return res;
}
bool cmp(const int &A, const int &B) { return depth[ol[A]] < depth[ol[B]]; }
int LCA(int A, int B)
{
    A = app[A].front();
    B = app[B].front();
    if (A > B)
        std::swap(A, B);
    int len = lg[B - A + 1];
    return ol[std::min(ST[len][A], ST[len][B - (1 << len) + 1], cmp)];
}
int dis(int A, int B) { return depth[A] + depth[B] - depth[LCA(A, B)] * 2; }
signed main()
{
    IO::read(n, q);
    for (int i = 1; i <= n; ++i)
        IO::read(v[i]);
    for (int i = 1; i < n; ++i)
    {
        static int a, b;
        IO::read(a, b);
        son[a].push_back(b);
        son[b].push_back(a);
    }
    depth[1] = 1;
    init(1);
    for (int i = 2; i <= n * 2 - 1; ++i)
        lg[i] = lg[i - 1] + !(i & (i - 1));
    for (int i = 1; i <= 2 * n - 1; ++i)
        ST[0][i] = i;
    for (int i = 1; 1 << i <= 2 * n - 1; ++i)
        for (int j = 1; j <= 2 * n - (1 << i); ++j)
            ST[i][j] = std::min(ST[i - 1][j], ST[i - 1][j + (1 << i >> 1)], cmp);
    build();
    for (int T = 1; T <= q; ++T)
    {
        static int opt, a, b[3], c, lca[3];
        IO::read(opt);
        switch (opt)
        {
        case 1:
            IO::read(a);
            root = a;
            break;
        case 2:
            IO::read(b[0], b[1], c);
            b[2] = root;
            for (int i = 0; i != 3; ++i)
                lca[i] = LCA(b[i], b[(i + 1) % 3]);
            for (int i = 0; i != 3; ++i)
            {
                if (depth[lca[i]] >= depth[lca[0]] && depth[lca[i]] >= depth[lca[1]] && depth[lca[i]] >= depth[lca[2]])
                {
                    if (lca[i] == root)
                        add(1, n, c);
                    else if (init(lca[i], root))
                    {
                        int son = ol[*std::upper_bound(app[lca[i]].begin(), app[lca[i]].end(), app[root].front()) - 1];
                        add(1, n, c);
                        add(in[son], out[son], -c);
                    }
                    else
                        add(in[lca[i]], out[lca[i]], c);
                    break;
                }
            }
            break;
        case 3:
            IO::read(a);
            if (a == root)
                IO::print(s(1, n));
            else if (init(a, root))
            {
                int son = ol[*std::upper_bound(app[a].begin(), app[a].end(), app[root].front()) - 1];
                IO::print(s(1, n) - s(in[son], out[son]));
            }
            else
                IO::print(s(in[a], out[a]));
            break;
        }
    }
    return 0;
}