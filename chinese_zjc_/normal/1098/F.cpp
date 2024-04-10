// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
char s[200005];
int n, m = 128, q, sa[200005], rk[200005], sum[200005], height[200005], r[200005],
       son[400005][2], fa[400005], top[400005], size[400005], v[400005], end, &root = son[0][1];
long long ans[200005];
std::vector<int> que[200005];
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 Rand(seed);
void add_node(int now)
{
    fa[son[end][1] = now] = end;
    while (v[end] > v[now])
    {
        fa[son[end][1] = son[now][0]] = end;
        fa[son[fa[end]][1] = now] = fa[end];
        fa[son[now][0] = end] = now;
        end = fa[now];
    }
    end = now;
}
void init1(int now)
{
    if (now <= n)
        return void(size[now] = 1);
    init1(son[now][0]);
    init1(son[now][1]);
    if (size[son[now][0]] < size[son[now][1]])
        std::swap(son[now][0], son[now][1]);
    size[now] = size[son[now][0]] + size[son[now][1]];
    // std::cout << now << ' ' << size[now] << std::endl;
}
void init2(int now)
{
    if (!top[now])
        top[now] = now;
    if (now <= n)
        return;
    top[son[now][0]] = top[now];
    init2(son[now][0]);
    init2(son[now][1]);
}
struct BIT
{
    long long sum[200005];
    void add(int pos, int val)
    {
        while (pos <= n)
        {
            sum[pos] += val;
            pos += pos & -pos;
        }
    }
    long long query(int pos)
    {
        long long res = 0;
        while (pos)
        {
            res += sum[pos];
            pos -= pos & -pos;
        }
        return res;
    }
    long long query(int l, int r) { return r < l ? 0 : query(r) - query(l - 1); }
} A, B;
void add(int now)
{
    if (now <= n)
    {
        A.add(now, +now);
        B.add(now, +1);
        return;
    }
    add(son[now][0]);
    add(son[now][1]);
}
void del(int now)
{
    if (now <= n)
    {
        A.add(now, -now);
        B.add(now, -1);
        return;
    }
    del(son[now][0]);
    del(son[now][1]);
}
void cal(int now, int val)
{
    if (now <= n)
    {
        for (auto i : que[now])
            if (r[i] - now + 1 >= val)
                ans[i] += B.query(now, r[i] - val + 1) * val +
                          (r[i] + 1) * B.query(r[i] - val + 2, r[i]) - A.query(r[i] - val + 2, r[i]);
            else
                ans[i] += (r[i] + 1) * B.query(now, r[i]) - A.query(now, r[i]);
        return;
    }
    cal(son[now][0], val);
    cal(son[now][1], val);
}
void work1(int now)
{
    if (now <= n)
    {
        add(now);
        return;
    }
    work1(son[now][1]);
    // cal(son[now][0], v[now]); // ???
    del(son[now][1]);
    work1(son[now][0]);
    cal(son[now][1], v[now]);
    add(son[now][1]);
    // std::cout << now << ' ' << ans[1] << ' ' << v[now] << std::endl;
}
struct operation
{
    int p, len;
    friend bool operator<(const operation &A, const operation &B) { return A.p + A.len < B.p + B.len; }
};
struct query
{
    int l, r, s;
    friend bool operator<(const query &A, const query &B) { return ::r[A.r] < ::r[B.r]; }
};
std::vector<operation> op[400005];
std::vector<query> qu[400005];
void cdq(const std::vector<int>::const_iterator l, const std::vector<int>::const_iterator r)
{
    if (r - l == 1)
        return;
    const std::vector<int>::const_iterator mid = l + (r - l) / 2;
    std::vector<operation> ops;
    std::vector<query> qus;
    for (std::vector<int>::const_iterator i = l; i != mid; ++i)
        ops.insert(ops.end(), op[*i].begin(), op[*i].end());
    for (std::vector<int>::const_iterator i = mid; i != r; ++i)
        qus.insert(qus.end(), qu[*i].begin(), qu[*i].end());
    std::sort(ops.begin(), ops.end());
    std::sort(qus.begin(), qus.end());
    std::vector<operation>::const_iterator j = ops.begin();
    for (std::vector<query>::const_iterator i = qus.begin(); i != qus.end(); ++i)
    {
        while (j != ops.end() && j->p + j->len <= ::r[i->r])
            A.add(j->p, +j->len), ++j;
        ans[i->r] += A.query(i->l, ::r[i->r]);
    }
    while (j != ops.end())
        A.add(j->p, +j->len), ++j;
    std::for_each(ops.cbegin(), j, [&](const operation &x)
                  { A.add(x.p, -x.len); });
    std::reverse(ops.begin(), ops.end());
    std::reverse(qus.begin(), qus.end());
    j = ops.begin();
    for (std::vector<query>::const_iterator i = qus.begin(); i != qus.end(); ++i)
    {
        while (j != ops.end() && j->p + j->len > ::r[i->r])
            A.add(j->p, +j->p), B.add(j->p, +1), ++j;
        ans[i->r] += (::r[i->r] + 1) * B.query(i->l, ::r[i->r]) - A.query(i->l, ::r[i->r]);
    }
    while (j != ops.end())
        A.add(j->p, +j->p), B.add(j->p, +1), ++j;
    std::for_each(ops.cbegin(), j, [&](const operation &x)
                  { A.add(x.p, -x.p), B.add(x.p, -1); });
    cdq(l, mid);
    cdq(mid, r);
}
void work2()
{
    for (int i = 1; i <= n; ++i)
        for (int j = i; j; j = fa[top[j]])
        {
            op[j].push_back({i, v[j]});
            for (auto k : que[i])
                qu[j].push_back({i, k, v[j]});
        }
    for (int i = 1; i <= n + n - 1; ++i)
        if (top[i] == i)
        {
            std::vector<int> tmp;
            for (int j = i; j; j = son[j][0])
                tmp.push_back(j);
            cdq(tmp.begin(), tmp.end());
        }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> (s + 1) >> q;
    n = std::strlen(s + 1);
    for (int i = 1; i <= n; ++i)
        ++sum[rk[i] = s[i]];
    for (int i = 1; i <= m; ++i)
        sum[i] += sum[i - 1];
    for (int i = n; i; --i)
        sa[sum[rk[i]]--] = i;
    for (int k = 1; k <= n; k <<= 1)
    {
        static int cnt, tmp[200005];
        cnt = 0;
        for (int i = n - k + 1; i <= n; ++i)
            tmp[++cnt] = i;
        for (int i = 1; i <= n; ++i)
            if (sa[i] > k)
                tmp[++cnt] = sa[i] - k;
        std::fill(sum + 1, sum + 1 + m, 0);
        for (int i = 1; i <= n; ++i)
            ++sum[rk[i]];
        for (int i = 1; i <= m; ++i)
            sum[i] += sum[i - 1];
        for (int i = n; i; --i)
            sa[sum[rk[tmp[i]]]--] = tmp[i];
        std::copy(rk + 1, rk + 1 + n, tmp + 1);
        rk[sa[1]] = m = 1;
        for (int i = 2; i <= n; ++i)
            rk[sa[i]] = tmp[sa[i]] == tmp[sa[i - 1]] && tmp[sa[i] + k] == tmp[sa[i - 1] + k] ? m : ++m;
        if (n == m)
            break;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (rk[i] == n)
            continue;
        static int h;
        if (h)
            --h;
        int j = sa[rk[i] + 1];
        while (i + h <= n && j + h <= n && s[i + h] == s[j + h])
            ++h;
        height[rk[i]] = h;
    }
    for (int i = 1; i <= n; ++i)
        v[i] = INT_MAX;
    for (int i = 1; i < n; ++i)
        v[i + n] = height[i];
    for (int i = 1; i < n; ++i)
    {
        add_node(sa[i]);
        add_node(i + n);
        // std::cout << height[i] << std::endl;
    }
    add_node(sa[n]);
    init1(root);
    init2(root);
    for (int i = 1, x; i <= q; ++i)
        std::cin >> x >> r[i], ans[i] = r[i] - x + 1, que[x].push_back(i);
    work1(root);
    del(root);
    work2();
    for (int i = 1; i <= q; ++i)
        std::cout << ans[i] << '\n';
    return 0;
}