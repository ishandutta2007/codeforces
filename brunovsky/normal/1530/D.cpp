#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

mt19937 mt(73);
auto stress() {
    uniform_int_distribution<int> distN(4, 10);
    int N = distN(mt);
    uniform_int_distribution<int> distV(0, N - 1);
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        int j = distV(mt);
        while (i == j) {
            j = distV(mt);
        }
        a[i] = j;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
#ifdef OMEGALUL
        auto a = stress();
        int N = a.size();
        debug(N, a);
#else
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i], a[i]--;
        }
#endif

        vector<bool> receives_gift(N);
        vector<int> keep, givers;
        for (int i = 0; i < N; i++) {
            if (receives_gift[a[i]]) {
                givers.push_back(i);
            } else {
                keep.push_back(i);
                receives_gift[a[i]] = true;
            }
        }

        int k = keep.size();
        if (k == N - 1) {
            int i = givers[0];
            if (!receives_gift[i]) {
                for (int j = 0; j < k; j++) {
                    int l = keep[j];
                    assert(i != l);
                    if (a[l] == a[i]) {
                        keep[j] = i;
                        givers[0] = l;
                        break;
                    }
                }
                assert(givers[0] != i);
            }
        }

        vector<bool> is_giver(N);
        for (int i : givers) {
            is_giver[i] = true;
        }

        vector<int> takers, both;
        for (int i = 0; i < N; i++) {
            if (!receives_gift[i]) {
                if (is_giver[i]) {
                    both.push_back(i);
                } else {
                    takers.push_back(i);
                }
            }
        }
        assert(takers.size() + both.size() == givers.size());

        debug(keep, givers, takers, both);

        vector<int> b(N, -1);
        for (int i : keep) {
            b[i] = a[i];
        }

        if (takers.empty() && k < N) {
            assert(k < N - 1);
            for (int i = 0; i < N - k; i++) {
                b[givers[i]] = givers[(i + 1) % (N - k)];
            }
        } else {
            for (int g : givers) {
                for (int i = 0, B = both.size(); i < B; i++) {
                    int c = both[i];
                    if (c != g) {
                        if (i + 1 != B) {
                            swap(both[i], both.back());
                        }
                        both.pop_back();
                        b[g] = c;
                        break;
                    }
                }
                if (b[g] == -1) {
                    assert(g != takers.back());
                    b[g] = takers.back();
                    takers.pop_back();
                }
            }
            assert(both.empty() && takers.empty());
        }

        cout << k << '\n';
        for (int i = 0; i < N; i++) {
            cout << 1 + b[i] << " \n"[i + 1 == N];
        }
    }

    return 0;
}