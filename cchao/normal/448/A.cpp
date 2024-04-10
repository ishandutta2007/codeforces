#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 0, b = 0, t;
    for(int i = 0; i < 3; ++i) { cin >> t; a += t; }
    for(int i = 0; i < 3; ++i) { cin >> t; b += t; }
    int n; cin >> n;
    cout << ((a + 4) / 5 + (b + 9) / 10 <= n ? "YES" : "NO") << endl;
    return 0;
}