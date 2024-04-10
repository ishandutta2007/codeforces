#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> pos;
vector<int> cl;
vector<vector<int> > tr, rtr;
vector<bool> used;

void dfs1(int v)
{
    used[v] = true;
    for (int i = 0; i < tr[v].size(); i++)
    {
        if (!used[tr[v][i]])
            dfs1(tr[v][i]);
    }
    pos.push_back(v);
}

void dfs2(int v, int c)
{
    cl[v] = c;
    used[v] = true;
    for (int i = 0; i < rtr[v].size(); i++)
    {
        if (!used[rtr[v][i]])
            dfs2(rtr[v][i], c);
    }
}

bool tdfs(int v, int c)
{
    if (cl[v] != c)
        return false;
    used[v] = true;
    for (int i = 0; i < tr[v].size(); i++)
    {
        if (!used[tr[v][i]])
            if (!tdfs(tr[v][i], c))
                return false;
    }
    return true;
}

vector<int> t;

int mnc(int v, int n)
{
    used.assign(n, false);
    t.assign(n, 0);
    queue<int> q;
    q.push(v);
    t[v] = 0;
    used[v] = true;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int i = 0; i < tr[p].size(); i++)
        {
            if (tr[p][i] == v)
            {
                return t[p] - t[v] + 1;
            }
            if (!used[tr[p][i]])
            {
                used[tr[p][i]] = true;
                t[tr[p][i]] = t[p] + 1;
                q.push(tr[p][i]);
            }
        }
    }
    return 0;
}

int main()
{
    int n, m, i;
    cin >> n >> m;
    tr.resize(n);
    rtr.resize(n);
    used.resize(n);
    cl.resize(n);
    for (i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        tr[a].push_back(b);
        rtr[b].push_back(a);
    }
    for (i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);
    int cnt = 0;
    used.assign(n, false);
    for (i = pos.size() - 1; i >= 0; i--)
    {
        if (!used[pos[i]])
        {
            dfs2(pos[i], cnt);
            cnt++;
        }
    }
    used.assign(n, false);
    vector<bool> term(cnt);
    for (i = 0; i < n; i++)
    {
        used.assign(n, false);
        term[cl[i]] = tdfs(i, cl[i]);
    }
//    for (i = 0; i < n; i++)
//    {
//        cout << term[cl[i]] << ' ';
//    }
//    cout << endl;
    t.resize(n);
    vector<int> mcs(cnt, 10000000);
    for (i = 0; i < n; i++)
    {
        mcs[cl[i]] = min(mcs[cl[i]], mnc(i, n));
    }
    long long ans = n;
    for (i = 0; i < cnt; i++)
    {
        if (term[i])
            if (mcs[i] != 0)
                ans += mcs[i] * 998, ans++;
    }
    cout << ans;
    return 0;
}