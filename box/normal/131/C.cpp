#include <iostream>
using namespace std;

long long c(long long n, long long k) {
    long long ans = 1;
    for(int i=1; i<=k; i++) {
        ans *= n+1-i;
        ans /= i;
    }
    return ans;
}

int main() {
    long long n, m, t; cin >> n >> m >> t;
    long long ans = 0;
    for(int boys=4; boys<=n; boys++) {
        if(t-boys < 1) continue;
        ans += c(n, boys) * c(m, t-boys);
    }
    cout << ans << endl;
}