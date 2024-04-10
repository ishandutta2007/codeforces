#include <bits/stdc++.h>
 
using namespace std;
 
#define flush cout.flush
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pl = pair<ll, ll>;
const ll INF = 1e9 + 7;
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ld eps = 1e-9;
const ld PI = acos(-1);
 
const int N = (int) 3e8 + 500;
const int M = 16252345 + 500;
int ptr = 0;
 
 
bitset<N> sieve;
array<int, M> primes;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    sieve[0] = sieve[1] = 1;
    for (int i = 1; i < N; ++i) {
        if (!sieve[i]) {
            primes[ptr++] = i;
        }
        for (int j = 0; j < ptr; ++j) {
            int p = primes[j];
            if (p * i >= N)break;
            sieve[p * i] = 1;
            if (i % p == 0)break;
        }
    }
    int l, r;
    cin >> l >> r;
    int res = 0;
    for (int a = 1; a * a <= r; ++a) {
        for (int b = a + 1; b * b + a * a <= r; b += 2) {
            int val = a * a + b * b;
            if (val >= l && !sieve[val]) {
                ++res;
            }
        }
    }
    if (l <= 2 && 2 <= r)++res;
    cout << res << "\n";
    return 0;
}