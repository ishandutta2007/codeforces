#include <bits/stdc++.h>
using namespace std;

bool ok(int x) {
    while(x) {
        if(x%10 != 4 && x %10 != 7) return false;
        x /= 10;
    }
    return true;
}

int main() {
    int ans = false; int n; cin >> n;
    for(int i = 4; i <= n; ++i)
        if(n % i == 0 && ok(i)) {
            ans = true;
            break;
        }
    puts(ans ? "YES": "NO");
    return 0;
}