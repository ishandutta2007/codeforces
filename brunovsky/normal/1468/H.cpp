#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, K, M;
        cin >> N >> K >> M;
        int R = N - M;
        vector<bool> keep(N);
        for (int i = 0; i < M; i++) {
            int n;
            cin >> n, n--;
            keep[n] = true;
        }
        deque<int> a;
        for (int i = 0; i < N; i++) {
            if (!keep[i]) {
                a.push_back(i);
            }
        }
        // each step we remove K-1
        // we want M
        // so N-M=a(K-1)
        if ((R % (K - 1)) != 0) {
            cout << "No\n";
            continue;
        }
        if (N == M) {
            cout << "Yes\n";
            continue;
        }
        int D = (K - 1) / 2;
        int first = a[D - 1] + 1;
        int last = a[a.size() - D] - 1;
        debug(N, K, M, R, D, first, last, a);
        bool found = false;
        for (int i = first; i <= last; i++) {
            if (keep[i]) {
                found = true;
                break;
            }
        }
        cout << (found ? "Yes\n" : "No\n");
    }
    return 0;
}