#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t; cin >> n >> t;
    int mx = t, mi = t, ans = 0;
    while(--n) {
        cin >> t;
        if(t < mi) mi = t, ans++;
        if(t > mx) mx = t, ans++;
    }
    cout << ans << endl;
    return 0;
}