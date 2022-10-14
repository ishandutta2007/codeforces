#include <bits/stdc++.h>
using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<long> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }
    vector<int> bindex(N);
    iota(begin(bindex), end(bindex), 0);
    sort(begin(bindex), end(bindex), [&](int u, int v) { return b[u] < b[v]; });

    long paid = 0;
    long bought = 0;
    long sought = accumulate(begin(a), end(a), 0LL);
    int bi = 0, ci = N - 1;

    while (bought < sought) {
        // say we bought this much at price 2
        long expensive = bi == N ? sought - bought : b[bindex[bi]] - bought;
        while (ci >= 0 && expensive > 0) {
            long sub = min(expensive, a[bindex[ci]]);
            a[bindex[ci]] -= sub;
            expensive -= sub;
            paid += 2 * sub;
            bought += sub;
            ci -= a[bindex[ci]] == 0;
        }
        while (bi < N && b[bindex[bi]] <= bought) {
            int u = bindex[bi];
            paid += a[u];
            bought += a[u];
            a[u] = 0;
            bi++;
        }
    }

    cout << paid << '\n';
    return 0;
}