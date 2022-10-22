// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 Rand(seed);
class treap
{
private:
    struct node
    {
        int v, w, siz;
        node *lson, *rson;
        node(int v_) : v(v_), w(Rand()), siz(1), lson(), rson() {}
        friend int size(node *x) { return x ? x->siz : 0; }
        void pushup() { siz = size(lson) + 1 + size(rson); }
    };
    node *root;
    node *merge(node *A, node *B)
    {
        if (!A)
            return B;
        if (!B)
            return A;
        if (A->w < B->w)
            return A->rson = merge(A->rson, B), A->pushup(), A;
        else
            return B->lson = merge(A, B->lson), B->pushup(), B;
    }
    std::pair<node *, node *> split(node *X, int x)
    {
        if (!X)
            return {};
        std::pair<node *, node *> res;
        if (X->v < x)
        {
            res = split(X->rson, x);
            X->rson = res.first;
            res.first = X;
            X->pushup();
            return res;
        }
        else
        {
            res = split(X->lson, x);
            X->lson = res.second;
            res.second = X;
            X->pushup();
            return res;
        }
    }
    int rank_(node *now, int m)
    {
        if (!now)
            return 0;
        if (now->v >= m)
            return rank_(now->lson, m) + 1 + size(now->rson);
        else
            return rank_(now->rson, m);
    }

public:
    void insert(int v)
    {
        std::pair<node *, node *> A = split(root, v);
        root = merge(A.first, merge(new node(v), A.second));
    }
    void erase(int v)
    {
        std::pair<node *, node *> A = split(root, v);
        if (v == INT_MAX)
            return void(root = merge(A.first, merge(A.second->lson, A.second->rson)));
        std::pair<node *, node *> B = split(A.second, v + 1);
        root = merge(A.first, merge(merge(B.first->lson, B.first->rson), B.second));
        delete B.first;
    }
    int rank(int m) { return rank_(root, m); }
} t[100005];
int n, k, siz[100005], fa[100005], heavy[100005], top[100005], but[100005], dfn[100005], idfn[100005], tim, c[100005];
std::vector<int> to[100005];
typedef std::array<int, 2> node;
node operator+(const node &A, const node &B) { return {std::min(A[1], std::max(A[0], B[0])),
                                                       std::min(A[1], std::max(A[0], B[1]))}; }
node g[1 << 18], h[100005];
constexpr node ze = {INT_MIN, INT_MAX};
#define lson (now << 1)
#define rson (lson | 1)
#define mid ((l + r) >> 1)
void pushup(int now)
{
    g[now] = g[lson] + g[rson];
    // std::cout << g[lson][0] << ' ' << g[lson][1] << std::endl
    //           << g[rson][0] << ' ' << g[rson][1] << std::endl
    //           << g[now][0] << ' ' << g[now][1] << std::endl;
}
void modify(int pos, int now = 1, int l = 0, int r = n)
{
    if (r - l == 1)
    {
        g[now] = h[idfn[pos]];
        return;
    }
    // std::cout << now << ' ' << pos << std::endl;
    // assert(now > 0);
    if (pos < mid)
        modify(pos, lson, l, mid);
    else
        modify(pos, rson, mid, r);
    pushup(now);
}
node query(int L, int R, int now = 1, int l = 0, int r = n)
{
    if (L <= l && r <= R)
        return g[now];
    if (r <= L || R <= l)
        return ze;
    return query(L, R, lson, l, mid) + query(L, R, rson, mid, r);
}
#undef lson
#undef rson
#undef mid
int get(int pos)
{
    return query(dfn[pos], dfn[but[pos]])[c[but[pos]]];
}
void init1(int now)
{
    siz[now] = 1;
    for (std::size_t i = 0; i != to[now].size(); ++i)
    {
        if (fa[now] == to[now][i])
        {
            std::swap(to[now][i--], to[now].back());
            to[now].pop_back();
            continue;
        }
        fa[to[now][i]] = now;
        init1(to[now][i]);
        siz[now] += siz[to[now][i]];
        if (siz[heavy[now]] < siz[to[now][i]])
            heavy[now] = to[now][i];
    }
}
// 2B-m>=k
void init2(int now)
{
    idfn[dfn[now] = tim++] = now;
    if (!top[now])
        top[now] = now;
    if (heavy[now])
        top[heavy[now]] = top[now], init2(heavy[now]), but[now] = but[heavy[now]];
    else
        return h[but[now] = now] = ze, modify(dfn[now]);
    for (auto i : to[now])
    {
        if (heavy[now] == i)
            continue;
        init2(i);
        t[now].insert(get(i));
    }
    // std::cout << now << std::endl;
    // for (auto i : to[now])
    //     std::cout << get(i) << ' ';
    // std::cout << std::endl;
    // for (int i = -n; i <= +n; ++i)
    //     std::cout << t[now].rank(i) << " \n"[i == +n];
    static int l, r;
    l = -n;
    r = +n;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (2 * t[now].rank(mid) - int(to[now].size()) >= mid)
            l = mid;
        else
            r = mid - 1;
    }
    h[now][0] = l;
    l = -n;
    r = +n;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (2 * (t[now].rank(mid) + 1) - int(to[now].size()) >= mid)
            l = mid;
        else
            r = mid - 1;
    }
    h[now][1] = l;
    // std::cout << h[now][0] << ' ' << h[now][1] << std::endl;
    modify(dfn[now]);
}
void update(int now)
{
    while (2 * t[now].rank(h[now][0]) - int(to[now].size()) >= h[now][0])
        ++h[now][0];
    while (2 * t[now].rank(h[now][0]) - int(to[now].size()) < h[now][0])
        --h[now][0];
    while (2 * (t[now].rank(h[now][1]) + 1) - int(to[now].size()) >= h[now][1])
        ++h[now][1];
    while (2 * (t[now].rank(h[now][1]) + 1) - int(to[now].size()) < h[now][1])
        --h[now][1];
    modify(dfn[now]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1, u, v; i != n; ++i)
    {
        std::cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        std::cin >> c[i];
    init1(1);
    init2(1);
    int q;
    std::cin >> q;
    for (int i = 1, opt, a, b; i <= q; ++i)
    {
        std::cin >> opt;
        switch (opt)
        {
        case 1:
            std::cin >> a;
            // std::cout << get(a) << std::endl;
            std::cout << (k <= get(a)) << std::endl;
            break;
        case 2:
            std::cin >> a >> b;
            if (c[a] ^ b)
            {
                if (fa[top[a]])
                {
                    // std::cout << fa[top[a]] << std::endl;
                    t[fa[top[a]]].erase(get(top[a]));
                    c[a] = b;
                    t[fa[top[a]]].insert(get(top[a]));
                    a = fa[top[a]];
                    while (fa[top[a]])
                    {
                        t[fa[top[a]]].erase(get(top[a]));
                        update(a);
                        t[fa[top[a]]].insert(get(top[a]));
                        a = fa[top[a]];
                    }
                    update(a);
                }
                else
                    c[a] = b;
            }
            break;
        case 3:
            std::cin >> k;
            break;
        }
    }
    return 0;
}