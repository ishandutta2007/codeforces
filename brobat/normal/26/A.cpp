#include <iostream>
#include <vector>
using namespace std;

int main() {
    // int n = 100000;
    // vector<bool> is_prime(n+1, true);
    // is_prime[0] = is_prime[1] = false;
    // for (int i = 2; i <= n; i++) {
    //     if (is_prime[i] && (long long)i * i <= n) {
    //         for (int j = i * i; j <= n; j += i)
    //             is_prime[j] = false;
    //     }
    // }
    // cout << is_prime[23];

    int n = 3000;
    vector<int> not_prime(n+1, 0);
    not_prime[0] = not_prime[1] = 1;
    for (int i=2; i<=n; i++) {
        if(not_prime[i]==0 && i<=n) {
            for (int j = i; j<=n; j+= i) not_prime[j] += 1;
        }
    }
    int ans = 0;
    int k; cin >> k;
    if(k==1) cout << 0;
    else {
        for(int i=2; i<=k; i++) {
            if(not_prime[i]==2) ans++;
        }
        cout << ans;
    }
}