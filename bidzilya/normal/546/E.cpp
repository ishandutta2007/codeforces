#include <bits/stdc++.h>
using namespace std;

const int kInf = 1e9;

struct Edge
{
    int from;
    int to;
    int f;
    int c;
    Edge* rev;
};

int n;
vector<vector<Edge*> > g;
int start;
int finish;

void AddEdge(int v1, int v2, int c)
{
    Edge* forw = new Edge();
    forw->from = v1;
    forw->to = v2;
    forw->f = 0;
    forw->c = c;
    
    Edge* backw = new Edge();
    backw->from = v2;
    backw->to = v1;
    backw->f = 0;
    backw->c = 0;
    
    forw->rev = backw;
    backw->rev = forw;
    g[v1].push_back(forw);
    g[v2].push_back(backw);
}

void RelaxAlongEdge(Edge* edge, int f)
{
    edge->f += f;
    edge->rev->f -= f;
}

int RelaxAlongPath(const vector<Edge*> edges)
{
    int mx = edges[0]->c - edges[0]->f;
    for (int i = 1; i < (int) edges.size(); ++i) {
        mx = min(mx, edges[i]->c - edges[i]->f);
    }
    for (int i = 0; i < (int) edges.size(); ++i) {
        RelaxAlongEdge(edges[i], mx);
    }
    return mx;
}

int in, m;
vector<int> a;
vector<int> b;

vector<vector<int> > ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> in >> m;
    a.resize(in);
    b.resize(in);
    int s1 = 0;
    for (int i = 0; i < in; ++i) {
        cin >> a[i];
        s1 += a[i];
    }
    int s2 = 0;
    for (int i = 0; i < in; ++i) {
        cin >> b[i];
        s2 += b[i];
    }
    if (s1 != s2) {
        cout << "NO" << endl;
        return 0;
    }
    n = 1 + in + in + 1;
    g.resize(n);
    start = 0;
    finish = n - 1;
    for (int i = 0; i < in; ++i) {
        AddEdge(start, 1 + i, a[i]);
    }
    for (int i = 0; i < in; ++i) {
        AddEdge(1 + in + i, finish, b[i]);
    }
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1; --v2;
        AddEdge(1 + v1, 1 + in + v2, kInf);
        AddEdge(1 + v2, 1 + in + v1, kInf);
    }
    for (int i = 0; i < in; ++i) {
        AddEdge(1 + i, 1 + in + i, kInf);
    }
    int max_flow = 0;
    while (true) {
        vector<Edge*> pr(n, nullptr);
        queue<int> q;
        vector<int> used(n, false);
        q.push(start);
        used[start] = true;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            for (int i = 0; i < (int) g[v].size(); ++i) {
                Edge* cur = g[v][i];
                if (cur->f < cur->c) {
                    int u = cur->to;
                    if (!used[u]) {
                        pr[u] = cur;
                        used[u] = true;
                        q.push(u);
                    }
                }
            }
        }
        if (pr[finish] == nullptr) {
            break;
        }
        vector<Edge*> path;
        for (int v = finish; pr[v] != nullptr; v = pr[v]->from) {
            path.push_back(pr[v]);
        }
        reverse(path.begin(), path.end());
        max_flow += RelaxAlongPath(path);
    }
    if (max_flow != s1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    ans.assign(n, vector<int>(in, 0));
    for (int v1 = 0; v1 < in; ++v1) {
        int id1 = 1 + v1;
        for (int i = 0; i < (int) g[id1].size(); ++i) {
            Edge* cur = g[id1][i];
            int v2 = cur->to - in - 1;
            if (v2 >= 0 && v2 < in && cur->f > 0) {
                ans[v1][v2] += cur->f;
            }
        }
    }
    for (int v2 = 0; v2 < in; ++v2) {
        int id2 = 1 + in + v2;
        for (int i = 0; i < (int) g[id2].size(); ++i) {
            Edge* cur = g[id2][i];
            int v1 = cur->to - 1;
            if (v1 >= 0 && v1 < in && cur->f > 0) {
                ans[v1][v2] -= cur->f;
            }
        }
    }
    for (int i = 0; i < in; ++i) {
        for (int j = 0; j < in; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}