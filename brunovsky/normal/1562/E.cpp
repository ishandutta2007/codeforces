#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Node>
struct iterative_segtree {
    int N, Q;
    vector<Node> node;

    iterative_segtree() = default;
    iterative_segtree(int N, Node init) { assign(N, init); }

    template <typename T>
    iterative_segtree(const vector<T>& arr) {
        assign(arr);
    }

    void assign(int N, Node init) {
        this->N = N;
        this->Q = 1 << (N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0);
        node.assign(2 * Q, Node());
        for (int i = 0; i < N; i++) {
            node[i + Q] = init;
        }
        for (int i = Q - 1; i > 0; i--) {
            pushup(i);
        }
    }

    template <typename T>
    void assign(const vector<T>& arr) {
        this->N = arr.size();
        this->Q = 1 << (N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0);
        node.assign(2 * Q, Node());
        for (int i = 0; i < N; i++) {
            node[i + Q] = Node(arr[i]);
        }
        for (int i = Q - 1; i > 0; i--) {
            pushup(i);
        }
    }

    auto query_point(int i) const { return node[i + Q]; }

    template <typename Update>
    void update_point(int i, Update&& update) {
        i += Q;
        apply(i, update);
        for (i >>= 1; i > 0; i >>= 1) {
            pushup(i);
        }
    }

    auto query_range(int L, int R) const {
        Node ans;
        for (int t = R - L; t >= 1; t = R - L) {
            int x = L | ((1U << 31) >> __builtin_clz(t));
            int u = x & (-x);
            int k = __builtin_ctz(x);
            Node v;
            v.pushup(ans, node[(Q | L) >> k]);
            ans = move(v);
            L += u;
        }
        return ans;
    }

    auto query_all() const { return node[1]; }

  private:
    template <typename Update>
    void apply(int u, Update&& update) {
        if constexpr (Node::RANGES) {
            node[u].apply(update, u - Q, u - Q + 1);
        } else {
            node[u].apply(update);
        }
    }
    void pushup(int u) { node[u].pushup(node[u << 1], node[u << 1 | 1]); }
};

template <typename T>
struct max_segnode {
    static constexpr bool RANGES = false, RANGES_MERGE = false;
    static constexpr T MIN = 0;

    T value = MIN;

    max_segnode() = default;
    max_segnode(T v) : value(v) {}
    operator T const &() const { return value; }

    void pushup(const max_segnode& lhs, const max_segnode& rhs) {
        value = max(lhs.value, rhs.value);
    }
    void apply(T add) { value = add; }
};

// you can eliminate duplicates, you would visit them earlier anyway

template <typename Vec>
auto build_cyclic_shifts(const Vec& s) {
    int N = s.size();
    if (N == 0)
        return vector<int>{};

    auto m = *min_element(begin(s), end(s)), M = *max_element(begin(s), end(s));
    int A = M - m + 1;

    int C = 0, S = 1; // #classes - 1, sorted width
    vector<int> cnt(max(A, N), 0), sa(N, 0), clazz(N, 0), perm(N, 0), clazzn(N, 0);

    for (int i = 0; i < N; i++)
        cnt[s[i] - m]++;
    for (int a = 1; a < A; a++)
        cnt[a] += cnt[a - 1];
    for (int i = N - 1; i >= 0; i--)
        sa[--cnt[s[i] - m]] = i;
    for (int i = 1; i < N; i++)
        clazz[sa[i]] = C += s[sa[i]] != s[sa[i - 1]];

    while (S < N) {
        for (int i = 0; i < N; i++)
            perm[i] = sa[i] - S, perm[i] += perm[i] < 0 ? N : 0;
        for (int c = 0; c <= C; c++)
            cnt[c] = 0;
        for (int i = 0; i < N; i++)
            cnt[clazz[perm[i]]]++;
        for (int a = 1; a <= C; a++)
            cnt[a] += cnt[a - 1];
        for (int i = N - 1; i >= 0; i--) // backwards for stable sort
            sa[--cnt[clazz[perm[i]]]] = perm[i];

        if (2 * S >= N)
            break;

        clazzn[sa[0]] = C = 0;
        for (int i = 1; i < N; i++) {
            int j = sa[i] + S;
            int k = sa[i - 1] + S;
            j -= j >= N ? N : 0;
            k -= k >= N ? N : 0;
            C += clazz[k] != clazz[j] || clazz[sa[i]] != clazz[sa[i - 1]];
            clazzn[sa[i]] = C;
        }
        swap(clazz, clazzn);
        S *= 2;
    }

    return sa;
}

/**
 * Compute the LCP array for string s and its suffix/cyclic shifts array.
 * LCP[i] = longest common prefix(sa[i], sa[i+1]) for i=0,...,N-1.
 *
 * Complexity: O(N)
 */
template <typename Vec>
auto build_lcp_array(const Vec& s, const vector<int>& sa) {
    int N = s.size();
    vector<int> rank(N, 0), lcp(N, 0);
    for (int i = 1; i < N; i++) {
        rank[sa[i]] = i;
    }
    for (int i = 0, len = 0; i < N; lcp[rank[i++]] = len, len && len--) {
        if (rank[i] + 1 < N) {
            int j = sa[rank[i] + 1] + len;
            int k = i + len;
            j -= j >= N ? N : 0;
            k -= k >= N ? N : 0;
            while (len < N && s[j] == s[k]) {
                len++, j++, k++;
                j -= j >= N ? N : 0;
                k -= k >= N ? N : 0;
            }
        }
    }
    if (N > 0) {
        lcp[N - 1] = s[sa[0]] == s[sa[N - 1]] ? N : 0; // wrap around
    }
    return make_pair(move(lcp), move(rank));
}

template <typename Fun>
class y_combinator_result {
    Fun fun_;

  public:
    template <typename T>
    explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

    template <typename... Args>
    decltype(auto) operator()(Args&&... args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <typename Fun>
auto y_combinator(Fun&& fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    // I'm retarded :D
    while (T--) {
        int N;
        string s;
        cin >> N >> s;
        s += "$";

        auto sa = build_cyclic_shifts(s);
        auto [lcp, rank] = build_lcp_array(s, sa);

        iterative_segtree<max_segnode<int>> st(N, 0);

        // D: how many characters to process as minimum
        y_combinator([&](auto self, int L, int R, int D) -> void {
            if (L + 1 == R) {
                int k = N - (sa[L] + D) + 1;
                if (k > 0) {
                    int before = st.query_range(0, sa[L] + 1);
                    st.update_point(sa[L], before + k);
                }
                return;
            }
            int a = L, b = a + 1;
            while (a < R) {
                while (b < R && lcp[b - 1] >= D) {
                    b++;
                }
                vector<int> sas(b - a);
                for (int i = a; i < b; i++) {
                    sas.push_back(sa[i]);
                }
                sort(rbegin(sas), rend(sas));
                for (int i = a; i < b; i++) {
                    int j = sas[i - a];
                    if (j + D <= N) {
                        int before = st.query_range(0, j + 1);
                        st.update_point(j, before + 1);
                    }
                }
                self(a, b, D + 1);
                a = b, b++;
            }
        })(1, N + 1, 1);

        cout << st.query_all() << '\n';
    }
    return 0;
}