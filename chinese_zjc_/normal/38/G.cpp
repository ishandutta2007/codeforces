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
struct Splay
{
    struct node
    {
        int son[2], fa, max, siz, Maxtag;
    } t[100005];
    int cnt = 0, root;
    int query_son(int now) { return t[t[now].fa].son[0] == now ? 0 : (t[t[now].fa].son[1] == now ? 1 : -1); }
    void connect(int fa, int son, bool side)
    {
        if (fa)
            t[fa].son[side] = son;
        if (son)
            t[son].fa = fa;
    }
    void rotate(int now)
    {
        bool side = query_son(now);
        int fa = t[now].fa;
        connect(t[fa].fa, now, query_son(fa));
        connect(fa, t[now].son[!side], side);
        connect(now, fa, !side);
        pushup(fa);
        pushup(now);
    }
    void init_splay(int now)
    {
        if (t[now].fa)
            init_splay(t[now].fa);
        pushdown(now);
    }
    void splay(int now)
    {
        init_splay(now);
        for (; ~query_son(now); rotate(now))
            if (query_son(now) == query_son(t[now].fa))
                rotate(t[now].fa);
        root = now;
    }
    void pushup(int now)
    {
        t[now].siz = t[t[now].son[0]].siz + t[t[now].son[1]].siz + 1;
    }
    void pushdown(int now)
    {
        if (t[now].Maxtag)
        {
            if (t[now].son[0])
            {
                t[t[now].son[0]].max = std::max(t[t[now].son[0]].max, t[now].Maxtag);
                t[t[now].son[0]].Maxtag = std::max(t[t[now].son[0]].Maxtag, t[now].Maxtag);
            }
            if (t[now].son[1])
            {
                t[t[now].son[1]].max = std::max(t[t[now].son[1]].max, t[now].Maxtag);
                t[t[now].son[1]].Maxtag = std::max(t[t[now].son[1]].Maxtag, t[now].Maxtag);
            }
            t[now].Maxtag = 0;
        }
    }
    int pre(int now)
    {
        splay(now);
        pushdown(now);
        now = t[now].son[0];
        while (t[now].son[1])
            pushdown(now), now = t[now].son[1];
        return now;
    }
    void insert(int rk, int val)
    {
        if (cnt)
        {
            insert_(root, rk, val);
            splay(cnt);
            t[cnt].max = std::max(t[cnt].max, t[pre(cnt)].max);
            if (t[cnt].son[1])
            {
                t[t[cnt].son[1]].max = std::max(t[t[cnt].son[1]].max, val);
                t[t[cnt].son[1]].Maxtag = std::max(t[t[cnt].son[1]].Maxtag, val);
            }
        }
        else
        {
            root = ++cnt;
            t[cnt].max = val;
            t[cnt].siz = 1;
        }
    }
    void insert_(int now, int rk, int val)
    {
        // std::cout << ": " << now << ' ' << t[now].max << std::endl;
        pushdown(now);
        if (t[now].max > val || t[t[now].son[0]].siz >= rk)
        {
            if (t[now].son[0])
                insert_(t[now].son[0], rk, val);
            else
            {
                connect(now, ++cnt, 0);
                t[cnt].max = val;
                t[cnt].siz = 1;
            }
        }
        else
        {
            if (t[now].son[1])
                insert_(t[now].son[1], rk - t[t[now].son[0]].siz - 1, val);
            else
            {
                connect(now, ++cnt, 1);
                t[cnt].max = val;
                t[cnt].siz = 1;
            }
        }
        pushup(now);
    }
    void print_(int now)
    {
        if (t[now].son[1])
            print_(t[now].son[1]);
        std::cout << now << ' ';
        if (t[now].son[0])
            print_(t[now].son[0]);
    }
    void print() { print_(root), std::cout << std::endl; }
} S;
int n;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        static int rk, val;
        std::cin >> val >> rk;
        S.insert(rk, val);
    }
    S.print();
    return 0;
}