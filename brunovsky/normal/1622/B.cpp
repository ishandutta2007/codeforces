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
        vector<int> p(N);
        for (int i = 0; i < N; i++) {
            cin >> p[i];
        }
        string s;
        cin >> s;
        vector<int> goods, bads;
        for (int i = 0; i < N; i++) {
            if (s[i] == '1') {
                goods.push_back(i);
            } else {
                bads.push_back(i);
            }
        }

        sort(begin(goods), end(goods), [&](int i, int j) { return p[i] < p[j]; });
        sort(begin(bads), end(bads), [&](int i, int j) { return p[i] < p[j]; });

        int B = bads.size(), G = goods.size();
        for (int i = 0; i < B; i++) {
            p[bads[i]] = i + 1;
        }
        for (int i = 0; i < G; i++) {
            p[goods[i]] = i + B + 1;
        }
        for (int i = 0; i < N; i++) {
            cout << p[i] << " \n"[i + 1 == N];
        }
    }
    return 0;
}