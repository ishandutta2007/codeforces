#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

inline namespace {

struct Hasher {
    template <typename Container>
    size_t operator()(const Container& vec) const noexcept {
        using std::hash;
        hash<typename Container::value_type> hasher;
        size_t seed = distance(begin(vec), end(vec));
        for (const auto& n : vec) {
            seed ^= hasher(n) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
    template <typename U, typename V>
    size_t operator()(const pair<U, V>& p) const noexcept {
        using std::hash;
        size_t a = hash<U>{}(p.first), b = hash<V>{}(p.second);
        return (a + b) * (a + b + 1) / 2 + b;
    }
    template <typename U>
    size_t operator()(const array<U, 2>& p) const noexcept {
        using std::hash;
        hash<U> hasher;
        size_t a = hasher(p[0]), b = hasher(p[1]);
        return (a + b) * (a + b + 1) / 2 + b;
    }
    template <int i, typename Tuple>
    size_t tuple_compute(const Tuple& tuple) const noexcept {
        if constexpr (i == std::tuple_size_v<Tuple>) {
            return std::tuple_size_v<Tuple>;
        } else {
            using std::hash;
            hash<std::tuple_element_t<i, Tuple>> hasher;
            size_t seed = tuple_compute<i + 1, Tuple>(tuple);
            size_t h = hasher(std::get<i>(tuple));
            return seed ^ (h + 0x9e3779b9 + (seed << 6) + (seed >> 2));
        }
    }
    template <typename... Ts>
    size_t operator()(const tuple<Ts...>& t) const noexcept {
        return tuple_compute<0, tuple<Ts...>>(t);
    }
};

} // namespace

namespace std {

template <typename T, size_t N>
struct hash<array<T, N>> : Hasher {};
template <typename T>
struct hash<vector<T>> : Hasher {};
template <typename U, typename V>
struct hash<pair<U, V>> : Hasher {};
template <typename... Ts>
struct hash<tuple<Ts...>> : Hasher {};

template <typename U, typename V>
string to_string(const pair<U, V>& uv) {
    return '(' + to_string(uv.first) + ',' + to_string(uv.second) + ')';
}
template <typename U, typename V>
ostream& operator<<(ostream& out, const pair<U, V>& v) {
    return out << to_string(v);
}

template <typename T>
string to_string(const array<T, 2>& uv) {
    return '(' + to_string(uv[0]) + ',' + to_string(uv[1]) + ')';
}
template <typename T, size_t N>
ostream& operator<<(ostream& out, const array<T, N>& v) {
    return out << to_string(v);
}

template <typename T, size_t N>
string to_string(const array<T, N>& v) {
    string s;
    for (const auto& el : v)
        s += to_string(el) + " ";
    return s.empty() ? s : (s.pop_back(), s);
}

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

template <typename T>
string to_string(const vector<vector<T>>& v) {
    string s;
    for (const auto& el : v)
        s += "[" + to_string(el) + "] ";
    return s.empty() ? s : (s.pop_back(), s);
}
template <typename T>
ostream& operator<<(ostream& out, const vector<vector<T>>& v) {
    return out << to_string(v);
}

template <typename T>
string to_string(const list<T>& v) {
    string s;
    for (const auto& el : v)
        s += to_string(el) + " ";
    return s.empty() ? s : (s.pop_back(), s);
}
template <typename T>
ostream& operator<<(ostream& out, const list<T>& v) {
    return out << to_string(v);
}

template <typename T>
string to_string(const set<T>& v) {
    string s;
    for (const auto& el : v)
        s += to_string(el) + " ";
    return s.empty() ? s : (s.pop_back(), s);
}
template <typename T>
ostream& operator<<(ostream& out, const set<T>& v) {
    return out << to_string(v);
}

template <typename T>
string to_string(const unordered_set<T>& v) {
    string s;
    for (const auto& el : v)
        s += to_string(el) + " ";
    return s.empty() ? s : (s.pop_back(), s);
}
template <typename T>
ostream& operator<<(ostream& out, const unordered_set<T>& v) {
    return out << to_string(v);
}

template <typename K, typename V>
string to_string(const map<K, V>& v) {
    string s;
    for (const auto& el : v)
        s += to_string(el) + " ";
    return s.empty() ? s : (s.pop_back(), s);
}
template <typename K, typename V>
ostream& operator<<(ostream& out, const map<K, V>& v) {
    return out << to_string(v);
}

template <typename K, typename V>
string to_string(const unordered_map<K, V>& v) {
    string s;
    for (const auto& el : v)
        s += to_string(el) + " ";
    return s.empty() ? s : (s.pop_back(), s);
}
template <typename K, typename V>
ostream& operator<<(ostream& out, const unordered_map<K, V>& v) {
    return out << to_string(v);
}

} // namespace std

template <typename Compare = less<>>
struct pairing_int_heap {
    struct node_t {
        int parent = 0, child = 0, next = 0, prev = 0;
    };
    vector<node_t> node;
    int root = 0;
    Compare comp;

    explicit pairing_int_heap(int N = 0, const Compare& comp = Compare())
        : node(N + 1), comp(comp) {}

    bool empty() const { return root == 0; }
    bool contains(int u) const { return u++, node[u].parent != 0; }
    int top() const { return root - 1; }

    void push(int u) {
        assert(!contains(u)), u++;
        node[u].parent = -1;
        root = empty() ? u : meld(root, u);
    }
    int pop() {
        assert(!empty());
        int u = root;
        root = two_pass_pairing(u);
        node[u] = node_t();
        return u - 1;
    }
    void improve(int u) {
        assert(!empty() && contains(u)), u++;
        if (u != root && do_comp(u, node[u].parent)) {
            take(u), root = meld(root, u);
        }
    }
    void push_or_improve(int u) { contains(u) ? improve(u) : push(u); }

    void clear() {
        if (!empty()) {
            clear_dive(root), root = 0;
        }
    }

    void erase(int u) {
        assert(contains(u)), u++;
        if (u == root) {
            pop();
        } else {
            take(u);
            int v = two_pass_pairing(u);
            node[u] = node_t();
            if (v) {
                root = meld(root, v);
            }
        }
    }

  private:
    bool do_comp(int u, int v) const { return comp(u - 1, v - 1); }
    int meld(int u, int v) { return do_comp(u, v) ? splice(u, v) : splice(v, u); }
    int splice(int u, int v) {
        node[node[u].child].prev = v;
        node[v].next = node[u].child, node[u].child = v;
        return node[v].prev = node[v].parent = u;
    }
    void take(int u) {
        assert(node[u].parent > 0);
        if (node[node[u].parent].child == u)
            node[node[u].parent].child = node[u].next;
        else
            node[node[u].prev].next = node[u].next;
        node[node[u].next].prev = node[u].prev;
    }
    int two_pass_pairing(int n) {
        if (node[n].child == 0)
            return 0;
        int u = node[n].child, v = node[u].next, w;
        while (v && node[v].next) {
            w = node[node[v].next].next;
            u = node[u].next = v = meld(v, node[v].next);
            v = node[v].next = w;
        }
        u = node[n].child, v = node[u].next;
        while (v) {
            w = node[v].next, u = meld(u, v), v = w;
        }
        return u;
    }
    void clear_dive(int u) {
        for (int v = node[u].child; v; v = node[v].next)
            clear_dive(v);
        node[u] = node_t();
    }
};

struct disjoint_set {
    int N, S;
    vector<int> next, size;

    explicit disjoint_set(int N = 0) : N(N), S(N), next(N), size(N, 1) {
        iota(begin(next), end(next), 0);
    }

    void assign(int N) { *this = disjoint_set(N); }
    bool same(int i, int j) { return find(i) == find(j); }
    bool unit(int i) { return size[find(i)] == 1; }
    bool root(int i) { return find(i) == i; }

    int find(int i) {
        while (i != next[i]) {
            i = next[i] = next[next[i]];
        }
        return i;
    }

    int join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (size[i] < size[j]) {
                swap(i, j);
            }
            next[j] = i;
            size[i] += size[j];
            S--;
        }
        return i;
    }
};

