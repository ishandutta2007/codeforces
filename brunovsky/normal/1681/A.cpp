#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto sort_uniq(vector<int>& x) {
    sort(begin(x), end(x));
    x.erase(unique(begin(x), end(x)), end(x));
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        cin >> M;
        vector<int> b(M);
        for (int i = 0; i < M; i++) {
            cin >> b[i];
        }
        int A = *max_element(begin(a), end(a));
        int B = *max_element(begin(b), end(b));
        if (A == B) {
            cout << "Alice\nBob\n";
        } else if (A > B) {
            cout << "Alice\nAlice\n";
        } else {
            cout << "Bob\nBob\n";
        }
    }
    return 0;
}