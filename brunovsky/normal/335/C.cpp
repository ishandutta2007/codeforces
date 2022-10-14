#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int R, N;
    cin >> R >> N;
    map<tuple<int, int, int>, int> grundy; // size on the left, size on the right, shifted
    for (int s : {0, 1}) {
        grundy[{0, 0, s}] = 0;
        grundy[{1, 0, s}] = 1;
        grundy[{1, 1, s}] = 1;
        grundy[{2, 0, s}] = 0;
        grundy[{2, 1, s}] = 2;
        grundy[{2, 2, s}] = 0;
    }
#define ADD_GRUNDY(L, LO, R, RO)                              \
    int l = L;                                                \
    int lo = LO;                                              \
    int r = R;                                                \
    int ro = RO;                                              \
    int a = grundy.at({l, lo, 1}), b = grundy.at({r, ro, 1}); \
    int c = a ^ b;                                            \
    if (c <= 2 * K) {                                         \
        seen[c] = true;                                       \
    }
#define SET_GRUNDY(l, lo, s)           \
    for (int i = 0; i <= 2 * K; i++) { \
        if (!seen[i]) {                \
            grundy[{l, lo, s}] = i;    \
            break;                     \
        }                              \
    }
    for (int K = 3; K <= R; K++) {
        // try a cut with length K-2
        //       O A O X X X O O O
        //     O A A A O X O O O O O
        //               6         11
        {
            vector<bool> seen(2 * K + 1);
            // play below
            for (int i = 1; i <= K; i++) {
                ADD_GRUNDY(i - 1, max(0, l - 2), K - i, max(0, r - 2));
            }
            // play above
            for (int i = 1; i <= K - 2; i++) {
                ADD_GRUNDY(i - 1, l, K - 2 - i, r);
            }
            SET_GRUNDY(K, K - 2, 1);
        }
        // try a cut with length K-1
        //        O O X X X O A O
        //        O O O X O A A A O
        {
            vector<bool> seen(2 * K + 1);
            // play below
            for (int i = 1; i <= K; i++) {
                ADD_GRUNDY(i - 1, max(0, l - 1), K - i, max(0, r - 2));
            }
            // play above
            for (int i = 1; i <= K - 1; i++) {
                ADD_GRUNDY(i - 1, max(0, l - 1), K - 1 - i, r);
            }
            SET_GRUNDY(K, K - 1, 1);
            SET_GRUNDY(K, K - 1, 0);
        }
        // try a cut with length K, not shifted
        //        O O X X X O A O O
        //        O O O X O A A A O
        {
            vector<bool> seen(2 * K + 1);
            // play below or above, same thing
            for (int i = 1; i <= K; i++) {
                ADD_GRUNDY(i - 1, max(0, l - 1), K - i, max(0, r - 1));
            }
            SET_GRUNDY(K, K, 0);
        }
        // try a cut with length K, shifted
        //        O O X X X O A O O O
        //      O O O O X O A A A O
        {
            vector<bool> seen(2 * K + 1);
            // play below or above, same thing
            for (int i = 1; i <= K; i++) {
                ADD_GRUNDY(i - 1, max(0, l - 2), K - i, r);
            }
            SET_GRUNDY(K, K, 1);
        }
    }

    // parse the input
    vector<array<bool, 2>> can_play(R + 2, {1, 1});
    for (int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c, c--;
        can_play[r][c] = false;
        can_play[r - 1][!c] = false;
        can_play[r][!c] = false;
        can_play[r + 1][!c] = false;
    }
    int ans_grundy = 0;
    for (int r = 1; r <= R; r++) {
        for (int c : {0, 1}) {
            if (can_play[r][c]) {
                int j = r + 1;
                while (j <= R && can_play[j][c])
                    can_play[j][c] = false, j++;
                int alen = j - r;
                bool shifted = !can_play[r][!c];
                int k = r + 1;
                while (k <= R && can_play[k][!c])
                    can_play[k][!c] = false, k++;
                int blen = !shifted + (k - r - 1);
                debug(alen, blen, r, c);
                if (alen < blen) {
                    swap(alen, blen);
                }
                ans_grundy ^= grundy[{alen, blen, shifted}];
                break;
            }
        }
    }
    if (ans_grundy == 0) {
        cout << "LOSE\n";
    } else {
        cout << "WIN\n";
    }
    return 0;
}

// O O O X O O O X O O O O
// O O X X X O X X X O O O

// O O O O X X X O X X X X X O O O O O
// O O O O O X O O O X X X X X O O O O