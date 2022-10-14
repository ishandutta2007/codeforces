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
        string L;
        string M(N, '(');
        string R(N, ')');
        for (int i = 1; i <= N; i++) {
            cout << L + M + R << '\n';
            L += "()";
            M.pop_back(), R.pop_back();
        }
    }
    return 0;
}