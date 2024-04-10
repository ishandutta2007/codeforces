#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        vector<int> A(k);
        vector<bool> OK(n, false);
        for (int i = 0; i < k; ++i) {
            cin >> A[i]; A[i] -= 1;
        }

        for (int ans = 1; ; ++ans) {
            for (auto x : A) {
                if (x - ans + 1 >= 0) OK[x - ans + 1] = true;
                if (x + ans - 1 < n) OK[x + ans - 1] = true;
            }
            bool all_ok = true;
            for (int i = 0; i < n; ++i) {
                all_ok &= OK[i];
            }
            if (all_ok) {
                cout << ans << '\n';
                break;
            }
        }
    }

    return 0;
}