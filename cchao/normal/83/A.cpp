#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int cur;
    long long t, last, ans = 0;
    for(int i = 0; i < n; ++i) {
        cin >> t;
        if(t != last) cur = 0;
        last = t;
        cur++;
        ans += cur;
    }
    cout << ans << endl;
    return 0;
}