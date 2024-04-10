#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int M = *max_element(begin(arr), end(arr));
    vector<int> above(M + 1); // smallest representable multiple of v, 0=inf

    for (int v : arr) {
        above[v] = v;
    }

    int ans = 0;

    for (int v = M; v >= 1; v--) {
        for (int m = 2 * v; m <= M; m += v) {
            above[v] = gcd(above[v], above[m]);
        }
        ans += above[v] == v;
    }

    cout << ans - N << '\n';
    return 0;
}