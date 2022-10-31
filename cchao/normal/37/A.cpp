#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    map<int, int> m;
    cin >> n;
    int ans = 0;
    while(n--) {
        int t; cin >> t;
        m[t]++;
        ans = max(ans, m[t]);
    }
    cout << ans << ' ' << m.size() << endl;

    return 0;
}