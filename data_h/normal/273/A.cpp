#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 210000;

int n, m;
struct SEG
{
    int TL, TR;
    long long tree[MAXN * 4], lazy[MAXN * 4];
    void clear()
    {
        memset(tree, 0, sizeof tree);
        memset(lazy, 0, sizeof lazy);
    }
    void set_border(int l, int r)
    {
        TL = l, TR = r;
    }
    void push(int root)
    {
        if (!lazy[root])
            return ;
        tree[root * 2] = lazy[root * 2] = lazy[root];
        tree[root * 2 + 1] = lazy[root * 2 + 1] = lazy[root];
        lazy[root] = 0;
    }
    void update(int root, int L, int R)
    {
        tree[root] = max(tree[L], tree[R]);
    }
    long long ask(int root, int L, int R, int l, int r)
    {
        if (l <= L && R <= r)
            return tree[root];
        push(root);
        int mid = (L + R) / 2;
        long long res = 0;
        if (r > mid)
            res = max(res, ask(root * 2 + 1, mid + 1, R, l, r));
        if (l <= mid)
            res = max(res, ask(root * 2, L, mid, l, r));
        update(root, root * 2, root * 2 + 1);   
        return res;
    }
    void ins(int root, int L, int R, int l, int r, long long v)
    {
        if (l <= L && R <= r)
        {
            tree[root] = lazy[root] = v;
            return;
        }
        push(root);
        int mid = (L + R) / 2;
        if (r > mid)
            ins(root * 2 + 1, mid + 1, R, l, r, v);
        if (l <= mid)
            ins(root * 2, L, mid, l, r, v);
        update(root, root * 2, root * 2 + 1);
    }
    void ins(int l, int r, long long v)
    {
        ins(1, TL, TR, l, r, v);
    }
    long long ask(int l, int r)
    {
        return ask(1, TL, TR, l, r);
    }
}T;

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    T.clear();
    T.set_border(1, n);
    for(int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        T.ins(i, i, a);
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
    {
        long long w, h;
        scanf("%I64d %I64d", &w, &h);
        long long tmp = T.ask(1, w);
        T.ins(1, w, tmp + h);
        printf("%I64d\n", tmp);
    }
    return 0;
}