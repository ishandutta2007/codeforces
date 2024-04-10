#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N;
    cin >> N;
    for (int i = 0, loldude; i < N; i++)
        cin >> loldude;

    printf("%d\n", 3 * N);
    for (int i = 1; i < N; i += 2) {
        printf("2 %d %d\n", i, i + 1);
        printf("2 %d %d\n", i, i + 1);
        printf("1 %d %d\n", i, i + 1);
        printf("2 %d %d\n", i, i + 1);
        printf("2 %d %d\n", i, i + 1);
        printf("1 %d %d\n", i, i + 1);
    }
}

// *****

int main() {
    ios::sync_with_stdio(true);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}