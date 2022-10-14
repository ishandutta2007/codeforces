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
        int a, b;
        cin >> a >> b;

        vector<int> sols;

        for (int _ = 0; _ <= 1; _++) {
            // a plays first
            int na = (a + b) / 2;
            for (int k = 0; k <= a + b; k++) {
                int ka2 = a - na + k;
                int kb2 = k + na - a;
                if (ka2 % 2 == 0 && kb2 % 2 == 0) {
                    int ka = ka2 / 2, kb = kb2 / 2;
                    if (0 <= ka && ka <= a && 0 <= kb && kb <= b && ka + kb == k) {
                        sols.push_back(k);
                    }
                }
            }
            swap(a, b);
        }

        sort(begin(sols), end(sols));
        sols.erase(unique(begin(sols), end(sols)), end(sols));

        int S = sols.size();
        cout << S << '\n';
        for (int i = 0; i < S; i++) {
            cout << sols[i] << " \n"[i + 1 == S];
        }
    }
    return 0;
}