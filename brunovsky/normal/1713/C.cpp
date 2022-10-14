#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

bool square(int n) {
    int x = int(round(sqrt(n)));
    return x * x == n;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> p(N, -1), used(N);
        int i = N - 1;
        while (i >= 0) {
            for (int j = 0; j < N; j++) {
                if (square(i + j)) {
                    for (int k = j; k < N; k++) {
                        p[k] = i--;
                    }
                    N = j;
                    i = N - 1;
                    break;
                }
            }
        }
        N = p.size();
        for (int j = 0; j < N; j++) {
            cout << p[j] << " \n"[j + 1 == N];
        }
    }
    return 0;
}