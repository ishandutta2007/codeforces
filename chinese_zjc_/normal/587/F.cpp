// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int N = 100000;
const int B = 300;
int n, q, cnt = 1;
long long ans[100005];
struct node
{
    int link, nxt[26];
    std::vector<int> way, app, son;
} t[100005];
struct query
{
    int l, r, k;
} a[100005];
std::string s[100005];
void insert(int now, int pos, std::string::iterator begin, std::string::iterator end)
{
    t[now].way.push_back(pos);
    if (begin == end)
        return t[now].app.push_back(pos);
    if (!t[now].nxt[*begin - 'a'])
        t[now].nxt[*begin - 'a'] = cnt++;
    return insert(t[now].nxt[*begin - 'a'], pos, begin + 1, end);
}
void build()
{
    std::queue<int> que;
    for (int i = 0; i != 26; ++i)
        if (t[0].nxt[i])
            que.push(t[0].nxt[i]), t[0].son.push_back(t[0].nxt[i]);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = 0; i != 26; ++i)
            if (t[now].nxt[i])
            {
                int tmp = t[now].nxt[i];
                que.push(tmp);
                int &fa = t[tmp].link = t[now].link;
                while (fa && !t[fa].nxt[i])
                    fa = t[fa].link;
                t[fa = t[fa].nxt[i]].son.push_back(tmp);
            }
    }
}
struct BLOCK
{
    long long sumb[N / B + 2];
    long long sum[N / B + 2][B + 1];
    int in1(int pos) { return (pos - 1) / B + 1; }
    int in2(int pos) { return (pos - 1) % B + 1; }
    void add(int pos, int val)
    {
        for (int i = in1(pos); i <= in1(n); ++i)
            sumb[i] += val;
        for (int i = in2(pos); i <= B; ++i)
            sum[in1(pos)][i] += val;
    }
    long long query(int pos) { return pos ? sumb[in1(pos) - 1] + sum[in1(pos)][in2(pos)] : 0; }
    long long query(int l, int r) { return query(r) - query(l - 1); }
    void clear() { memset(sumb, 0, sizeof(sumb)), memset(sum, 0, sizeof(sum)); }
} c;
std::vector<int> belongs[100005];
void dfs(int now)
{
    for (auto i : t[now].app)
        c.add(i, +1);
    for (auto i : t[now].way)
        if (s[i].size() <= B)
            for (auto j : belongs[i])
                ans[j] += c.query(a[j].l, a[j].r);
    for (auto i : t[now].son)
        dfs(i);
    for (auto i : t[now].app)
        c.add(i, -1);
}
int init(int now, int pos)
{
    int tot = std::binary_search(t[now].way.begin(), t[now].way.end(), pos);
    for (auto i : t[now].son)
        tot += init(i, pos);
    for (auto i : t[now].app)
        c.add(i, tot);
    return tot;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        std::cin >> s[i], insert(0, i, s[i].begin(), s[i].end());
    build();
    for (int i = 1; i <= q; ++i)
        std::cin >> a[i].l >> a[i].r >> a[i].k, belongs[a[i].k].push_back(i);
    dfs(0);
    for (int i = 1; i <= n; ++i)
        if (s[i].size() > B)
        {
            init(0, i);
            for (auto j : belongs[i])
                ans[j] = c.query(a[j].l, a[j].r);
            c.clear();
        }
    for (int i = 1; i <= q; ++i)
        std::cout << ans[i] << std::endl;
    return 0;
}