#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int DISTINCT(int l, int r) {
    cout << "? 2 " << l + 1 << ' ' << r + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

char GET(int i) {
    cout << "? 1 " << i + 1 << endl;
    string ans;
    cin >> ans;
    return ans[0];
}

constexpr int A = 26;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    int D = 1;
    string s(N, '.');
    s[0] = GET(0);
    vector<int> latest(A, -1);
    latest[s[0] - 'a'] = 0;
    for (int i = 1; i < N; i++) {
        debug(i, s);
        int E = DISTINCT(0, i);
        if (D < E) {
            s[i] = GET(i);
            latest[s[i] - 'a'] = i;
            D++;
            continue;
        }
        vector<int> pos;
        for (int c = 0; c < A; c++) {
            if (latest[c] != -1) {
                pos.push_back(latest[c]);
            }
        }
        sort(begin(pos), end(pos));
        int P = pos.size();
        int L = 0, R = P;
        while (L + 1 < R) {
            int M = (L + R) / 2;
            E = DISTINCT(pos[M], i);
            int S = P - M;
            assert(E == S || E == S + 1);
            if (E == S) {
                L = M;
            } else {
                R = M;
            }
        }
        s[i] = s[pos[L]];
        latest[s[i] - 'a'] = i;
    }
    cout << "! " << s << endl;
    return 0;
}