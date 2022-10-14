#include <bits/stdc++.h>

using namespace std;

inline void next_lexicographical_mask(int& v) {
    int c = v & -v, r = v + c;
    v = c ? (((r ^ v) >> 2) / c) | r : 0;
}

#define pop(mask) __builtin_popcount(mask)

#define FOR_EACH_MASK(mask, size, max_size)                                       \
    for (int mask = (1 << (size)) - 1, m##mask = 1 << (max_size); mask < m##mask; \
         next_lexicographical_mask(mask))

#define FOR_EACH_SUBSET(subset, mask)                                               \
    for (remove_const<decltype(mask)>::type s##subset = (mask), subset = s##subset, \
                                            break##subset = !s##subset;             \
         !break##subset;                                                            \
         subset ? (subset = s##subset & (subset - 1)) : (break##subset = 1))

#define FOR_EACH_BIT_NUMBER(bit, n, mask)                                            \
    for (remove_const<decltype(mask)>::type z##bit = (mask), bit = z##bit & -z##bit, \
                                            n = __builtin_ctz(bit);                  \
         z##bit;                                                                     \
         z##bit ^= bit, z##bit && (bit = z##bit & -z##bit, n = __builtin_ctz(bit)))

int c[25];
bool tree[1 << 11][25];
bool forest[1 << 11][25];
// dp[mask_big_used][#1s][size]

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    sort(c, c + N);
    int O = count(c, c + N, 1);
    if (O < (N + 2) / 2 || c[N - 1] != N) {
        cout << "NO" << endl;
        return 0;
    }
    int B = N - O;
    for (int i = 0; i < B; i++) {
        c[i] = c[i + O];
    }
    assert(B <= 11);

    vector<vector<int>> bits(N + 1);
    for (int i = 0; i < B; i++) {
        bits[c[i]].push_back(1 << i);
    }

    tree[0][1] = true;
    for (int o = 2; o <= O; o++) {
        forest[0][o] = true;
        for (int bit : bits[o + 1]) {
            tree[bit][o] = true;
        }
    }
    // extend forests of mask size s
    // compute trees of mask size s+1
    for (int size = 1; size < B; size++) {
        FOR_EACH_MASK (mask, size, B) {
            FOR_EACH_SUBSET (as, mask) {
                int bs = as ^ mask;
                if (as < bs) {
                    for (int l = 0; l <= O; l++) {
                        if (forest[as][l] | tree[as][l]) {
                            for (int r = 0; l + r <= O; r++) {
                                forest[mask][l + r] |= forest[bs][r] | tree[bs][r];
                            }
                        }
                    }
                }
            }
            for (int o = 0; o <= O; o++) {
                int s = 1 + pop(mask) + o;
                if (forest[mask][o]) {
                    for (int bit : bits[s]) {
                        tree[bit ^ mask][o] = true;
                    }
                }
            }
        }
        FOR_EACH_MASK (mask, size, B) {
            for (int o = 0; o <= O; o++) {
                forest[mask][o] |= tree[mask][o];
            }
        }
    }

    cout << (tree[(1 << B) - 1][O] ? "YES" : "NO") << endl;
    return 0;
}