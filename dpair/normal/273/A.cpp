#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <typename T>
inline void read(T &x)
{
    x = 0;
    int fu = 1;
    char c = getchar();
    while(c > 57 || c < 48)
    {
        if(c == 45) fu = -1;
        c = getchar();
    }
    while(c <= 57 && c >= 48)
    {
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    x *= fu;
}

LL a[200010];
struct seg_tree{
    struct node{
        LL num, lazy;
    }tree[800010];

    void pushup(int rt)
    {
        tree[rt].num = max(tree[rt << 1].num, tree[rt << 1 | 1].num);
    }

    void pushdown(int rt, int l, int r)
    {
        int mid = (l + r) >> 1;
        tree[rt << 1].lazy = tree[rt].lazy;
        tree[rt << 1].num = tree[rt].lazy;
        tree[rt << 1 | 1].lazy = tree[rt].lazy;
        tree[rt << 1 | 1].num = tree[rt].lazy;   
        tree[rt].lazy = 0;
    }

    void build(int rt, int l, int r)
    {
        if (l == r)
        {
            tree[rt].num = a[l];
            return; 
        }
        int mid = (l + r) >> 1;
        build(rt << 1, l, mid);
        build(rt << 1 | 1, mid + 1, r);
        pushup(rt);
    }

    LL query_num(int rt, int l, int r, int x, int y) 
    {
        if (x <= l && r <= y) return tree[rt].num;
        int mid = (l + r) >> 1;
        if (tree[rt].lazy) pushdown(rt, l, r);
        LL ans = -0x3f3f3f3f;
        if (x <= mid) ans = max(ans, query_num(rt << 1, l, mid, x, y));
        if (y > mid) ans = max(ans, query_num(rt << 1 | 1, mid + 1, r, x, y));
        pushup(rt);
        return ans;
    }

    void modify(int rt, int l, int r, int x, int y , LL z)
    {
        if (x <= l && r <= y)
        {
            tree[rt].lazy = z;
            tree[rt].num = z;
            return;
        }
        if (tree[rt].lazy) pushdown(rt, l, r); 
        int mid = (l + r) >> 1; 
        if (x <= mid) modify(rt << 1, l, mid, x, y, z);
        if (y > mid) modify(rt << 1 | 1, mid + 1, r, x, y, z);
        pushup(rt);
    }
}t;

int n, m;

int main()
{
	read(n);
	for (register int i = 1;i <= n;i ++) read(a[i]);
	t.build(1, 1, n);
	read(m);
	while(m --)
	{
		int l;
		LL r;
		read(l);read(r);
		LL ret = t.query_num(1, 1, n, 1, l);
		printf("%lld\n", ret);
		t.modify(1, 1, n, 1, l, ret + r);
	}
}