#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename T>
struct tmat { // max
    using vec = vector<T>;
    using unit_type = T;
    static constexpr T ninf = numeric_limits<T>::min() / 2;
    int n, m;
    T* data = nullptr;

    tmat() : n(0), m(0) {}
    tmat(int n, int m, const T& v = ninf) { assign(n, m, v); }
    tmat(const tmat& o) : n(o.n), m(o.m), data(new T[n * m]) {
        copy(o.data, o.data + n * m, data);
    }
    tmat(tmat&& o) : tmat() { *this = move(o); }
    tmat& operator=(const tmat& o) { return *this = tmat(o); }
    tmat& operator=(tmat&& o) noexcept {
        using std::swap;
        swap(n, o.n), swap(m, o.m), swap(data, o.data);
        return *this;
    }
    ~tmat() { delete[] data; }

    bool operator==(const tmat& o) const {
        return n == o.n && m == o.m && equal(data, data + n * m, o.data);
    }
    bool operator!=(const tmat& o) const { return !(*this == o); }

    void assign(int n, int m, const T& v) {
        this->n = n, this->m = m, delete[] data, data = new T[n * m];
        std::fill(data, data + n * m, v);
    }

    array<int, 2> size() const { return {n, m}; }
    T* operator[](int x) const { return data + x * m; }
    T& operator[](array<int, 2> xy) const { return data + (xy[0] * m + xy[1]); }

    template <typename U>
    static tmat from(const vector<vector<U>>& vals) {
        int n = vals.size(), m = n ? vals[0].size() : 0;
        tmat a(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = vals[i][j];
        return a;
    }

    template <typename O = T>
    friend auto tovec(const tmat& a) {
        vector<vector<O>> m(a.n, vector<T>(a.m));
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < a.m; j++)
                m[i][j] = a[i][j];
        return m;
    }

    static tmat identity(int n) {
        tmat a(n, n, ninf);
        for (int i = 0; i < n; i++)
            a[i][i] = 0;
        return a;
    }

    friend tmat transpose(const tmat& a) {
        tmat b(a.m, a.n);
        for (int i = 0; i < a.m; i++)
            for (int j = 0; j < a.n; j++)
                b[i][j] = a[j][i];
        return b;
    }

    friend tmat& operator+=(tmat& a, const tmat& b) {
        assert(a.size() == b.size() && "Different matrix dimensions");
        for (int i = 0, s = a.n * a.m; i < s; i++)
            a[i] = max(a[i], b[i]);
        return a;
    }

    friend tmat operator*(const tmat& a, const tmat& b) {
        assert(a.m == b.n && "Invalid proper matrix multiplication");
        tmat c(a.n, b.m, ninf);
        for (int i = 0; i < a.n; i++)
            for (int k = 0; k < a.m; k++)
                for (int j = 0; j < b.m; j++)
                    c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
        return c;
    }

    friend vec operator*(const tmat& a, const vec& b) {
        assert(a.m == int(b.size()) && "Invalid matrix/vector multiplication");
        vec c(a.n, ninf);
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < a.m; j++)
                c[i] = max(c[i], a[i][j] + b[j]);
        return c;
    }

    friend tmat operator^(tmat a, int64_t e) {
        assert(a.n == a.m && "Matrix exp operand is not square");
        tmat c = tmat::identity(a.n);
        while (e > 0) {
            if (e & 1)
                c = c * a;
            if (e >>= 1)
                a = a * a;
        }
        return c;
    }

    friend tmat operator+(tmat a, const tmat& b) { return a += b; }
    tmat operator*=(const tmat& b) { return *this = *this * b; }
    tmat operator^=(int64_t e) { return *this = *this ^ e; }

    friend string to_string(const tmat& a) {
        vector<vector<string>> cell(a.n, vector<string>(a.m));
        vector<size_t> w(a.m);
        for (int i = 0; i < a.n; i++) {
            for (int j = 0; j < a.m; j++) {
                using std::to_string;
                if constexpr (std::is_same<T, string>::value) {
                    cell[i][j] = a[i][j];
                } else {
                    cell[i][j] = to_string(a[i][j]);
                }
                w[j] = max(w[j], cell[i][j].size());
            }
        }
        string s;
        for (int i = 0; i < a.n; i++) {
            for (int j = 0; j < a.m; j++) {
                s += string(w[j] + 1 - cell[i][j].size(), ' ');
                s += cell[i][j];
            }
            s += '\n';
        }
        return s;
    }

    friend ostream& operator<<(ostream& out, const tmat& a) {
        return out << to_string(a);
    }
    friend istream& operator>>(istream& in, tmat& a) {
        for (int i = 0; i < a.n * a.m; i++)
            in >> a.data[i];
        return in;
    }
};

