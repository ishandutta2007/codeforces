#include <bits/stdc++.h>

using namespace std;

// *****

inline void next_lexicographical_mask(unsigned& v) {
    unsigned c = v & -v, r = v + c;
    v = c ? (((r ^ v) >> 2) / c) | r : 0;
}

#define FOR_EACH_BIT(bit, mask)                                                      \
    for (remove_const<decltype(mask)>::type z##bit = (mask), bit = z##bit & -z##bit; \
         z##bit; z##bit ^= bit, z##bit && (bit = z##bit & -z##bit))

#define FOR_EACH_BIT_NUMBER(bit, n, mask)                                            \
    for (remove_const<decltype(mask)>::type z##bit = (mask), bit = z##bit & -z##bit, \
                                            n = __builtin_ctz(bit);                  \
         z##bit;                                                                     \
         z##bit ^= bit, z##bit && (bit = z##bit & -z##bit) && (n = __builtin_ctz(bit)))

#define FOR_EACH_MASK(mask, size, max_size)                                            \
    for (unsigned mask = (1 << (size)) - 1, m##mask = 1 << (max_size); mask < m##mask; \
         next_lexicographical_mask(mask))

auto solve() {
    int N, M;
    string s;
    cin >> N >> M >> s;

    vector<int> letter_freq(M);
    for (char c : s) {
        letter_freq[c - 'a']++;
    }

    vector<vector<int>> weight(M, vector<int>(M));
    for (int i = 1; i < N; i++) {
        int a = s[i] - 'a', b = s[i - 1] - 'a';
        if (a != b) {
            weight[a][b]++, weight[b][a]++;
        }
    }

    vector<int> dp(1 << M, INT_MAX);
    dp[0] = 0;
    for (int mask_size = 1; mask_size <= M; mask_size++) {
        FOR_EACH_MASK (mask, mask_size, M) {
            FOR_EACH_BIT_NUMBER (add_bit, add, mask) {
                int add_cost = 0;
                for (int i = 0; i < M; i++) {
                    if (mask & (1 << i)) {
                        add_cost += weight[add][i] * mask_size;
                    } else {
                        add_cost -= weight[add][i] * mask_size;
                    }
                }
                dp[mask] = min(dp[mask], dp[mask ^ add_bit] + add_cost);
            }
        }
    }
    return dp.back();
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}