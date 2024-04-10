#include <bits/stdc++.h>

using namespace std;

using int64 = int64_t;

struct Line {
    int a; int64 b;
    int64 Eval(int x) { return 1LL * a * x + b; }
};
const int64 kInf = 2e18; // Maximum answer (A * x + B)
const int kMin = -1e9, kMax = 1e9; // Bounds of query (x)

struct ConvexTree {
    struct Node { int l, r; Line line; };
    vector<Node> T = { Node{0, 0, {0, -kInf}} };
    int root = 0;
    
    int update(int node, int b, int e, Line upd) {
        if (node == 0) { 
            T.push_back(Node{0, 0, upd});
            return T.size() - 1;
        }
        
        auto& cur = T[node].line;
        if (cur.Eval(b) >= upd.Eval(b) && cur.Eval(e) >= upd.Eval(e))
            return node;
        if (cur.Eval(b) <= upd.Eval(b) && cur.Eval(e) <= upd.Eval(e))
            { cur = upd; return node; }
        
        int m = (b + e) / 2;
        if (cur.Eval(b) < upd.Eval(b)) swap(cur, upd);
        if (cur.Eval(m) >= upd.Eval(m)) {
            int res = update(T[node].r, m + 1, e, upd);
            T[node].r = res; // DO NOT ATTEMPT TO OPTIMIZE
        } else {
            swap(cur, upd);
            int res = update(T[node].l, b, m, upd);
            T[node].l = res; // DO NOT ATTEMPT TO OPTIMIZE
        }
        return node;
    }
    void Update(Line line) { root = update(root, kMin, kMax, line); }

    int64 query(int node, int b, int e, int x) {
        int64 ans = T[node].line.Eval(x);
        if (node == 0) return ans;
        int m = (b + e) / 2;
        if (x <= m) ans = max(ans, query(T[node].l, b, m, x));
        if (x > m) ans = max(ans, query(T[node].r, m + 1, e, x));
        return ans;
    }
    int64 GetMax(int x) { return query(root, kMin, kMax, x); }
};

struct Solver {
    int n;
    vector<int> A, B;
    vector<vector<int>> G;
    vector<int64> dp;

    Solver(vector<int> A, vector<int> B) : 
        n(A.size()), A(A), B(B), G(n), dp(n) {}

    void AddEdge(int a, int b) {
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    struct DFSRet { vector<Line> lines; ConvexTree tree; };
    DFSRet* dfs(int node, int par) {
        DFSRet* ret = new DFSRet();

        bool leaf = true;
        for (auto vec : G[node]) {
            if (vec == par) continue;
            leaf = false;

            auto oth = dfs(vec, node);
            
            if (oth->lines.size() > ret->lines.size())
                swap(ret, oth);

            for (auto line : oth->lines) {
                ret->lines.push_back(line);
                ret->tree.Update(line);
            }
            delete oth;
        }

        dp[node] = (leaf ? 0 : -ret->tree.GetMax(A[node]));
        
        Line nw{-B[node], -dp[node]};
        ret->lines.push_back(nw);
        ret->tree.Update(nw);
        return ret;
    }
        
    vector<int64> Solve() {
        dfs(0, -1);
        return dp;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];
    

    Solver solver(A, B); 
    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        solver.AddEdge(a - 1, b - 1);
    }
    
    auto dp = solver.Solve();
    for (int i = 0; i < n; ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
    
    return 0;
}