auto solve() {
    int N, E;
    long X;
    cin >> N >> E >> X;

    vector<long> weight(N);
    for (int i = 0; i < N; i++) {
        cin >> weight[i];
    }
    long W = accumulate(begin(weight), end(weight), 0LL);
    if (W < (N - 1) * X) {
        cout << "NO" << endl;
        return;
    }

    vector<unordered_map<int, int>> adj(N);
    vector<array<int, 2>> edges(E);
    for (int e = 0; e < E; e++) {
        auto& [u, v] = edges[e];
        cin >> u >> v, u--, v--;
        adj[u].emplace(v, e);
        adj[v].emplace(u, e);
    }

    auto weight_comp = [&](int u, int v) { return weight[u] > weight[v]; };

    pairing_int_heap heap(N, weight_comp);
    disjoint_set dsu(N);
    vector<int> ans;

    for (int u = 0; u < N; u++) {
        heap.push(u);
    }

    while (dsu.S > 1) {
        int u = heap.top();

        auto [z, e] = *adj[u].begin();
        adj[u].erase(adj[u].begin());

        int v = dsu.find(z);
        if (u != v) {
            ans.push_back(e + 1);
            int root = dsu.join(u, v);
            int old = u != root ? u : v;

            heap.erase(old);
            heap.erase(root);
            weight[root] += weight[old] - X;
            heap.push(root);

            for (auto [w, e] : adj[old]) {
                if (dsu.find(w) != root) {
                    adj[root].emplace(dsu.find(w), e);
                }
            }
            adj[old].clear();
        }
    }

    cout << "YES" << endl;
    for (int e : ans) {
        cout << e << endl;
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}