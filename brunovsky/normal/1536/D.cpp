#include <bits/stdc++.h>
using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> b(N);
        for (int i = 0; i < N; i++) {
            cin >> b[i];
        }
        set<int> bigger = {INT_MIN, b[0], INT_MAX};
        set<int, greater<int>> smaller = {INT_MIN, b[0], INT_MAX};
        bool bad = false;
        for (int i = 1; i < N; i++) {
            int above = *bigger.upper_bound(b[i]);
            int below = *smaller.upper_bound(b[i]);
            if (b[i - 1] != b[i] && above != b[i - 1] && below != b[i - 1]) {
                bad = true;
                break;
            }
            bigger.insert(b[i]);
            smaller.insert(b[i]);
        }
        cout << (bad ? "NO" : "YES") << endl;
    }
    return 0;
}