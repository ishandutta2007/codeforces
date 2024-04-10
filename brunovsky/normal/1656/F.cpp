#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct disjoint_set {
    int N, S;
    vector<int> next, size;

    explicit disjoint_set(int N = 0) : N(N), S(N), next(N), size(N, 1) {
        iota(begin(next), end(next), 0);
    }

    void assign(int n) { *this = disjoint_set(n); }
    void reset() { *this = disjoint_set(N); }
    bool same(int i, int j) { return find(i) == find(j); }
    bool unit(int i) { return i == next[i] && size[i] == 1; }
    bool root(int i) { return find(i) == i; }
    void reroot(int u) {
        if (int r = find(u); u != r) {
            size[u] = size[r];
            next[u] = next[r] = u;
        }
    }

    int find(int i) {
        while (i != next[i]) {
            i = next[i] = next[next[i]];
        }
        return i;
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (size[i] < size[j]) {
                swap(i, j);
            }
            next[j] = i;
            size[i] += size[j];
            S--;
            return true;
        }
        return false;
    }
};

int64_t ceildiv(int64_t A, int64_t B) { return (A + B - 1) / B; }
void setmax(int64_t& a, int64_t b) { a = max(a, b); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int64_t> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(begin(a), end(a));
        int64_t B = 0;
        for (int i = 0; i + 1 < N; i++) {
            B += a[N - 1] + a[i];
        }
        int64_t C = 0;
        for (int i = 1; i < N; i++) {
            C += a[0] + a[i];
        }
        if (B < 0 || C > 0) {
            cout << "INF\n";
            continue;
        }
        if (a[0] == a[N - 1]) {
            assert(a[0] == 0);
            cout << "0\n";
            continue;
        }
        if (N == 2) {
            assert(a[0] == -a[1]);
            cout << a[0] * a[1] << '\n';
            continue;
        }
        int64_t E = a[N - 1] - a[0];
        int64_t A = 0, D = 0;
        for (int i = 0; i + 1 < N; i++) {
            A += a[i] * a[N - 1];
            D += a[i] + a[N - 1];
        }
        assert(D == B);
        int64_t ans = INT64_MIN;
        vector<array<int64_t, 2>> sols;
        sols.push_back({A, D});
        setmax(ans, A + -a[N - 1] * D);
        for (int i = N - 2; i >= 1; i--) {
            A = A - (a[i] * a[N - 1]) + (a[i] * a[0]);
            D = D - E;
            if (i == 1 || a[i] != a[i - 1]) {
                setmax(ans, A + -a[i] * D);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}