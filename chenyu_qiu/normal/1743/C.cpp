#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void test_case() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    for (int i = 0, last_zero = -1; i < n; i++) {
        if (s[i] == '0') {
            last_zero = i;
        } else if (last_zero >= 0 && a[last_zero] > a[i]){
            s[last_zero] = '1';
            s[i] = '0';
            last_zero = i;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ans += a[i];
        }
    }
    cout << ans << '\n';
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        test_case();
    }
}