#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        int n; cin >> n;
        vector<int> v(n);
        for (auto& i: v) cin >> i;
        vector<int> a(n), b(n);
        a[0] = v[0];
        bool has_ans = true;
        for (int i = 1; i < n; ++i) {
            a[i] = min(a[i - 1], v[i] - b[i - 1]);
            if (a[i] < 0) {
                has_ans = false;
                break;
            }
            b[i] = v[i] - a[i];
        }
        cout << (has_ans ? "YES" : "NO") << '\n';
    }
    
    return 0;
}