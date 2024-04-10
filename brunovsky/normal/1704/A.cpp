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
        int N, M;
        cin >> N >> M;
        string a, b;
        cin >> a >> b;
        int K = M - 1;
        if (a.substr(N - K) != b.substr(1)) {
            cout << "NO\n";
            continue;
        }
        char c = b[0];
        if (count(begin(a), begin(a) + N - K, c)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}