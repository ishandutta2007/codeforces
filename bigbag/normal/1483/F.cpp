/**
 *  created: 30/03/2021, 18:57:48
**/

#include <bits/stdc++.h>

using namespace std;

class AhoCorasick {
public:
    static const int min_c = 'a', max_c = 'z';

    struct Node {
    friend class AhoCorasick;
        int parent, parent_c;
        bool is_terminal; // optional

        Node(int parent, int parent_c): suffix_link(-1), parent(parent), parent_c(parent_c),
                                        closest_terminal(-1), is_terminal(false) {
            memset(nxt, -1, sizeof(nxt));
        }

    private:
        int nxt[max_c - min_c + 1], suffix_link;
        int closest_terminal; // optional
    };

    vector<Node> nodes;

    AhoCorasick(): nodes({{0, 0}}) {
    }

    AhoCorasick(int max_nodes): nodes({{0, 0}}) {
        nodes.reserve(max_nodes);
    }

    void clear() {
        nodes.clear();
        nodes.push_back({0, 0});
    }

    int add(const string &s) {
        int v = 0;
        for (char cur_c : s) {
            assert(min_c <= cur_c && cur_c <= max_c);
            const int c = cur_c - min_c;
            if (nodes[v].nxt[c] == -1) {
                nodes[v].nxt[c] = nodes.size();
                nodes.push_back({v, c});
            }
            v = nodes[v].nxt[c];
        }
        nodes[v].is_terminal = true;
        return v;
    }

    int get_nxt(int v, int c) {
        assert(min_c <= c && c <= max_c);
        c -= min_c;
        return get_nxt_private(v, c);
    }

    int get_suffix_link(int v) {
        if (nodes[v].suffix_link == -1) {
            if (nodes[v].parent == 0) {
                nodes[v].suffix_link = 0;
            } else {
                nodes[v].suffix_link = get_nxt_private(get_suffix_link(nodes[v].parent), nodes[v].parent_c);
            }
        }
        return nodes[v].suffix_link;
    }

    int get_closest_terminal(int v) {
        if (nodes[v].closest_terminal == -1) {
            if (v == 0) {
                nodes[v].closest_terminal = 0;
            } else if (nodes[v].is_terminal) {
                nodes[v].closest_terminal = v;
            } else {
                nodes[v].closest_terminal = get_closest_terminal(get_suffix_link(v));
            }
        }
        return nodes[v].closest_terminal;
    }

    vector<vector<int>> get_suffix_link_tree() { // note, that edges (from -> to) not necessary satisfy condition from < to
        vector<vector<int>> g(nodes.size());
        for (int i = 1; i < nodes.size(); ++i) {
            g[get_suffix_link(i)].push_back(i);
        }
        return g;
    }

    vector<int> get_bfs_order() {
        queue<int> q;
        vector<int> res;
        vector<char> used(nodes.size());
        q.push(0);
        used[0] = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            res.push_back(v);
            for (int c = 0; c <= max_c - min_c; ++c) {
                if (nodes[v].nxt[c] != -1 && !used[nodes[v].nxt[c]]) {
                    q.push(nodes[v].nxt[c]);
                    used[nodes[v].nxt[c]] = 1;
                }
            }
        }
        return res;
    }

    void calculate_all() { // Optional. Little bit faster and less memory-consumptive then recursive method
        for (int v : get_bfs_order()) {
            get_suffix_link(v);
            get_closest_terminal(v);
            for (int c = 0; c <= max_c - min_c; ++c) {
                get_nxt_private(v, c);
            }
            /*if (v == 0) {
                nodes[v].suffix_link = nodes[v].closest_terminal = 0;
                for (int c = 0; c <= max_c - min_c; ++c) {
                    if (nodes[v].nxt[c] == -1) {
                        nodes[v].nxt[c] = 0;
                    }
                }
            } else {
                if (nodes[v].parent == 0) {
                    nodes[v].suffix_link = 0;
                } else {
                    nodes[v].suffix_link = nodes[nodes[nodes[v].parent].suffix_link].nxt[nodes[v].parent_c];
                }
                if (nodes[v].is_terminal) {
                    nodes[v].closest_terminal = v;
                } else {
                    nodes[v].closest_terminal = nodes[nodes[v].suffix_link].closest_terminal;
                }
                for (int c = 0; c <= max_c - min_c; ++c) {
                    if (nodes[v].nxt[c] == -1) {
                        nodes[v].nxt[c] = nodes[nodes[v].suffix_link].nxt[c];
                    }
                }
            }*/
        }
    }

private:
    int get_nxt_private(int v, int c) {
        if (nodes[v].nxt[c] == -1) {
            if (v == 0) {
                nodes[v].nxt[c] = 0;
            } else {
                nodes[v].nxt[c] = get_nxt_private(get_suffix_link(v), c);
            }
        }
        return nodes[v].nxt[c];
    }
};

const int max_n = 1000111, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

struct Fenwick {
    int a[max_n];

    void update(int i, int x) {
        for (; i < max_n; i = (i | (i + 1))) {
            a[i] += x;
        }
    }

    int get_sum(int r) const {
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res += a[r];
        }
        return res;
    }

    int get_sum(int l, int r) const {
        return get_sum(r) - get_sum(l - 1);
    }
};

int n, terminal_id[max_n], len[max_n];
int curt = -1, tin[max_n], tout[max_n];
string s[max_n];
AhoCorasick aho(max_n);
vector<vector<int>> g;
Fenwick f;

void dfs(int v, int p) {
    tin[v] = ++curt;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
        }
    }
    tout[v] = curt;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        s[i] = read();
    }
    for (int i = 0; i < n; ++i) {
        int v = aho.add(s[i]);
        terminal_id[v] = i;
    }
    aho.calculate_all();
    g = aho.get_suffix_link_tree();
    dfs(0, 0);
    len[0] = -1;
    for (int v : aho.get_bfs_order()) {
        len[v] = len[aho.nodes[v].parent] + 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> all;
        int v = 0;
        vector<pair<int, int>> st;
        st.push_back({-2, -2});
        for (int j = 0; j < s[i].size(); ++j) {
            v = aho.get_nxt(v, s[i][j]);
            int closest_terminal = aho.get_closest_terminal(v);
            if (closest_terminal && terminal_id[closest_terminal] == i) {
                closest_terminal = aho.get_closest_terminal(aho.get_suffix_link(v));
            }
            if (closest_terminal) {
                int pos = j - len[closest_terminal] + 1;
                while (st.back().second >= pos) {
                    st.pop_back();
                }
                st.push_back({j - 1, pos});
                all.push_back(closest_terminal);
            }
        }
        st.push_back({inf, inf});
        v = 0;
        int pos_st = 0;
        set<int> bad_ids;
        for (int j = 0; j < s[i].size(); ++j) {
            while (st[pos_st].first < j) {
                ++pos_st;
            }
            v = aho.get_nxt(v, s[i][j]);
            int closest_terminal = aho.get_closest_terminal(v);
            if (closest_terminal && terminal_id[closest_terminal] == i) {
                closest_terminal = aho.get_closest_terminal(aho.get_suffix_link(v));
            }
            if (closest_terminal && len[closest_terminal] <= j - st[pos_st].second + 1) {
                bad_ids.insert(closest_terminal);
            }
        }
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());
        for (int v : all) {
            f.update(tin[v], 1);
        }
        for (int v : all) {
            ans += f.get_sum(tin[v], tout[v]) == 1 && !bad_ids.count(v);
        }
        for (int v : all) {
            f.update(tin[v], -1);
        }
    }
    printf("%d\n", ans);
    return 0;
}