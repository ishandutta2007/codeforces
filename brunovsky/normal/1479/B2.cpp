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
    vector<int> a(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<int> nxt(N + 1, N), head(N + 1, N);
    for (int i = N - 1; i >= 0; i--) {
        nxt[i] = head[a[i]], head[a[i]] = i;
    }
    int B1 = N, B2 = N, ans = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] == a[B1]) {
            B1 = i;
        } else if (a[i] == a[B2]) {
            B2 = i;
        } else if (nxt[B1] >= nxt[B2]) {
            B1 = i, ans++;
        } else {
            B2 = i, ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}