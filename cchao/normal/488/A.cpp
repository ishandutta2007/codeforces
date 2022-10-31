#include <bits/stdc++.h>
using namespace std;

bool ok(long long t) {
    if(t < 0) t = -t;
    while(t) {
        if(t % 10 == 8) return true;
        t /= 10;
    }
    return false;
}

int main() {
    long long t; cin >> t;
    int ans = 1; t = t + 1;
    while(!ok(t)) {
        t = t + 1;
        ans++;
    }
    cout << ans << endl;
    return 0;
}