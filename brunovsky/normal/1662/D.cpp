#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto counts(const string& s) {
    int b = 0, N = s.size(), S = 0;
    string f;
    for (int i = 0; i < N; i++) {
        if (s[i] != 'B') {
            f.push_back(s[i]), S++;
            if (S >= 2 && f[S - 1] == f[S - 2]) {
                f.pop_back(), S--;
                f.pop_back(), S--;
            }
        } else {
            b ^= 1;
        }
    }
    if (b) {
        f.push_back('B');
    }
    return f;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string u, v;
        cin >> u >> v;
        int N = u.size(), M = v.size();
        if (N % 2 != M % 2) {
            cout << "NO\n";
            continue;
        }
        auto f = counts(u);
        auto g = counts(v);
        cout << (f == g ? "YES\n" : "NO\n");
    }
    return 0;
}