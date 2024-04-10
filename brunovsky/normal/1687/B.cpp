#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto QUERY(const string& s) {
    cout << "? " << s << endl;
    int ans;
    cin >> ans;
    return ans;
}

auto ANSWER(int ans) {
    cout << "! " << ans << endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;

    string s(M, '0');

    vector<int> weight(M);
    for (int i = 0; i < M; i++) {
        s[i] = '1';
        weight[i] = QUERY(s);
        s[i] = '0';
    }

    vector<int> order(M);
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order), [&](int i, int j) {
        return make_pair(weight[i], i) < make_pair(weight[j], j); //
    });

    int ans = 0;
    for (int i : order) {
        s[i] = '1';
        int w = QUERY(s);
        if (w != ans + weight[i]) {
            s[i] = '0';
        } else {
            ans += weight[i];
        }
    }
    ANSWER(ans);
    return 0;
}