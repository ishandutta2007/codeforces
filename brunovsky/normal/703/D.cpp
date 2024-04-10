#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

struct fenwick {
    int N;
    vector<int> tree;

    explicit fenwick(int N = 0) : N(N), tree(N + 1, 0) {}

    int sum(int i) {
        int sum = 0;
        while (i > 0) {
            sum ^= tree[i];
            i -= i & -i;
        }
        return sum;
    }

    void add(int i, int n) {
        if (i > 0) {
            while (i <= N) {
                tree[i] ^= n;
                i += i & -i;
            }
        }
    }
};

auto solve() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    vector<int> pref(N + 1); // pref[i]: [0,i)
    for (int i = 0; i < N; i++) {
        pref[i + 1] = pref[i] ^ A[i + 1];
    }

    int Q;
    cin >> Q;
    vector<array<int, 3>> queries(Q);

    for (int q = 0; q < Q; q++) {
        int L, R;
        cin >> L >> R;
        queries[q] = {L, R, q};
    }

    sort(begin(queries), end(queries),
         [&](auto a, auto b) { return make_pair(a[1], a[0]) < make_pair(b[1], b[0]); });

    vector<int> ans(Q);
    unordered_map<int, int> pos;
    fenwick fw(N);
    for (int i = 0, right = 0; i < Q; i++) {
        auto [L, R, q] = queries[i];
        while (right < R) {
            right++;
            fw.add(pos[A[right]], A[right]);
            fw.add(right, A[right]);
            pos[A[right]] = right;
        }
        ans[q] = pref[L - 1] ^ pref[R] ^ fw.sum(L - 1) ^ fw.sum(R);
    }

    for (int q = 0; q < Q; q++) {
        cout << ans[q] << endl;
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}