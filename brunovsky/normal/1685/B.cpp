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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        string s;
        cin >> s;
        int as = count(begin(s), end(s), 'A');
        int bs = count(begin(s), end(s), 'B');
        if (as != a + c + d || bs != b + c + d) {
            cout << "NO\n";
            continue;
        }
        int N = s.size();
        vector<int> AB, BA;
        int either = 0;
        for (int l = 0, r = 1; l < N; l = r++) {
            while (r < N && s[r - 1] != s[r])
                r++;
            int len = r - l;
            if (len == 1) {
                continue;
            } else if (len % 2 == 1) {
                either += len / 2;
            } else if (len % 2 == 0) {
                if (s[l] == 'A') {
                    AB.push_back(len / 2);
                } else {
                    BA.push_back(len / 2);
                }
            }
        }
        int ab = accumulate(begin(AB), end(AB), 0);
        int ba = accumulate(begin(BA), end(BA), 0);
        sort(begin(AB), end(AB));
        sort(begin(BA), end(BA));
        while (ab + ba + either > c + d) {
            if (ab + either < c) {
                int x = BA.back();
                BA.pop_back();
                ba -= x;
                either += x - 1;
            } else if (ba + either < d) {
                int x = AB.back();
                AB.pop_back();
                ab -= x;
                either += x - 1;
            } else {
                break;
            }
        }
        bool ok = (ab + either >= c) && (ba + either >= d) && (ab + ba + either >= c + d);
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}