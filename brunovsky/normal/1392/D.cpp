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
        string s;
        cin >> N >> s;
        int Rs = count(begin(s), end(s), 'R');
        if (Rs == 0 || Rs == N) {
            cout << (N + 2) / 3 << '\n';
            continue;
        }
        s.push_back(s[0]);
        int ans = 0;
        for (int u = 0; u < N; u++) {
            if (s[u] == 'R' && s[u + 1] == 'L') {
                int Rs = 0;
                int v = u;
                while (s[v] == 'R') {
                    v = (v - 1 + N) % N, Rs++;
                }
                int Ls = 0;
                v = u + 1;
                while (s[v] == 'L') {
                    v = (v + 1) % N, Ls++;
                }
                debug(Rs, Ls);
                ans += Rs / 3 + Ls / 3;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}