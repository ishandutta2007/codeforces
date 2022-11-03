#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    long long ans = 0;
    int incr = 0;
    while(N--) {
        int b;
        cin >> b;
        ans += abs(b - incr);
        incr += b - incr;
    }
    cout << ans << '\n';
}