#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int ans = a;
    while(a >= b) {
        ans += a / b;
        a = (a/b) + (a%b);
    }
    cout << ans << endl;
    return 0;
}