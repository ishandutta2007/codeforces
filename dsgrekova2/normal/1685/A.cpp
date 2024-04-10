#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n % 2 == 1){
        cout << "NO\n";
        return;
    }
    sort(all(a));
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        if (i < n / 2)
            b[i*2] = a[i];
        else
            b[(i-n/2)*2+1] = a[i];
    }
    for (int i = 1; i < n; ++i) {
        if (b[i] == b[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << b[i] << ' ';
    }
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}