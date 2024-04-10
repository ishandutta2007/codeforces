#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int secret_1, secret_2;

int dist(int x) { return min(abs(x - secret_1), abs(x - secret_2)); }

// Left is true, right is false
int Q = 0;
bool QUERY(int x, int y) {
    debug(x, y);
    assert(x != y && 1 <= x && 1 <= y);
    Q++;
#ifdef LOCAL
    return dist(x) <= dist(y);
#endif
    cout << 1 << ' ' << x << ' ' << y << endl;
    string ans;
    cin >> ans;
    assert(ans == "TAK" || ans == "NIE");
    return ans == "TAK";
}

void ANSWER(int x, int y) { cout << 2 << ' ' << x << ' ' << y << endl; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
#ifdef LOCAL
    cin >> secret_1 >> secret_2;
    debug(N, K, secret_1, secret_2);
#endif
    auto ternary_search = [&](int L, int R) {
        while (L + 2 < R) {
            int M1 = (2 * L + R) / 3;
            int M2 = (L + 2 * R + 1) / 3;
            if (QUERY(M1, M2)) {
                R = M2;
            } else {
                L = M1;
            }
        }
        debug("ternary", Q);
        return L + 1;
    };
    int A = ternary_search(0, N + 1);
    int B = -1;
    auto advance_right = [&](int& R) {
        assert(A + 1 < R);
        int MA = (A + R - 1) / 2;
        int MR = MA + 1;
        debug(A, MA, MR, R);
        assert(A <= MA && MA < MR && MR < R);
        if (QUERY(MR, MA)) {
            B = ternary_search(MA, R);
        } else {
            R = MR;
        }
    };
    auto advance_left = [&](int& L) {
        assert(L + 1 < A);
        int MA = (L + A + 1) / 2;
        int ML = MA - 1;
        debug(L, ML, MA, A);
        assert(L < ML && ML < MA && MA <= A);
        if (QUERY(ML, MA)) {
            B = ternary_search(L, MA);
        } else {
            L = ML;
        }
    };
    int L = 0, R = N + 1;
    while (B == -1) {
        int Ldist = A - L, Rdist = R - A;
        assert(Ldist > 1 || Rdist > 1);
        assert(Ldist >= 1 && Rdist >= 1);
        if (Ldist > Rdist) {
            advance_left(L);
        } else {
            advance_right(R);
        }
    }
    ANSWER(A, B);
    debug(N, K, A, B, Q);
    return 0;
}