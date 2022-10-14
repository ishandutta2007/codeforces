#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto QUERY_OR(int i, int j) {
    cout << "or " << i + 1 << ' ' << j + 1 << endl;
    int ans;
    cin >> ans;
    if (ans == -1) {
        exit(1);
    }
    return ans;
}

auto QUERY_AND(int i, int j) {
    cout << "and " << i + 1 << ' ' << j + 1 << endl;
    int ans;
    cin >> ans;
    if (ans == -1) {
        exit(1);
    }
    return ans;
}

auto ANSWER(int ans) {
    cout << "finish " << ans << endl;
    exit(0);
}

#define bit(a, i) (((a) >> i) & 1)

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, K;
    cin >> N >> K;

    vector<int> value(N);
    int a1 = QUERY_AND(0, 1);
    int b1 = QUERY_AND(0, 2);
    int c1 = QUERY_AND(1, 2);
    int a2 = QUERY_OR(0, 1);
    int b2 = QUERY_OR(0, 2);
    int c2 = QUERY_OR(1, 2);

    map<array<int, 6>, array<int, 3>> poss;
    poss[{0, 0, 0, 0, 0, 0}] = {0, 0, 0};
    poss[{0, 0, 0, 0, 1, 1}] = {0, 0, 1};
    poss[{0, 0, 0, 1, 0, 1}] = {0, 1, 0};
    poss[{0, 0, 1, 1, 1, 1}] = {0, 1, 1};
    poss[{0, 0, 0, 1, 1, 0}] = {1, 0, 0};
    poss[{0, 1, 0, 1, 1, 1}] = {1, 0, 1};
    poss[{1, 0, 0, 1, 1, 1}] = {1, 1, 0};
    poss[{1, 1, 1, 1, 1, 1}] = {1, 1, 1};

    for (int i = 0; i <= 30; i++) {
        array<int, 6> Q = {bit(a1, i), bit(b1, i), bit(c1, i),
                           bit(a2, i), bit(b2, i), bit(c2, i)};
        for (int x = 0; x < 3; x++) {
            value[x] |= poss.at(Q)[x] << i;
        }
    }
    debug(value);

    for (int i = 3; i < N; i++) {
        int a = QUERY_AND(0, i);
        int b = QUERY_OR(0, i);
        value[i] = (b ^ value[0]) | a;
    }
    debug(value);

    sort(begin(value), end(value));
    ANSWER(value[K - 1]);
    return 0;
}