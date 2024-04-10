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
int know[MAXN]; // how many ones initially in [1..know[n]].
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
    if (know[r] >= 0) {
        return know[r] + added.sum(r);
    } else {
        int ones = QUERY(r);
        know[r] = ones - added.sum(r);
        return ones;
    }
}

int get_possible(int k) {
    int L = k, R = N;
    while (L <= R) {
        int M = (L + R) / 2;
        int ones = maybe_query(M);
        int zeros = M - ones;
        // fprintf(stderr, "zeros up to %d: %d\n", M, ones);
        if (zeros >= k) {
            R = M - 1;
        } else {
            L = M + 1;
        }
    }
    return L;
}

void scan() {
    int l = 0;
    for (int r = 1; r <= N; r++) {
        if (know[r] >= 0 && r - l > 0) {
            int between = (know[r] + added.sum(r)) - (know[l - 1] + added.sum(l - 1));
            int cells = r - l;
            if (between == 0) {
                // everything is zero
                for (int i = l + 1; i < r; i++) {
                    know[i] = 0;
                }
            } else if (between == cells) {
                // everything is one
                for (int i = l + 1; i < r; i++) {
                    know[i] = 1;
                }
            }
            l = r;
        }
    }
}

auto solve() {
    cin >> N >> Q;
    added = fenwick(N);
    memset(know, 0xff, sizeof(know));
    know[0] = 0;
    int counter = 0;
    while (Q--) {
        int k;
        cin >> k;
        int i = get_possible(k);
        string s = "! " + to_string(i);
        cout << s << endl;
        added.add(i, 1);
        // if (++counter == 300) {
        //     scan();
        //     counter = 0;
        // }
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    cerr << "total queries: " << queries_count << endl;
    return 0;
}