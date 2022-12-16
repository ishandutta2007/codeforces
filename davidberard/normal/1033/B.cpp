#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int NMAX = 500000;

int sieve[NMAX];
vector<int> primes;

bool setup() {
    for(ll i =2;i<NMAX;++i) {
        if(sieve[i] == 0) {
            for(ll j=i*i;j<NMAX;j+=i) {
                sieve[j] = 1;
            }
            primes.push_back(i);
        }
    }
    return true;
}

bool prime(ll x) {
    for(auto& P : primes) {
        ll p = P;
        if(p*p > x) {
            return true;
        }
        if(x%p == 0) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    setup();
    while(t--) {
        ll a, b;
        cin >> a >> b;
        if(a-b == 1 && prime(a+b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}