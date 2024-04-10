// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
struct node
{
    node *lson, *rson;
    int x, y, cnt, tag;
    node() : lson(), rson(), x(), y(), cnt(), tag() {}
    void pushup(int d)
    {
        x = 0;
        y = 0;
        cnt = 0;
        if (lson)
        {
            x |= lson->x;
            y |= lson->y;
            x |= 1 << d >> 1;
            cnt += lson->cnt;
        }
        if (rson)
        {
            x |= rson->x;
            y |= rson->y;
            y |= 1 << d >> 1;
            cnt += rson->cnt;
        }
    }
    void pushdown(int d)
    {
        if (tag << 1 >> d & 1)
            std::swap(lson, rson);
        if (lson)
            lson->Xor(tag, d - 1);
        if (rson)
            rson->Xor(tag, d - 1);
        tag = 0;
    }
    void Xor(int val, int d)
    {
        tag ^= val;
        x ^= val & y;
        y ^= val & x;
        x ^= val & y;
    }
} * root;
int n, m;
void insert(node *&now, int v, int d)
{
    if (!now)
        now = new node();
    if (d)
    {
        if (v << 1 >> d & 1)
            insert(now->rson, v, d - 1);
        else
            insert(now->lson, v, d - 1);
        now->pushup(d);
    }
    else
        now->cnt = 1;
}
#define r (l + (1 << d))
#define mid (l | 1 << d >> 1)
node *split(int L, int R, node *&now, int l = 0, int d = 20)
{
    if (R <= l || r <= L || !now)
        return nullptr;
    node *res = nullptr;
    if (L <= l && r <= R)
    {
        std::swap(res, now);
        return res;
    }
    now->pushdown(d);
    res = new node();
    if (!d)
        res->cnt = 1;
    res->lson = split(L, R, now->lson, l, d - 1);
    res->rson = split(L, R, now->rson, mid, d - 1);
    res->pushup(d);
    now->pushup(d);
    if (!res->cnt)
        delete res, res = nullptr; //, std::cout << "!!!!!!!!!!!!!" << ' ' << l << ' ' << r << std::endl;
    if (!now->cnt)
        delete now, now = nullptr; //, std::cout << "?????????????" << ' ' << l << ' ' << r << std::endl;
    return res;
}
void merge(node *&A, node *&B, int d = 20)
{
    if (!A)
        return std::swap(A, B);
    if (!B)
        return;
    if (d)
    {
        A->pushdown(d);
        B->pushdown(d);
        merge(A->lson, B->lson, d - 1);
        merge(A->rson, B->rson, d - 1);
        A->pushup(d);
    }
    else
        A->cnt = 1;
    delete B;
    B = nullptr;
}
void Xor(node *now, int x, int d = 20) { now ? now->Xor(x, d) : void(); }
void Or(node *now, int x, int d = 20)
{
    if (!now)
        return;
    if (now->x & now->y & x)
    {
        now->pushdown(d);
        if (x << 1 >> d & 1)
            merge(now->rson, now->lson, d - 1);
        Or(now->lson, x, d - 1);
        Or(now->rson, x, d - 1);
        now->pushup(d);
    }
    else
        Xor(now, now->x & x, d);
}
void print(node *now, int x = 0, int d = 20)
{
    if (!now)
        return;
    if (d == 0)
        return void(std::cout << x << std::endl);
    now->pushdown(d);
    if (now->lson)
        std::cout << now << ' ' << now->lson << ' ' << '0' << std::endl;
    if (now->rson)
        std::cout << now << ' ' << now->rson << ' ' << '1' << std::endl;
    print(now->lson, x, d - 1);
    print(now->rson, x | 1 << d >> 1, d - 1);
    now->pushup(d);
}
#undef r
#undef mid
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    while (n--)
    {
        static int x;
        std::cin >> x;
        insert(root, x, 20);
    }
    while (m--)
    {
        static int opt, l, r, x;
        std::cin >> opt >> l >> r;
        ++r;
        // print(root);
        // std::cout << std::endl;
        node *rt = split(l, r, root);
        // print(rt);
        // std::cout << std::endl;
        // print(root);
        // std::cout << std::endl;
        switch (opt)
        {
        case 1:
            std::cin >> x;
            Xor(rt, (1 << 20) - 1);
            Or(rt, (1 << 20) - 1 - x);
            Xor(rt, (1 << 20) - 1);
            break;
        case 2:
            std::cin >> x;
            Or(rt, x);
            break;
        case 3:
            std::cin >> x;
            Xor(rt, x);
            break;
        case 4:
            std::cout << (rt ? rt->cnt : 0) << '\n';
            break;
        }
        // std::cout << std::endl;
        merge(root, rt, 20);
        // print(root);
        // std::cout << std::endl;
        // std::cout << root->cnt << std::endl;
    }
    return 0;
}