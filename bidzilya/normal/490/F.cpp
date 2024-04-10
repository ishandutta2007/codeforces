#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

const int max_a = 1e6 + 1;

int n;
vector<vector<int> > g;
vector<int> r;

vector<int> tree(4 * max_a);
/*
int GetMax(int v, int tl, int tr, int l, int r)
{
    if (tl == l && tr == r) {
        return tree[v];
    } else {
        int tm = (tl + tr) >> 1;
        
        if (r <= tm) {
            return GetMax(2 * v, tl, tm, l, r); 
        } else if (l > tm) {
            return GetMax(2 * v + 1, tm + 1, tr, l, r);
        } else {
            return max(GetMax(2 * v, tl, tm, l, tm),
                        GetMax(2 * v + 1, tm + 1, tr, tm + 1, r));
        }
    }
}

int SetValue(int v, int tl, int tr, int pos, int x, bool rewrite)
{
    int old_value;
    if (tl == tr) {
        old_value = tree[v];
        if (rewrite) {
            tree[v] = x;
        } else {
            tree[v] = max(tree[v], x);
        }
        return old_value;
    } else {
        int tm = (tl + tr) >> 1;
        if (pos <= tm) {
            old_value = SetValue(2 * v, tl, tm, pos, x, rewrite);
        } else {
            old_value = SetValue(2 * v + 1, tm + 1, tr, pos, x, rewrite);
        }
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }
    
    return old_value;
}
*/

const int ChangeLogSize = 30;

struct ChangeLog
{
    ChangeLog()
    {
        sz = 0;
    }

    void AddChange(int _pos, int _value)
    {
        pos[sz] = _pos;
        value[sz] = _value;
        ++sz;
    }
    
    void Work()
    {
        for (int i = 0; i < sz; ++i) {
            tree[pos[i]] = value[i];
        }
    }
    
    int pos[ChangeLogSize];
    int value[ChangeLogSize];
    
    int sz;
};

int GetValue(int pos)
{
    int result = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        result = max(result, tree[pos]);
    }
    return result;
}

void SetValue(int pos, int value, ChangeLog& c)
{
    for (; pos <= max_a; pos |= (pos + 1)) {
        if (tree[pos] < value) {
            c.AddChange(pos, tree[pos]);
            tree[pos] = value;
        }
    }
}

int DFS(int v, int pr)
{
    int value = GetValue(r[v] - 1) + 1;

    ChangeLog c;
    
    SetValue(r[v], value, c);
    
    int result = value;
    
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (u != pr) {
            result = max(result, DFS(u, v));
        }
    }

    c.Work();
    
    return result;
}

int SolveTask(int root)
{
    return DFS(root, -1);
}

int main()
{
    /*
    freopen("input.txt", "w", stdout);
    cout << 6000 << endl;
    for (int i = 1; i <= 6000; ++i) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i + 1 < 6000; ++i) {
        cout << i + 1 << " " << i + 2 << endl;
    }
    return 0;
    */
    
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);

    cin >> n;
    r.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1; --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, SolveTask(i));
    }
    
    cout << ans << endl;
    
    return 0;
}