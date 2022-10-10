#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            if (++cur == a[i]) {
                ans++;
                cur = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}