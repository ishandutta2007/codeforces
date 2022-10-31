#include<bits/stdc++.h>

using namespace std;

const int N = 150043;

typedef pair<long long, long long> func;

func T[4 * N];
bool usedT[4 * N];

void clear(int v, int l, int r)
{
    if(!usedT[v]) return;
    usedT[v] = false;
    T[v] = make_pair(0ll, 0ll);
    if(l < r - 1)
    {
        int m = (l + r) / 2;
        clear(v * 2 + 1, l, m);
        clear(v * 2 + 2, m, r);
    }
}

long long eval(func f, int x)
{
    return f.first * x + f.second;
}

long long get(int v, int l, int r, int x)
{
    long long ans = eval(T[v], x);
    if(l < r - 1)
    {
        int m = (l + r) / 2;
        if(m > x)
            ans = max(ans, get(v * 2 + 1, l, m, x));
        else
            ans = max(ans, get(v * 2 + 2, m, r, x));
    }
    return ans;
}

void upd(int v, int l, int r, func f)
{
    usedT[v] = true;
    int m = (l + r) / 2;
    bool need_swap = eval(f, m) > eval(T[v], m);
    if(need_swap)
        swap(T[v], f);
    if(l == r - 1)
        return;
    if(eval(f, l) > eval(T[v], l))
        upd(v * 2 + 1, l, m, f);
    else
        upd(v * 2 + 2, m, r, f);
}

long long ans = 0;

void update_ans(vector<vector<func> > heads, vector<vector<func> > tails)
{
    int n = heads.size();
    for(int i = 0; i < n; i++)
    {
        for(auto x : heads[i])
            ans = max(ans, get(0, 0, N, x.first) + x.second);
        for(auto x : tails[i])
            upd(0, 0, N, x);
    }
    clear(0, 0, N);
}

int a[N];
vector<int> g[N];
int n;
bool used[N];
int siz[N];

void dfs1(int x, int p = -1)
{
    if(used[x]) return;
    siz[x] = 1;
    for(auto to : g[x])
    {                    
        if(!used[to] && to != p)
        {
            dfs1(to, x);
            siz[x] += siz[to];
        }
    }
}

pair<int, int> c;
int S = 0;

void find_centroid(int x, int p = -1)
{
    if(used[x]) return;
    int mx = 0;
    for(auto to : g[x])
    {
        if(!used[to] && to != p)
        {
            find_centroid(to, x);
            mx = max(mx, siz[to]);
        }
    }
    if(p != -1)
        mx = max(mx, S - siz[x]);
    c = min(c, make_pair(mx, x));
}

void dfs_heads(int v, int p, int cnt, long long cursum, long long curadd, vector<func>& sink)
{
    if(used[v])
        return;
    cnt++;
    curadd += a[v];
    cursum += curadd;
    sink.push_back(make_pair(cnt, cursum));
    for(auto to : g[v])
        if(to != p)
            dfs_heads(to, v, cnt, cursum, curadd, sink);
}

void dfs_tails(int v, int p, int cnt, long long cursum, long long curadd, vector<func>& sink)
{
    if(used[v])
        return;
    cnt++;
    curadd += a[v];
    cursum += a[v] * 1ll * cnt;
    sink.push_back(make_pair(curadd, cursum));
    for(auto to : g[v])
        if(to != p)
            dfs_tails(to, v, cnt, cursum, curadd, sink);
}

void centroid(int v)
{
    if(used[v]) return;
    dfs1(v);
    S = siz[v];
    c = make_pair(int(1e9), -1);
    find_centroid(v);
    int C = c.second;
    used[C] = 1;
    vector<vector<func> > heads, tails;
    for(auto to : g[C])
        if(!used[to])
        {
            heads.push_back(vector<func>());
            dfs_heads(to, C, 1, a[C], a[C], heads.back());
            tails.push_back(vector<func>());
            dfs_tails(to, C, 0, 0, 0, tails.back());
        }
    heads.push_back(vector<func>({{1, a[C]}}));
    tails.push_back(vector<func>({{0, 0}}));
    update_ans(heads, tails);
    reverse(heads.begin(), heads.end());
    reverse(tails.begin(), tails.end());
    update_ans(heads, tails);
    for(auto to : g[C])
        centroid(to);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);    
    }
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    centroid(0);
    printf("%lld\n", ans);
}