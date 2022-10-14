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
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        int sum = accumulate(begin(A), end(A), 0);
        if (sum == N) {
            cout << 0 << endl;
        } else if (sum < N) {
            cout << 1 << endl;
        } else {
            cout << sum - N << endl;
        }
    }
    return 0;
}