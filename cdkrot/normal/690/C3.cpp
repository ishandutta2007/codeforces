#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

class sparse_table
{
    vector<int> values;
    vector<int> maxk;
    vector<vector<int> > st;
    void build(const vector<int>& a)
    {
        values = a;
        int n = a.size();
        st.resize(maxk[n] + 1);
        st[0].resize(n);
        for (int i = 0; i < n; i++)
            st[0][i] = i;
        for (int i = 1; i <= maxk[n]; i++)
        {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j < (int)st[i].size(); j++)
            {
                if (values[st[i - 1][j]] < values[st[i - 1][j + (1 << (i - 1))]])
                    st[i][j] = st[i - 1][j];
                else
                    st[i][j] = st[i - 1][j + (1 << (i - 1))];
            }
        }
    }
 public:
    sparse_table(const vector<int>& vec)
    {
        int n = vec.size();
        maxk.resize(n + 1, 0);
        for (int i = 2; i < n + 1; i++)
            maxk[i] = maxk[i / 2] + 1;
        build(vec);
    }
    sparse_table() {}
    int get(int l, int r)
    {
        if (values[st[maxk[r - l]][l]] < values[st[maxk[r - l]][r - (1 << maxk[r - l])]])
            return st[maxk[r - l]][l];
        else
            return st[maxk[r - l]][r - (1 << maxk[r - l])];
    }
};

int n;
vector<vector<int> > graph;
vector<int> vec;
vector<int> height;
vector<int> first;
vector<int> tin, tout, parent;
int cur_time = 0;

void dfs(int u, int par, int hg)
{
    height[u] = hg;
    vec.push_back(u);
    first[u] = vec.size() - 1;
    tin[u] = cur_time++;
    parent[u] = par;
    for (int v : graph[u])
        if (v != par)
        {
            vec.push_back(u);
            dfs(v, u, hg + 1);
        }
    tout[u] = cur_time++;
}

sparse_table st;

void precalc_lca()
{
    vec.clear();
    height.clear();
    first.clear();
    height.resize(n);
    first.resize(n);
    tin.resize(n);
    tout.resize(n);
    parent.resize(n);
    dfs(0, -1, 0);
    vector<int> to_st(vec.size());
    for (int i = 0; i < (int)vec.size(); i++)
        to_st[i] = height[vec[i]];
    st = sparse_table(to_st);
}

int lca(int u, int v)
{
    int a = min(first[u], first[v]);
    int b = max(first[u], first[v]);
    return vec[st.get(a, b + 1)];
}

int dist(int u, int v) {
    return height[u] + height[v] - 2 * height[lca(u, v)];
}

bool is_child(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int c1 = 0, c2 = 0, x = 0;
int add_vertex(int v) {
    if (c1 == c2) {
        if (dist(c1, v) == x + 1) {
            x++;            
            if (is_child(c1, v)) {
                auto it = upper_bound(graph[c1].begin(), graph[c1].end(), v, [](const int& i, const int& j) -> bool {return tin[i] < tin[j];});
                assert(it != graph[c1].begin());
                it--;
                c2 = *it;
            } else {
                c2 = parent[c1];
            }
        }
    } else {
        if (dist(c1, v) == x + 1) {
            c1 = c2;
        } else if (dist(c2, v) == x + 1) {
            c2 = c1;
        }
    }
    if (c1 == c2) {
        return 2 * x;
    } else {
        return 2 * x - 1;
    }
}

int main() {
    cin >> n;
    graph.resize(n);
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        a--;
        graph[a].push_back(i);
        graph[i].push_back(a);
    }
    precalc_lca();
    for (int i = 1; i < n; i++) {
        cout << add_vertex(i) << " ";
    }
    cout << endl;
    return 0;
}