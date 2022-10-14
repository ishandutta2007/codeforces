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
        int N, K;
        cin >> N >> K;
        string s;
        cin >> s;
        int Ws = count(begin(s), end(s), 'W');
        if (Ws == 0) {
            cout << (K > 0 ? 2 * K - 1 : 0) << '\n';
            continue;
        }
        vector<array<int, 2>> runs;
        for (int l = 0, r = 1; l < N; l = r++) {
            while (r < N && s[l] == s[r])
                r++;
            if (s[l] == 'L' && l > 0 && r < N)
                runs.push_back({l, r});
        }
        int left = find(begin(s), end(s), 'W') - begin(s);
        int right = find(rbegin(s), rend(s), 'W') - rbegin(s);
        sort(begin(runs), end(runs),
             [&](auto a, auto b) { return a[1] - a[0] < b[1] - b[0]; });

        int R = runs.size();
        for (int i = 0; i < R && K > 0; i++) {
            auto [l, r] = runs[i];
            for (int j = l; j < min(r, l + K); j++) {
                s[j] = 'W';
            }
            K = max(0, K - r + l);
        }
        while (right > 0 && K > 0) {
            s[N - right] = 'W';
            right--, K--;
        }
        while (left > 0 && K > 0) {
            s[left - 1] = 'W';
            left--, K--;
        }
        int score = 0;
        for (int i = 0; i < N; i++) {
            score += s[i] == 'W';
            score += i > 0 && s[i] == 'W' && s[i - 1] == 'W';
        }
        cout << score << '\n';
    }
    return 0;
}