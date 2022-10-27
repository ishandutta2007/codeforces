#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define sort(arr) sort(arr.begin(), arr.end())
#define forn(i, n) for (int i = 0; i < n; i++)
#define print(arr) forn(i, size(arr)) cout << arr[i] << " "
#define scan(arr) forn(i, size(arr)) cin >> arr[i]
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int count[10] = {0};
    int b = 0;
    forn(i, 10) {
        int x = -1;
        for (int j = b; j < n; j++) {
            if (s[j] - 48 == i) {
                x = j;
                count[i]++;
            }
        }
        if (x != -1) {
            for (int j = b; j < x + 1; j++)
                if (s[j] != i + 48) {
                    count[min(s[j] - 47, 9)]++;
                }
            b = x + 1;
        }
    }
    forn(i, 10) forn(j, count[i]) cout << i;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    forn(i, t) {
        // cout << "Case #" << i + 1 << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}