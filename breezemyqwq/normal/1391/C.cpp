#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int mod = 1e9 + 7;

long long ksm(long long b, long long p) {
    long long ret = 1;
    while(p) {
        if(p & 1) {
            ret = (ret * b) % mod;
        }
        p >>= 1;
        b = (b * b) % mod;
    }   
    return ret;
}

long long k[1000005];

int main() {
    long long n;
    cin >> n;
    k[0] = 1;
    for(int i = 1; i <= n; i++) k[i] = k[i - 1] * i % mod;
    long long m = k[n];
    long long ans = ((m - ksm(2, n - 1) + mod) % mod);
    cout << ans << endl;
    return 0;
}