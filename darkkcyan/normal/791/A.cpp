#include <bits/stdc++.h>
using namespace std;

int main() {
    #define llong long long 
    llong a, b; cin >> a >> b;
    for (int ans = 0; ; ++ans, a *= 3, b *= 2)
        if (a > b) {
            cout << ans;
            break;
        }
    return 0;
}