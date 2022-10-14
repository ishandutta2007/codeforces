#include <bits/stdc++.h>

using namespace std;

#define long int64_t

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    while (T--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (max(a, b) < min(c, d) || min(a, b) > max(c, d)) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}