#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if(a < b) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a%b);
}

bool dp[1000006];

int main() {
    int n; cin >> n;
    int d; cin >> d; int e; cin >> e; e *= 5;
    if(n >= 1000000) {
        cout << (n % gcd(d, e)) << endl;
        return 0;
    }
    dp[0] = true; int ans = 0;
    for(int i=0; i<=n; i++) {
        if(!dp[i]) continue;
        if(i+d <= n) { dp[i+d] = true; ans = max(ans, i+d); }
        if(i+e <= n) { dp[i+e] = true; ans = max(ans, i+e); }
    }
    cout << n - ans << endl;
}