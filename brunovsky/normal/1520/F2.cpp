#include <bits/stdc++.h>

using namespace std;

#define long int64_t
#define DV(a) (" [" #a "=" + to_string(a) + "]")

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

    int lower_bound(int n) {
        int i = 0;
        int bits = CHAR_BIT * sizeof(int) - __builtin_clz(N << 1);
        for (int j = 1 << bits; j; j >>= 1) {
            if (i + j <= N && tree[i + j] < n) {
                n -= tree[i + j];
                i += j;
            }
        }
        return i + 1;
    }
};

#define MAXN        200'010
#define MAX_QUERIES 60'000
int N, Q, queries_count = 0;
int know[MAXN]; // how many ones initially in [1..n].
fenwick added;

// how many ones in positions [1..r]
int QUERY(int r) {
    queries_count++;
    assert(queries_count <= MAX_QUERIES);
    string s = "? 1 " + to_string(r);
    cout << s << endl;
    int ones;
    cin >> ones;
    return ones;
}

// how many ones in positions [1..r]
int maybe_query(int r) {
    if (know[r] < 0) {
        int ones = QUERY(r);
        know[r] = ones - added.sum(r);
    }
    return know[r] + added.sum(r);
}

auto solve() {
    cin >> N >> Q;
    added = fenwick(N + 1);
    memset(know, 0xff, sizeof(know)); // -1
    know[0] = 0;

    while (Q--) {
        int k;
        cin >> k;

        int L = 0, R = N + 1;
        while (L + 1 < R) {
            int M = (L + R) / 2;
            int ones = maybe_query(M);
            int zeros = M - ones;
            if (zeros >= k) {
                R = M;
            } else {
                L = M;
            }
        }
        assert(R <= N);

        string s = "! " + to_string(R);
        cout << s << endl;

        added.add(R, 1);
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    cerr << "Queries: " << queries_count << endl;
    return 0;
}