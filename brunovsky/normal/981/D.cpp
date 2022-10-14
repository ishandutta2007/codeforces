#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

constexpr int MAXN = 51;
long rangesum[MAXN][MAXN];
bool can[MAXN][MAXN]; // can[r][k]: can reach position r with k shelves filled

using int2 = array<int, 2>;

struct sort_ranges {
    bool operator()(int2 a, int2 b) const {
        return make_pair(a[1], a[0]) < make_pair(b[1], b[0]);
    }
};

auto solve() {
    int N, K;
    cin >> N >> K;
    vector<long> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int l = 1; l <= N; l++) {
        for (int r = l; r <= N; r++) {
            rangesum[l][r] = rangesum[l][r - 1] + A[r];
        }
    }

    long Q = 1, b = 0;
    while (2 * Q <= rangesum[1][N])
        Q <<= 1, b++;

    long ans = 0;
    while (b >= 0) {
        // Let's try to add 1 << b
        long want = ans | (1LL << b);

        set<array<int, 2>, sort_ranges> ranges;
        for (int l = 1; l <= N; l++) {
            for (int r = l; r <= N; r++) {
                if ((rangesum[l][r] & want) == want) {
                    ranges.insert({l, r});
                }
            }
        }

        memset(can, 0, sizeof(can));
        can[0][0] = true;

        for (auto [l, r] : ranges) {
            for (int k = 1; k <= K; k++) {
                can[r][k] |= can[l - 1][k - 1];
            }
        }

        if (can[N][K]) {
            ans = want;
        }
        b--;
    }
    return ans;
}

// *****

int main() {
    cout << solve() << endl;
    return 0;
}