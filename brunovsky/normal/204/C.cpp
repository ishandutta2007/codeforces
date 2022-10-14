#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

struct fenwick {
    int N;
    vector<long> tree;

    explicit fenwick(int N = 0) : N(N), tree(N + 1, 0) {}

    long sum(int i) {
        long sum = 0;
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
};

auto solve() {
    int N;
    string a, b;
    cin >> N >> a >> b;
    a = "$" + a;
    b = "$" + b;

    double num = 0;
    long den = 1LL * N * (N + 1) * (2 * N + 1) / 6;

    vector<int> ai[26], bi[26];
    for (int i = 1; i <= N; i++) {
        ai[a[i] - 'A'].push_back(i);
        bi[b[i] - 'A'].push_back(i);
    }

    fenwick sum(N), one(N);

    for (int c = 0; c < 26; c++) {
        for (int i : bi[c]) {
            sum.add(i, i);
            one.add(i, 1);
        }
        long tone = one.sum(N); // lol
        long tsum = sum.sum(N);
        for (int i : ai[c]) {
            long lo = one.sum(i);
            long hi = tone - lo;
            long sum_lo = sum.sum(i);
            long sum_hi = tsum - sum_lo;
            num += i * (hi * (N + 1) - sum_hi); // i < j
            num += sum_lo * (N + 1 - i);        // i >= j
        }
        for (int i : bi[c]) {
            sum.add(i, -i);
            one.add(i, -1);
        }
    }

    return num / den;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << setprecision(9) << fixed << solve() << endl;
    return 0;
}