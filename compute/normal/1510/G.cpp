#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100 + 7, INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;

vector<int> G[N];
int dep[N],ds[N];
int n, k;
int st[N * 100], tot, cur;

void getdep(int u, int f)
{
    dep[u] = 1;
    for(int v: G[u])
    {
        if(v != f)
        {
            getdep(v, u);
            if(dep[v] + 1 > dep[u])
            {
                dep[u] = dep[v] + 1;
                ds[u] = v;
            }
        }
    }
}

void dfs(int u, int f, int m)
{
    st[tot++] = u;
    k--;
    if(!k)
    {
        return;
    }
    if(m)
    {
        cur--;
        if(k > cur)
        {
            for(int v: G[u])
            {
                if(v != f && v != ds[u])
                {
                    dfs(v, u, 0);
                    if(!k)
                    {
                        return;
                    }
                    st[tot++] = u;
                    if(k <= cur)
                    {
                        break ;
                    }
                }
            }
        }
        dfs(ds[u], u, 1);
        if(!k)
        {
            return;
        }
    }
    else
    {
        if(k <= cur)
        {
            return ;
        }
        else
        {
            for(int v: G[u])
            {
                if(v != f)
                {
                    dfs(v, u, 0);
                    if(!k)
                    {
                        return;
                    }
                    st[tot++] = u;
                    if(k <= cur)
                    {
                        return ;
                    }
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, cas = 0;
    cin >> T;
    while (T--)
    {
        tot = cur = 0;
        cin >> n >> k;
        for(int i = 1; i <= n; ++i)
        {
            G[i].clear();
        }
        for(int u,i = 2; i <= n; ++i)
        {
            cin >> u;
            G[u].push_back(i);
        }
        getdep(1, 0);
        cur = dep[1];
        dfs(1, 0, 1);
        cout << tot - 1 << '\n';
        for(int i = 0; i < tot; ++i)
        {
            cout << st[i] << " \n"[i == tot - 1];
        }
    }
}