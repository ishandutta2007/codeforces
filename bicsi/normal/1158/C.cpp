#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> dataa;
vector<vector<int>> graph;
vector<int> order;
int at = 0;
int n;

void update(int node, int b, int e, int l, int r, int val) {
    l = max(l, b);
    r = min(r, e);
    if (l > r) return;

    if (b == l && e == r) {
        dataa[node].push_back(val);
        return;
    }
    int m = (b + e) / 2;
    update(node * 2, b, m, l, r, val);
    update(node * 2 + 1, m + 1, e, l, r, val);
}

int get(int node, int b, int e, int l) {
    if (dataa[node].size()) {
        int ret = dataa[node].back();
        dataa[node].pop_back();
        return ret;
    }
    if (b == e) return -1;

    int m = (b + e) / 2;
    if (l <= m) return get(node * 2, b, m, l);
    else return get(node * 2 + 1, m + 1, e, l);
}

void DFS(int node) {
//    cerr << "dfs: " << node << " " << endl;
    order[node] = -2;

    while (true) {
        int x = get(1, 1, n, node);
        if (x == -1) break;
        if (order[x] == -1)
            DFS(x);
    }    
    for (auto x : graph[node]) {
        if (order[x] == -1)
            DFS(x);
    }
    order[node] = at--;
}

void Solve() {
    cin >> n;
    graph.assign(n + 1, {});
    order.assign(n + 1, -1);
    dataa.assign(4 * (n + 1), {});

    at = n;

    vector<int> nxt(n + 1);
    vector<int> maxx(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        cin >> nxt[i]; 
        if (nxt[i] != -1) {
            if (nxt[i] <= n)
                graph[i].push_back(nxt[i]);
            maxx[i] = max(maxx[i], nxt[i]);
        }   
    }
  /*  
    for (int i = 1; i <= n; ++i) {
    
        if (nxt[i] != -1 && nxt[i] <= n) {
            cerr << "EDGE: " << i << " -> " << nxt[i] << endl;
        }
        if (maxx[i] != -1) {
            cerr << "EDGE: <" << maxx[i] << " -> " << i << endl;     
        }
    }
    */
    for (int i = 1; i <= n; ++i) {
        if (maxx[i] == -1) continue;
        update(1, 1, n, i + 1, maxx[i] - 1, i);
    }
        
    for (int i = 1; i <= n; ++i) {
        if (order[i] == -1) {
            DFS(i);
        }
    } 
    /*
    for (int i = 1; i <= n; ++i) {
        cerr << order[i] << " ";
    }    
    cerr << endl;
    */
    vector<int> stk;
    for (int i = n; i >= 1; --i) {
        while (stk.size() && order[i] >= order[stk.back()])
            stk.pop_back();
        int j = n + 1;
        if (stk.size()) j = stk.back();
        if (nxt[i] != -1 && nxt[i] != j) {
            //cerr << "fail: " << i << " " << nxt[i] << endl;
            //cerr << "stk shows: " << j << endl;
            //cerr << "stk: "; for (auto x : stk) cerr << x << " "; cerr << endl;
            cout << -1 << '\n';
            return;
        }       
        stk.push_back(i);
    }

    for (int i = 1; i <= n; ++i)
        cout << order[i] << " ";
    cout << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--) {    
        Solve();
    }

    return 0;
}