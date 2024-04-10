#include <bits/stdc++.h>
using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        if (a[i] < 0) {
            cout << "NO" << endl;
            return;
        }
    }
    vector<int> each = a;
    sort(begin(each), end(each));
    each.erase(unique(begin(each), end(each)), end(each));
    int C = each.size();
    for (int prev = 0, i = 0; i < C; prev = each[i], i++) {
        for (int n = each[i] - 1; n > prev; n--) {
            a.push_back(n);
        }
    }
    int A = a.size();
    cout << "YES" << endl;
    cout << A << endl;
    for (int i = 0; i < A; i++) {
        cout << a[i] << " \n"[i + 1 == A];
    }
}

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}