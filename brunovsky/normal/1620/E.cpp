#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    const int MAXV = 500'000;

    int Q;
    cin >> Q;

    vector<list<int>> pos(MAXV);
    int S = 0;

    while (Q--) {
        if (int t; cin >> t, t == 1) {
            int x;
            cin >> x, x--;
            pos[x].push_back(S++);
        } else {
            int x, y;
            cin >> x >> y, x--, y--;
            if (x != y) {
                pos[y].splice(end(pos[y]), pos[x]);
            }
        }
    }

    vector<int> ans(S);
    for (int v = 0; v < MAXV; v++) {
        for (int i : pos[v]) {
            ans[i] = v;
        }
    }
    for (int i = 0; i < S; i++) {
        cout << 1 + ans[i] << " \n"[i + 1 == S];
    }

    return 0;
}