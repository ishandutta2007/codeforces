// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, q, m, len, id[400005], sa[400005], rk[400005], L[400005], R[400005], h[400005], sum[400005], k[500005], ans[500005];
std::vector<int> ql[200005], qr[200005], g;
std::string s[200005];
void add(int pos, int val)
{
    ++pos;
    while (pos <= len)
    {
        sum[pos] += val;
        pos += pos & -pos;
    }
}
int pre(int pos)
{
    if (!~pos)
        return 0;
    int res = 0;
    while (pos)
    {
        res += sum[pos];
        pos -= pos & -pos;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for (int i = 0; i != n; ++i)
        std::cin >> s[i], id[i] = g.size(), g.insert(g.end(), s[i].begin(), s[i].end()), g.push_back(i + 128);
    len = g.size();
    m = 128 + n;
    for (int i = 0; i != len; ++i)
        ++sum[rk[i] = g[i]];
    for (int i = 1; i != m; ++i)
        sum[i] += sum[i - 1];
    for (int i = 0; i != len; ++i)
        sa[--sum[rk[i]]] = i;
    for (int k = 1; k < len; k <<= 1)
    {
        static int cnt, tmp[400005];
        cnt = 0;
        for (int i = len - k; i != len; ++i)
            tmp[cnt++] = i;
        for (int i = 0; i != len; ++i)
            if (sa[i] >= k)
                tmp[cnt++] = sa[i] - k;
        std::fill(sum, sum + m, 0);
        for (int i = 0; i != len; ++i)
            ++sum[rk[i]];
        for (int i = 1; i != m; ++i)
            sum[i] += sum[i - 1];
        for (int i = len; i--;)
            sa[--sum[rk[tmp[i]]]] = tmp[i];
        std::swap(rk, tmp);
        rk[sa[0]] = m = 0;
        for (int i = 1; i != len; ++i)
            rk[sa[i]] = tmp[sa[i]] == tmp[sa[i - 1]] && tmp[sa[i] + k] == tmp[sa[i - 1] + k] ? m : ++m;
        if (len == ++m)
            break;
    }
    // for (int i = 0; i != len; ++i)
    // {
    //     for (int j = sa[i]; j != len; ++j)
    //         std::cout << g[j] << ' ';
    //     std::cout << std::endl;
    // }
    for (int i = 0, height = 0; i != len; ++i)
    {
        if (!rk[i])
            continue;
        if (height)
            --height;
        int j = sa[rk[i] - 1];
        while (i + height != len && j + height != len && g[i + height] == g[j + height])
            ++height;
        h[rk[i]] = height;
    }
    for (int i = 0; i != len; ++i)
    {
        L[i] = i - 1;
        while (L[i] != -1 && h[L[i]] >= h[i])
            L[i] = L[L[i]];
    }
    for (int i = len; i--;)
    {
        R[i] = i + 1;
        while (R[i] != len && h[R[i]] >= h[i])
            R[i] = R[R[i]];
    }
    for (int i = 0, l, r; i != q; ++i)
    {
        std::cin >> l >> r >> k[i];
        --l;
        --k[i];
        ql[l].push_back(i);
        qr[r].push_back(i);
    }
    // for (int i = 0; i != len; ++i)
    //     std::cout << h[i] << " \n"[i + 1 == len];
    // for (int i = 0; i != len; ++i)
    //     std::cout << L[i] << " \n"[i + 1 == len];
    // for (int i = 0; i != len; ++i)
    //     std::cout << R[i] << " \n"[i + 1 == len];
    std::fill(sum, sum + len + 1, 0);
    for (int i = 0; i <= n; ++i)
    {
        for (auto j : ql[i])
            ans[j] -= pre(h[rk[id[k[j]]] + 1] == int(s[k[j]].size()) ? R[rk[id[k[j]]] + 1] : rk[id[k[j]]] + 1) -
                      pre(h[rk[id[k[j]]]] == int(s[k[j]].size()) ? L[rk[id[k[j]]]] : rk[id[k[j]]]);
        for (auto j : qr[i])
            ans[j] += pre(h[rk[id[k[j]]] + 1] == int(s[k[j]].size()) ? R[rk[id[k[j]]] + 1] : rk[id[k[j]]] + 1) -
                      pre(h[rk[id[k[j]]]] == int(s[k[j]].size()) ? L[rk[id[k[j]]]] : rk[id[k[j]]]);
        if (i != n)
            for (std::size_t j = 0; j != s[i].size(); ++j)
                add(rk[id[i] + j], 1);
    }
    for (int i = 0; i != q; ++i)
        std::cout << ans[i] << '\n';
    return 0;
}