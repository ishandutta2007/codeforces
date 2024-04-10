#include <bits/stdc++.h>

using namespace std;

// *****

default_random_engine mt(random_device{}());
using Mask = long long;

#define CONCAT(x, y) x##y

#define LOOP_FOR_DURATION_IMPL(z, duration)                   \
    auto CONCAT(loop_start, z) = chrono::steady_clock::now(); \
    while (chrono::steady_clock::now() - CONCAT(loop_start, z) < duration)

#define LOOP_FOR_DURATION(in_duration) LOOP_FOR_DURATION_IMPL(__COUNTER__, in_duration)

#define FOR_EACH_SUBSET(subset, mask)                         \
    for (Mask s##subset = (mask), subset = s##subset; subset; \
         subset = s##subset & (subset - 1))

#define FOR_EACH_BIT(bit, mask)                                \
    for (Mask z##bit = (mask), bit = z##bit & -z##bit; z##bit; \
         z##bit ^= bit, z##bit && (bit = z##bit & -z##bit))

#define MASK(c) (1LL << (c))

auto solve() {
    int N, M, P;
    cin >> N >> M >> P;
    vector<Mask> dude(N);
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int c = 0; c < M; c++) {
            dude[i] |= line[c] == '1' ? MASK(c) : 0;
        }
    }

    uniform_int_distribution<int> disti(0, N - 1);
    int best = 0;
    Mask ans = 0;

    LOOP_FOR_DURATION(2s) {
        int n = disti(mt);
        Mask super = dude[n];
        if (super == 0) {
            continue;
        }

        unordered_map<Mask, int> F;
        for (int i = 0; i < N; i++) {
            Mask consider = super & dude[i];
            if (consider) {
                F[consider]++;
            }
        }
        FOR_EACH_BIT (bit, super) {
            FOR_EACH_SUBSET (mask, super) {
                if (mask & bit) {
                    F[mask ^ bit] += F[mask];
                }
            }
        }
        for (auto [mask, k] : F) {
            if (k >= (N + 1) / 2 && mask && __builtin_popcountll(mask) > best) {
                ans = mask;
                best = __builtin_popcountll(ans);
            }
        }
    }

    string ans_str(M, '0');
    for (int c = 0; c < M; c++) {
        if (ans & MASK(c)) {
            ans_str[c] = '1';
        }
    }
    return ans_str;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}