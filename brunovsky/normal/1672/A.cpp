#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

#define ALICE "errorgorn"
#define BOB   "maomao90"

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
        int S = accumulate(begin(a), end(a), 0);
        int moves = S - N;
        if (moves % 2 == 0) {
            cout << BOB << '\n';
        } else {
            cout << ALICE << '\n';
        }
    }
    return 0;
}