#include <bits/stdc++.h>

using namespace std;

int t;
long long a, b, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a >> b >> n;
        int ans = 0;
        while (max(a, b) <= n) {
            ++ans;
            long long na = max(a, b);
            long long nb = a + b;
            a = na;
            b = nb;
        }
        cout << ans << "\n";
    }
    return 0;
}