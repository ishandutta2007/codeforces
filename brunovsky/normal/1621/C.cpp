#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto QUERY(int n) {
    cout << "? " << n << endl;
    int ans;
    cin >> ans;
    return ans;
}

auto ANSWER(vector<int> p) {
    cout << "!";
    for (int i = 1, n = p.size() - 1; i <= n; i++) {
        cout << ' ' << p[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<int> pi(N + 1);
        int Q = 0;
        for (int i = 1; i <= N; i++) {
            if (pi[i] == 0) {
                vector<int> cyc;
                do {
                    cyc.push_back(QUERY(i));
                } while (cyc.size() == 1u || cyc.front() != cyc.back());

                int C = cyc.size();
                for (int j = 0; j + 1 < C; j++) {
                    pi[cyc[j]] = cyc[j + 1];
                }

                Q += cyc.size();
            }
        }

        ANSWER(pi);
    }
    return 0;
}