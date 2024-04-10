#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;

    int abcs = 0;
    auto is = [&](int i) { return i >= 0 && i + 2 < N && s.substr(i, 3) == "abc"; };

    for (int i = 0; i + 2 < N; i++) {
        abcs += is(i);
    }

    while (Q--) {
        int i;
        string c;
        cin >> i >> c, i--;
        if (s[i] != c[0]) {
            abcs -= is(i) + is(i - 1) + is(i - 2);
            s[i] = c[0];
            abcs += is(i) + is(i - 1) + is(i - 2);
        }
        cout << abcs << '\n';
    }
    return 0;
}