/**
 * Aho-Corasick string automaton
 * Edit A and chash before using. Add extra preprocessing in the constructor.
 * Requires 4(A+c)S bytes where S=#states and S<=W=#dict length. Not adequate if A>50.
 *
 * Complexity: O(AS+M) construction, O(AS) space, O(N) for main queries.
 * Reference: https://github.com/indy256/codelibrary
 */
template <typename T = char>
struct aho_corasick {
    static constexpr int A = 26;
    static constexpr int chash(T value) { return value - 'a'; }

    struct Node {
        int next[A] = {};
        int parent = 0, len = 0, ch = 0;
        int escape = 0, link = 0; // nearest leaf / suffix link
        int happy = 0;
        Node() = default;
        Node(int parent, int len, int ch) : parent(parent), len(len), ch(ch) {}
    };

    vector<Node> node;

    aho_corasick() = default;

    template <typename Vec>
    explicit aho_corasick(const vector<Vec>& words, const vector<int>& happy) : node(1) {
        for (int i = 0, W = words.size(); i < W; i++) {
            int v = 0, len = 1;
            for (auto value : words[i]) {
                int c = chash(value);
                if (!node[v].next[c]) {
                    node[v].next[c] = num_nodes();
                    node.emplace_back(v, len, c);
                }
                v = node[v].next[c], len++;
            }
            node[v].escape = v;
            // Preprocess: ignore repeated words
            node[v].happy += happy[i];
        }

        vector<int> bfs(num_nodes());
        int s = 0, t = 1;
        while (s < t) {
            int v = bfs[s++], u = node[v].link;
            if (node[v].escape == 0) {
                node[v].escape = node[u].escape;
            }
            for (int c = 0; c < A; c++) {
                int& w = node[v].next[c];
                if (w) {
                    bfs[t++] = w;
                    node[w].link = v ? node[u].next[c] : 0;
                } else {
                    w = node[u].next[c];
                }
            }
            node[v].happy += node[u].happy;
        }
        assert(t == num_nodes());
    }

    int num_nodes() const { return node.size(); }

    // Count number of distinct indices where words end.
    template <typename Vec>
    int count_unique_matches(const Vec& text) const {
        int matches = 0;
        for (int v = 0, i = 0, N = text.size(); i < N; i++) {
            v = node[v].next[chash(text[i])];
            matches += node[v].escape > 0;
        }
        return matches;
    }

    // Count total number of matches across all words and indices
    template <typename Vec>
    long count_matches(const Vec& text) const {
        long matches = 0;
        for (int v = 0, i = 0, N = text.size(); i < N; i++) {
            v = node[v].next[chash(text[i])];
            matches += node[v].nmatches;
        }
        return matches;
    }

    // For each index i, find the longest dictionary word ending at text[i] (inclusive)
    template <typename Vec>
    vector<int> longest_each_index(const Vec& text) const {
        vector<int> longest(text.size(), -1);
        for (int v = 0, i = 0, N = text.size(); i < N; i++) {
            v = node[v].next[chash(text[i])];
            longest[i] = node[node[v].escape].wordid;
        }
        return longest;
    }

    // Call fn(i, wordid) for every match <i, longest wordid>
    template <typename Fn, typename Vec>
    void visit_longest_each_index(const Vec& text, Fn&& fn, bool skipbad = true) const {
        for (int v = 0, i = 0, N = text.size(); i < N; i++) {
            v = node[v].next[chash(text[i])];
            int w = node[node[v].escape].wordid;
            if (w != -1 || !skipbad)
                fn(i, w);
        }
    }

    // Call fn(i, wordid) for every match <i, wordid>
    template <typename Fn, typename Vec>
    void visit_all(const Vec& text, Fn&& fn) const {
        for (int v = 0, i = 0, N = text.size(); i < N; i++) {
            v = node[v].next[chash(text[i])];
            int u = node[v].escape;
            while (u != 0)
                fn(i, node[u].wordid), u = node[node[u].link].escape;
        }
    }

    // Find first occurrence of any dictionary word in text. Returns <i, longest wordid>
    template <typename Vec>
    pair<int, int> find_first(const Vec& text) const {
        for (int v = 0, i = 0, N = text.size(); i < N; i++) {
            v = node[v].next[chash(text[i])];
            int w = node[node[v].escape].wordid;
            if (w != 0)
                return {i, w};
        }
        return {-1, -1};
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    int64_t L;
    cin >> N >> L;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    aho_corasick aho(words, a);
    int S = aho.num_nodes();

    const int64_t inf = INT64_MIN / 4;
    tmat<int64_t> A(S, S, inf);
    for (int s = 0; s < S; s++) {
        for (int c = 0; c < aho_corasick<char>::A; c++) {
            if (int d = aho.node[s].next[c]) {
                A[d][s] = aho.node[d].happy;
            }
        }
    }

    vector<int64_t> b(S, inf);
    b[0] = 0;
    b = (A ^ L) * b;
    int64_t ans = *max_element(begin(b), end(b));
    cout << ans << '\n';
    return 0;
}