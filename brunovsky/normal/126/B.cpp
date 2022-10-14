#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

inline namespace {

template <typename Vec = string, typename T = typename Vec::value_type>
struct sparse_suffix_automaton {
    // We do not need alphabet size :)
    static constexpr int chash(T value) { return value - 'a'; }

    struct Node {
        int len = 0, link = 0;
        int ch = 0;
        int numpos = 0;
        bool terminal = false;
        Node() = default;
        Node(int len, int ch) : len(len), ch(ch) {}
        Node(const Node& o, int len, int ch) : Node(o) { this->len = len, this->ch = ch; }
    };
    struct Edge {
        int ch = -1, node = 0;
        Edge() = default;
        Edge(int ch, int node) : ch(ch), node(node) {}
    };

    int V, E, last = 1; // node[0] is empty; last is id of node with entire string
    vector<Node> node;
    vector<Edge> edge;
    vector<int> head, next, pi;

    sparse_suffix_automaton() : V(2), E(1), node(2), edge(1), head(2, 0), next(1, 0) {}
    explicit sparse_suffix_automaton(const Vec& s) : sparse_suffix_automaton() {
        auto S = s.size();
        head.reserve(2 * S + 2), node.reserve(2 * S + 2);
        next.reserve(3 * S + 2), edge.reserve(3 * S + 2);
        for (char c : s) {
            extend(c);
        }
        toposort();
        preprocess();
    }

    int num_nodes() const { return V; }
    int num_edges() const { return E; }

    int extend(const T& value) {
        int c = chash(value), p = last;
        int v = add_node(node[p].len + 1, c);
        while (p && !get_link(p, c)) {
            add_link(p, c, v), p = node[p].link;
        }
        if (p == 0)
            node[v].link = 1;
        else {
            int q = get_link(p, c);
            if (node[p].len + 1 == node[q].len)
                node[v].link = q;
            else {
                int u = clone_node(q, node[p].len + 1, c);
                while (p && get_link(p, c) == q) {
                    set_link(p, c, u), p = node[p].link;
                }
                node[q].link = node[v].link = u;
            }
        }
        return last = v;
    }

    int get_link(int u, int c) const {
        int e = head[u];
        while (e && edge[e].ch != c) {
            e = next[e];
        }
        return edge[e].node;
    }
    int set_link(int u, int c, int v) {
        int e = head[u];
        while (e && edge[e].ch != c) {
            e = next[e];
        }
        return assert(e), edge[e].node = v, e;
    }
    int add_link(int u, int c, int v) {
        return next.push_back(head[u]), edge.emplace_back(c, v), head[u] = E++;
    }
    int add_node(int len, int ch) {
        return node.emplace_back(len, ch), head.push_back(0), V++;
    }
    int clone_node(int u, int len, int ch) {
        node.push_back(node[u]), head.push_back(0);
        for (int e = head[u]; e; e = next[e]) {
            add_link(V, edge[e].ch, edge[e].node);
        }
        node[V].len = len, node[V].ch = ch;
        return V++;
    }

    void toposort() {
        vector<int> cnt(node[last].len + 1), pos(V);
        pi.resize(V);

        for (int v = 0; v < V; v++)
            cnt[node[v].len]++;
        for (int len = 1; len <= node[last].len; len++)
            cnt[len] += cnt[len - 1];
        for (int v = V - 1; v >= 0; v--)
            pos[v] = --cnt[node[v].len];
        for (int v = 0; v < V; v++)
            pi[pos[v]] = v;

        // topological order: pi[0], pi[1], pi[2], ...
    }

    void preprocess() {
        // numpos: number of positions where state v can be found.
        for (int i = V - 1, v = pi[i]; i >= 1; i--, v = pi[i]) {
            node[v].numpos++;
            node[node[v].link].numpos += node[v].numpos;
        }
        node[0].numpos = 0;

        // terminal: whether a state is terminal (corresponds to a suffix)
        int u = last;
        do {
            node[u].terminal = true, u = node[u].link;
        } while (u > 1);
    }

    int get_state(const Vec& word) const {
        int v = 1;
        for (int i = 0, W = word.size(); i < W && v; i++) {
            v = get_link(v, chash(word[i]));
        }
        return v;
    }

    int longest_prefix(const Vec& word) const {
        int best = 0;
        for (int v = 1, i = 0, W = word.size(); i < W; i++) {
            v = get_link(v, chash(word[i]));
            if (v == 0 || node[v].len != i + 1) {
                return best;
            } else if (node[v].terminal && node[v].numpos >= 3) {
                best = i + 1;
            }
        }
        return best;
    }
};

template <typename T>
string to_string(const vector<T>& v) {
    string s;
    for (const auto& el : v)
        s += to_string(el) + " ";
    return s.empty() ? s : (s.pop_back(), s);
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    return out << to_string(v);
}

template <typename Vec>
vector<int> build_z_function(const Vec& s) {
    int N = s.size();
    vector<int> z(N);
    for (int i = 1, l = 0, r = 0; i < N; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < N && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r + 1)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

} // namespace

auto solve_z_function() {
    string s;
    getline(cin, s);
    auto z = build_z_function(s);
    int S = s.size();
    int longest = 0;
    for (int i = 1; i < S; i++) {
        if (z[i] == S - i && longest >= z[i]) {
            return s.substr(0, S - i);
        } else {
            longest = max(longest, z[i]);
        }
    }
    return "Just a legend"s;
}

auto solve_suffix_automaton() {
    string s;
    getline(cin, s);
    sparse_suffix_automaton sa(s);
    int n = sa.longest_prefix(s);
    return n ? s.substr(0, n) : "Just a legend"s;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve_suffix_automaton() << endl;
    return 0;
}