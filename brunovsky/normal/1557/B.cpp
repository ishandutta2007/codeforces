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
    cout << fixed << showpoint << setprecision(9);
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        vector<int> index(N);
        iota(begin(index), end(index), 0);
        sort(begin(index), end(index), [&](int u, int v) { return a[u] < a[v]; });
        int runs = 1;
        for (int i = 1; i < N; i++) {
            if (index[i] != index[i - 1] + 1)
                runs++;
        }
        cout << (runs <= K ? "Yes\n" : "No\n");
    }
    return 0;
}