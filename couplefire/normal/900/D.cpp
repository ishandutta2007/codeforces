#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

vector<int> trial_division1(long long n) {
    vector<int> factorization;
    for (int d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << 1 << endl;
    int x, y; cin >> x >> y;
    if(y % x != 0){
        cout << 0 << endl;
        return 0;
    }
    y /= x;
    vector<int> primes = trial_division1(y);
    sort(primes.begin(), primes.end());
    primes.erase(unique(primes.begin(), primes.end()), primes.end());
    int siz = (1<<primes.size());
    long long ans = 0;
    for(int mask = 0; mask<siz; mask++){
        int mult = 1;
        if(__builtin_popcount(mask)&1) mult = -1;
        int yy = y;
        for(int i = 0; i<primes.size(); i++){
            if(mask&(1<<i)){
                yy /= primes[i];
            }
        }
        ans += mult*binpow(2, yy-1, MOD);
        ans %= MOD;
    }
    cout << (ans+MOD)%MOD << endl;
}