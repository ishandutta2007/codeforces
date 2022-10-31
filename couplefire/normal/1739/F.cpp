#include <bits/stdc++.h>
using namespace std;

const int C = 12;
const int N = 1005;

struct DSU {
    int fa[C], siz[C];

    DSU() {
        for (int i = 0; i<C; ++i) {
            fa[i] = i;
            siz[i] = 1;
        }
    }

    int find(int v) {
        return fa[v]==v ? fa[v] : fa[v] = find(fa[v]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (siz[a] > siz[b]) {
            swap(a, b);
        }
        if (a == b) {
            return true;
        }
        fa[a] = b;
        siz[b] += siz[a];
        return false;
    }
};

struct AC {
    struct Node {
        array<int, C> to;
        int link = -1;
        int word_link = -1;
        int id = -1;
    };
    vector<Node> nodes = {{}};

    int add(string s, int id) {
        int v = 0;
        for (auto c : s) {
            c = c-'a';
            if (!nodes[v].to[c]) {
                nodes[v].to[c] = nodes.size();
                nodes.emplace_back();
            }
            v = nodes[v].to[c];
        }
        nodes[v].id = id;
        return v;
    }

    void init() {
        nodes[0].link = -1;
        queue<int> q;
        q.push(0);
        
        while (q.size()) {
            int v = q.front();
            q.pop();

            for (int c = 0; c<C; ++c) {
                int u = nodes[v].to[c];
                if (!u) {
                    continue;
                }
                nodes[u].link = nodes[v].link == -1 ? 0 : nodes[nodes[v].link].to[c];
                nodes[u].word_link = nodes[nodes[u].link].id == -1 ? nodes[nodes[u].link].word_link : nodes[u].link;
                q.push(u);
            }
            if (v) {
                for (int c = 0; c<C; ++c) {
                    if (!nodes[v].to[c]) {
                        nodes[v].to[c] = nodes[nodes[v].link].to[c];
                    }
                }
            }
        }
    }
} ac;

int n;
int costs[N];
string words[N];
bool valid[N];
map<string, int> bruh_id;

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i<n; ++i) {
        cin >> costs[i] >> words[i];
    }

    fill(valid, valid+N, 1);
    for (int i = 0; i<n; ++i) {
        vector<bitset<C>> adj(C, bitset<C>(0));
        DSU dsu = DSU();
        for (int j = 0; j<(int)words[i].size()-1; ++j) {
            int a = words[i][j]-'a', b = words[i][j+1] - 'a';
            if (dsu.unite(a, b) && !adj[a][b]) {
                valid[i] = false;
                break;
            }
            adj[a][b] = adj[b][a] = 1;
        }
        for (int j = 0; j<C; ++j) {
            if (adj[j].count() >= 3) {
                valid[i] = false;
                break;
            }
        }
        if (!valid[i]) {
            continue;
        }
        bitset<C> visited;
        int v = -1;
        for (int j = 0; j<C; ++j) {
            if (adj[j].count() == 1) {
                v = j;
                break;
            }
        }
        assert(v != -1);
        string res = "";
        while(v != -1) {
            visited[v] = 1;
            res += char('a'+v);
            int nxt = -1;
            for (int j = 0; j<C; ++j) {
                if (!visited[j] && adj[v][j]) {
                    nxt = j;
                    break;
                }
            }
            swap(v, nxt);
        }
        words[i] = res;
    }
    
    for (int i = 0; i<n; ++i) {
        if (valid[i]) {
            string tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            if (bruh_id.count(words[i]) || bruh_id.count(tmp)) {
                costs[bruh_id[words[i]]] += costs[i];
                continue;
            }
            ac.add(words[i], i);
            ac.add(tmp, i);
            bruh_id[words[i]] = bruh_id[tmp] = i;
        }
    }
    ac.init();
    int m = ac.nodes.size();

    vector<array<int, 1<<C>> dp(m), best_char(m);
    for (int mask = 0; mask < (1<<C); ++mask) {
        for (int i = 0; i<m; ++i) {
            int cur = i;
            while (cur >= 0) {
                if (ac.nodes[cur].id != -1) {
                    dp[i][mask] += costs[ac.nodes[cur].id];
                }
                cur = ac.nodes[cur].word_link;
            }
            best_char[i][mask] = -1;
            int best = 0;
            for (int c = 0; c<C; ++c) {
                if (mask & (1<<c)) {
                    if (dp[ac.nodes[i].to[c]][mask ^ (1<<c)] >= best) {
                        best_char[i][mask] = c;
                    }
                    best = max(best, dp[ac.nodes[i].to[c]][mask ^ (1<<c)]);
                }
            }
            dp[i][mask] += best;
        }
    }
    int v = 0, mask = (1<<C)-1;
    for (int i = 0; i<C; ++i) {
        int c = best_char[v][mask];
        cout << char('a'+c);
        mask ^= (1<<c);
        v = ac.nodes[v].to[c];
    }
    cout << '\n';
}