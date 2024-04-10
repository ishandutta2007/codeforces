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

        deque<int> answer;
        answer.push_back(p[0]);

        for (int i = 1; i < N; i++) {
            if (p[i] < answer.front()) {
                answer.push_front(p[i]);
            } else {
                answer.push_back(p[i]);
            }
        }

        for (int i = 0; i < N; i++) {
            cout << answer[i] << " \n"[i + 1 == N];
        }
    }
    return 0;
}