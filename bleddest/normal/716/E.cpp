#include<bits/stdc++.h>

using namespace std;

const int N = 200043;
int m, n;

int add(int x, int y)
{
    x += y;
    while(x >= m) x -= m;
    while(x < 0) x += m;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % m;
}

int sub(int x, int y)
{
    return add(x, m - y);
}

int binpow(int x, int y)
{
    int z = 1 % m;
    while(y > 0)
    {
        if(y % 2 == 1)
            z = mul(z, x);
        y /= 2;
        x = mul(x, x);
    }
    return z;
}

vector<pair<int, int>> g[N];
int used[N];
int siz[N];

void calc_sizes(int x, int p = -1)
{
    siz[x] = 1;
    for(auto y : g[x])
    {
        int to = y.first;
        if(to != p && !used[to])
        {
            calc_sizes(to, x);
            siz[x] += siz[to];
        }
    }
}

void dfs(int x, int p, int cur, int d, int c, map<int, int>& str)
{
    str[cur]++;
    for(auto y : g[x])
    {
        int to = y.first;
        int e = y.second;
        if(to != p && !used[to])
        {
            dfs(to, x, add(cur, mul(d, e)), mul(d, c), c, str);
        }
    }
}

int find_centroid(int x, int full_size, int p = -1)
{
    int ans = -1;
    bool good = (full_size - siz[x]) * 2 <= full_size;
    for(auto y : g[x])
    {
        int to = y.first;
        if(to != p && !used[to])
        {
            good &= siz[to] * 2 <= full_size;
            ans = max(ans, find_centroid(to, full_size, x));
        }
    }
    if(good)
        ans = max(ans, x);
    return ans;
}

long long ans = 0;

long long merge_heads_tails(const map<int, int>& heads, map<int, int>& tails)
{
    long long res = 0;
    for(auto x : heads)
    {
        int H = x.first;
        int cnt = x.second;
        int T = sub(m, H);
        if(!tails.count(T))
            continue;
        res += tails[T] * 1ll * cnt;
    }
    return res;
}

long long merge_tails_heads(const map<int, int>& tails, map<int, int>& heads)
{
    long long res = 0;
    for(auto x : tails)
    {
        int T = x.first;
        int cnt = x.second;
        int H = sub(m, T);
        if(!heads.count(H))
            continue;
        res += heads[H] * 1ll * cnt;
    }
    return res;
}

int phi(int m)
{
    int ans = m;
    set<int> f;
    for(int i = 2; i * i <= m; i++)
        while(m % i == 0)
        {
            f.insert(i);
            m /= i;
        }          
    if(m != 1) f.insert(m);
    for(auto x : f)
        ans = ans / x * (x - 1);
    return ans;
}

int inv10;

void calc_answer(int c)
{                                               
    map<int, int> heads;
    map<int, int> tails;
    heads[0] = 1;
    tails[0] = 1;
    for(auto y : g[c])
    {
        int to = y.first;
        if(used[to])
            continue;
        map<int, int> new_heads;
        dfs(to, c, mul(inv10, y.second), mul(inv10, inv10), inv10, new_heads);
        map<int, int> new_tails;
        dfs(to, c, y.second % m, 10 % m, 10 % m, new_tails);
        ans += merge_heads_tails(new_heads, tails);
        ans += merge_tails_heads(new_tails, heads);  
        for(auto x : new_heads)
            heads[x.first] += x.second;  
        for(auto x : new_tails)
            tails[x.first] += x.second;
    }
}

void decomposition(int x)
{
    calc_sizes(x);
    int c = find_centroid(x, siz[x]);
    calc_answer(c);
    used[c] = 1;
    for(auto y : g[c])
    {
        int to = y.first;
        if(!used[to])
            decomposition(to);
    }
}

int main()
{            
    scanf("%d", &n);
    scanf("%d", &m);
    inv10 = binpow(10, phi(m) - 1);
    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        int w;
        scanf("%d", &w);
        g[x].push_back(make_pair(y, w));
        g[y].push_back(make_pair(x, w));
    }
    decomposition(0);
    cout << ans << endl;
}