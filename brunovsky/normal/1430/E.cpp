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
            sum += tree[i];
            i -= i & -i;
        }
        return sum;
    }

    void add(int i, int n) {
        assert(i > 0);
        while (i <= N) {
            tree[i] += n;
            i += i & -i;
        }
    }

    int sum(int l, int r) { return sum(r) - sum(l - 1); }
};

auto solve() {
    int N;
    string s;
    cin >> N >> s;
    string want = s;
    reverse(begin(want), end(want));

    s = "$" + s;
    want = "$" + want;

    constexpr int A = 26;
    vector<int> index[A];
    for (int i = 1; i <= N; i++) {
        index[s[i] - 'a'].push_back(i);
    }

    fenwick tree(N);

    long ops = 0;
    for (int i = N; i >= 1; i--) {
        int w = want[i] - 'a';
        int original = index[w].back();
        int adjusted = original - tree.sum(original);
        tree.add(original, 1);
        int d = i - adjusted;
        ops += d;
        index[w].pop_back();
    }
    return ops;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}