#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

template <typename Vec, typename T = typename Vec::value_type>
auto build_cyclic_shifts(const Vec& s) {
    int N = s.size();
    if (N == 0)
        return vector<int>{};

    int m = *min_element(begin(s), end(s)), M = *max_element(begin(s), end(s));
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
    return lcp;
}

template <typename T>
struct min_rmq {
    vector<vector<T>> jmp;

    min_rmq() = default;
    explicit min_rmq(const vector<T>& v) : jmp(1, v) {
        for (int len = 1, k = 1, N = v.size(); 2 * len <= N; len *= 2, ++k) {
            int J = N - 2 * len + 1;
            jmp.emplace_back(J);
            for (int j = 0; j < J; j++) {
                const auto& l = jmp[k - 1][j];
                const auto& r = jmp[k - 1][j + len];
                jmp[k][j] = l < r ? l : r; // prefers last
            }
        }
    }

    T query(int a, int b) const /* [a,b) */ {
        static constexpr int BITS = CHAR_BIT * sizeof(int) - 1;
        assert(a < b); // or return inf if a == b
        int bits = BITS - __builtin_clz(b - a);
        const auto& l = jmp[bits][a];
        const auto& r = jmp[bits][b - (1 << bits)];
        return l < r ? l : r;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    string s;
    cin >> N >> Q >> s;

    s += '$';

    auto sa = build_cyclic_shifts(s);
    auto lcp = build_lcp_array(s, sa);
    debug(sa);
    debug(lcp);
    // lcp[0] is the dollar

    min_rmq<int> rmq(lcp);

    vector<int> rank(N + 1);
    for (int i = 0; i <= N; i++) {
        rank[sa[i]] = i;
    }
    debug(rank);

    vector<int> len(N + 1);
    for (int i = 0; i <= N; i++) {
        len[rank[i]] = N - i;
    }
    debug(len);

    for (int q = 0; q < Q; q++) {
        int A, B;
        cin >> A >> B;
        vector<int> a(A), b(B);
        for (int i = 0; i < A; i++) {
            cin >> a[i], a[i] = rank[a[i] - 1];
        }
        for (int i = 0; i < B; i++) {
            cin >> b[i], b[i] = rank[b[i] - 1];
        }
        sort(begin(a), end(a));
        sort(begin(b), end(b));
        debug(q, a, b);

        // so we must consider
        // a[i]<b[i], a[i]=b[i], a[i]>b[i]
        // solve these separately?
        // (1) for a[i]<b[i] the lcp is rmq.query(a[i],b[i])
        // (2) for a[i]>b[i] the lcp is rmq.query(b[i],a[i])
        // (3) for a[i]=b[i] the lcp is len[a[i]]

        long sum = 0;
        long window = 0;
        priority_queue<pair<int, int>> pq;

        // (1) a[i] < b[i]
        pq = priority_queue<pair<int, int>>();
        window = 0;
        for (int i = A - 1, j = B - 1; i >= 0; i--) {
            while (j >= 0 && a[i] < b[j]) {
                if (a[i] != b[j]) {
                    int common = rmq.query(a[i], b[j]);
                    window += common;
                    pq.emplace(common, 1);
                }
                j--;
            }
            sum += window;
            if (i > 0) {
                int m = rmq.query(a[i - 1], a[i]);
                int total = 0;
                while (!pq.empty() && pq.top().first >= m) {
                    auto [hi, cnt] = pq.top();
                    window -= 1LL * cnt * hi;
                    total += cnt;
                    pq.pop();
                }
                window += 1LL * m * total;
                pq.emplace(m, total);
            }
        }

        // (2) a[i] > b[i]
        pq = priority_queue<pair<int, int>>();
        window = 0;
        for (int i = 0, j = 0; i < A; i++) {
            while (j < B && b[j] < a[i]) {
                if (a[i] != b[j]) {
                    int common = rmq.query(b[j], a[i]);
                    window += common;
                    pq.emplace(common, 1);
                }
                j++;
            }
            sum += window;
            if (i + 1 < A) {
                int m = rmq.query(a[i], a[i + 1]);
                int total = 0;
                while (!pq.empty() && pq.top().first >= m) {
                    auto [hi, cnt] = pq.top();
                    window -= 1LL * cnt * hi;
                    total += cnt;
                    pq.pop();
                }
                window += 1LL * m * total;
                pq.emplace(m, total);
            }
        }

        // (3) a[i] = b[i]
        int ai = 0, bi = 0;
        while (ai < A && bi < B) {
            if (a[ai] == b[bi]) {
                sum += len[a[ai]];
                ai++, bi++;
            } else if (a[ai] < b[bi]) {
                ai++;
            } else {
                bi++;
            }
        }

        cout << sum << '\n';
    }

    return 0;
}