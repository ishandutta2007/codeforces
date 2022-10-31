#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, ans = 1, t; cin >> n >> l;
    while(--n) {
        cin >> t;
        if(t != l) ans++;
        l = t;
    }
    cout << ans << endl;
    return 0;
}