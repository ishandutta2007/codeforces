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
        vector<int> beauty(11);
        for (int i = 0; i < N; i++) {
            int b, d;
            cin >> b >> d;
            beauty[d] = max(beauty[d], b);
        }
        int zeros = count(begin(beauty) + 1, end(beauty), 0);
        if (zeros > 0) {
            cout << "MOREPROBLEMS\n";
        } else {
            int sum = accumulate(begin(beauty), end(beauty), 0);
            cout << sum << '\n';
        }
    }
    return 0;
}