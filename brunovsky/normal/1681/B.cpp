#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        int M;
        cin >> M;
        int B = 0;
        for (int i = 0; i < M; i++) {
            int b;
            cin >> b;
            B = (B + b) % N;
        }
        cout << a[B] << '\n';
    }
    return 0;
}