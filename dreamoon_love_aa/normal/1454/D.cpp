#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
void solve() {
    long long n;
    scanf("%lld", &n);
    long long _n = n;
    int max_power = 0;
    long long max_power_prime = 1;
    for(long long p = 2; p * p <= n; p++) {
        if(n % p == 0) {
            int cnt = 0;
            while(n % p == 0) {
                cnt++;
                n /= p;
            }
            if(cnt > max_power) {
                max_power = cnt;
                max_power_prime = p;
            }
        }
    }
    if(n > 1 && 1 > max_power) {
        max_power = 1;
        max_power_prime = n;
    }
    printf("%d\n", max_power);
    for(int i = 0; i + 1 < max_power; i++) {
        printf("%lld ", max_power_prime);
        _n /= max_power_prime;
    }
    printf("%lld\n", _n);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}