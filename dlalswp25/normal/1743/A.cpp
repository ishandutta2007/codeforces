#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) {
        int N; scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%*d");
        }
        N = 10 - N;
        printf("%d\n", 3 * N * (N - 1));
    }
    return 0;
}