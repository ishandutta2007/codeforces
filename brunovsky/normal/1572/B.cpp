#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        int ones = count(begin(A), end(A), 1);
        if (ones == N || ones % 2 == 1) {
            cout << "NO\n";
            continue;
        }
        vector<int> bs;
        auto flip = [&](int i, int a, int b, int c) {
            assert(0 <= i && i < N - 2);
            bs.push_back(i);
            int x = A[i] ^ A[i + 1] ^ A[i + 2];
            assert(A[i] == a && A[i + 1] == b && A[i + 2] == c);
            A[i] = A[i + 1] = A[i + 2] = x;
        };
        auto solve = [&](int start = 0) {
            int p = start;
            assert(start < N && A[start] == 0);
            while (p < N) {
                while (p < N && A[p] == 0) {
                    p++;
                }
                if (p == N) {
                    break;
                }
                int l = p, r = p + 1;
                // eliminate consecutive ones using the previous zero
                while (l + 1 < N && A[l] == 1 && A[l + 1] == 1) {
                    flip(l - 1, 0, 1, 1);
                    l += 2;
                }
                // if we're left with a single one
                if (l < N && A[l] == 1) {
                    assert(l + 1 < N && A[l + 1] == 0);
                    while (A[l + 1] == 0 && A[l + 2] == 0) {
                        flip(l, 1, 0, 0), flip(l - 1, 0, 1, 1);
                        l += 2;
                    }
                    if (A[l + 1] == 0 && A[l + 2] == 1) {
                        flip(l, 1, 0, 1);
                        l += 3;
                    }
                }
                p = l;
            }
        };
        if (A[0] == 0) {
            solve();
        } else if (A[N - 1] == 0) {
            reverse(begin(A), end(A));
            solve();
            for (int& b : bs) {
                b = N - 3 - b;
            }
            reverse(begin(A), end(A));
        } else {
            int p = 0;
            int where = -1;
            while (p < N) {
                while (p < N && A[p] == 1) {
                    p++;
                }
                if (p == N) {
                    break;
                }
                if (p % 2 == 0) {
                    where = p;
                    break;
                }
                int l = p, r = p + 1;
                while (r < N && A[r] == 0) {
                    r++;
                }
                int len = r - l;
                if (len % 2 == 1) {
                    for (int i = l; i + 2 < r; i += 2) {
                        flip(i - 1, 1, 0, 0);
                    }
                    flip(r - 2, 1, 0, 1);
                    where = r - 2;
                    break;
                } else {
                    for (int i = l; i < r; i += 2) {
                        flip(i - 1, 1, 0, 0);
                    }
                }
                p = r;
            }
            if (where == -1) {
                cout << "NO\n";
                continue;
            }
            p = where;
            while (p >= 2) {
                flip(p - 2, 1, 1, 0);
                p -= 2;
            }
            solve(where);
        }
        assert(count(begin(A), end(A), 0) == N);
        int B = bs.size();
        cout << "YES\n";
        cout << B << '\n';
        for (int i = 0; i < B; i++) {
            cout << bs[i] + 1 << " \n"[i + 1 == B];
        }
    }
    return 0;
}