#include <bits/stdc++.h>

using namespace std;

const int N = 500 + 7;
const int OO = (int) 1e9;
int n;
int q;
string s;
int a[N];
int par_edge[N];
int best[N];
int x;

struct Edge {
        int to;
        int cap;
        int bonus;
};

vector<Edge> edges;
vector<int> g[N];

void add_edge(int a, int b, int cap, int bonus) {
        g[a].push_back((int) edges.size());
        edges.push_back({b, cap, bonus});
        g[b].push_back((int) edges.size());
        edges.push_back({a, 0, -bonus});
}

struct T {
        int x;
        int b;
};

bool operator < (T a, T b) {
        return a.x < b.x;
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n >> s >> q;
        for (int i = 1; i <= n; i++) {
                a[i] = s[i - 1];
        }
        while (q--) {
                int add;
                string t;
                cin >> t >> add;
                int sz = (int) t.size();
                for (int i = 1; i + sz - 1 <= n; i++) {
                        bool are_equal = 1;
                        for (int k = 0; k < sz; k++) {
                                if (a[i + k] != t[k]) {
                                        are_equal = 0;
                                        break;
                                }
                        }
                        if (are_equal) {
                                int j = i + sz;
                                add_edge(i, j, 1, add);
                        }
                }
        }
        for (int i = 0; i <= n; i++) {
                add_edge(i, i + 1, OO, 0);
        }
        cin >> x;
        int flow = 0, ans = 0;
        while (flow < x) {
                priority_queue<T> pq;
                pq.push({0, 0});
                for (int i = 1; i <= n + 1; i++) {
                        best[i] = -OO;
                }
                while (!pq.empty()) {
                        int a = pq.top().x;
                        int be = pq.top().b;
                        pq.pop();
                        if (be != best[a]) {
                                continue;
                        }
                        for (auto &i : g[a]) {
                                if (edges[i].cap) {
                                        int b = edges[i].to;
                                        int pos = be + edges[i].bonus;
                                        if (pos > best[b]) {
                                                best[b] = pos;
                                                par_edge[b] = i;
                                                pq.push({b, pos});
                                        }
                                }
                        }
                }
                if (best[n + 1] == -OO) {
                        break;
                }
                flow++;
                int a = n + 1;
                while (a) {
                        int i = par_edge[a];
                        edges[i].cap--;
                        edges[i ^ 1].cap++;
                        ans += edges[i].bonus;
                        a = edges[i ^ 1].to;
                }
        }
        cout << ans << "\n";
}