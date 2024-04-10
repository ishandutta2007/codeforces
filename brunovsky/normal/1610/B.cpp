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
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        bool ok = true;
        for (int i = 0; i < N - 1 - i; i++) {
            ok &= a[i] == a[N - 1 - i];
        }
        if (ok) {
            cout << "YES\n";
            continue;
        }

        auto try_erase = [&](int x) {
            int l = 0, r = N - 1;
            while (l < r) {
                while (l < r && a[l] == x)
                    l++;
                while (l < r && a[r] == x)
                    r--;
                if (l < r && a[l] != a[r]) {
                    return false;
                }
                l++, r--;
            }
            return true;
        };

        for (int i = 0; i < N - 1 - i; i++) {
            if (a[i] != a[N - 1 - i]) {
                if (try_erase(a[i]) || try_erase(a[N - 1 - i])) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
                break;
            }
        }
    }
    return 0;
}