#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

// For each i, we have a[i], we want to know who will invite us
// Must be j such that a[j]>a[i] and a[i]&a[j]=0
// Invert it, we just visited j
// Which a[i] with a[i]<a[j] are going to be invited by j?
// Those where the bits set in a[j] are all 0
// Invert all the bits in a[i], then a[j] is a proper subset of a[i]
// So fix the kid a[i] and iterate over all its proper submasks

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

void setmax(int& a, int b) { a = max(a, b); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(rbegin(a), rend(a));
    int B = 1;
    while (B <= a[0]) {
        B *= 2;
    }
    int64_t A = accumulate(begin(a), end(a), 0LL);

    disjoint_set dsu(B);
    int64_t ans = 0;

    vector<int> cnt(B);
    for (int n : a) {
        cnt[n]++;
    }

    for (int s = B - 1; s >= 1; s--) {
        for (int a = s; a > 0; a = s & (a - 1)) {
            int b = s ^ a;
            if (cnt[a] && cnt[b] && dsu.join(a, b)) {
                ans += int64_t(cnt[a] + cnt[b] - 1) * (a + b);
                cnt[a] = cnt[b] = 1;
            }
        }
        int a = s, b = 0;
        if (cnt[a] && cnt[b] && dsu.join(a, b)) {
            ans += int64_t(cnt[a] + cnt[b] - 1) * (a + b);
            cnt[a] = cnt[b] = 1;
        }
    }

    debug(ans, A);
    cout << ans - A << '\n';
    return 0;
}