#include <bits/stdc++.h>
using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> h(N);
        for (int i = 0; i < N; i++) {
            cin >> h[i];
        }
        sort(begin(h), end(h));
        int min_difference = INT_MAX;
        for (int i = 1; i < N; i++) {
            min_difference = min(min_difference, h[i] - h[i - 1]);
        }
        vector<int> ans;
        if (h[N - 1] - h[N - 2] == min_difference) {
            ans.push_back(h[N - 2]);
            ans.insert(end(ans), begin(h), begin(h) + (N - 2));
            ans.push_back(h[N - 1]);
        } else {
            for (int i = 1; i < N; i++) {
                if (h[i] - h[i - 1] == min_difference) {
                    ans.push_back(h[i - 1]);
                    ans.insert(end(ans), begin(h) + (i + 1), end(h));
                    ans.insert(end(ans), begin(h), begin(h) + (i - 1));
                    ans.push_back(h[i]);
                    break;
                }
            }
        }
        assert(int(ans.size()) == N);
        for (int i = 0; i < N; i++) {
            cout << ans[i] << " \n"[i + 1 == N];
        }
    }
    return 0;
}