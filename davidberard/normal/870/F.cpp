#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 10001000;

int sieve[N];
int non_composite_pfx[N];
int smallest_prime_pfx[N];
vector<int> primes;
int pcount[N];
int totient[N];

int n;

void setup() {
    //cerr << "! !" << endl;
    for (int i=2; i<=n; ++i) {
        totient[i] = i;
    }
    for (int i=2; i<=n; ++i) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (int j=i; j<N; j+=i) {
                if (!sieve[j]) sieve[j] = i;
                ++pcount[j];
                totient[j] /= i;
                totient[j] *= i-1;
            }
        }
    }
    non_composite_pfx[1] = 1;
    for (int i=2; i<=n; ++i) {
        if (i>n/2 && sieve[i] == i) continue;
        smallest_prime_pfx[sieve[i]]++;
    }
    for (int i=2; i<=n; ++i) {
        non_composite_pfx[i] = non_composite_pfx[i-1] + (sieve[i] == i);
    }
    for (int i=2; i<=n; ++i) {
        smallest_prime_pfx[i] += smallest_prime_pfx[i-1];
    }
}

ll type1;
ll type2;
ll bad;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    setup();

    bad = 1;
    for (int i=(n+2)/2; i<=n; ++i) {
        if (sieve[i] == i) {
            ++ bad;
        }
    }
    for (int i=2; i<=n; ++i) {
        type1 += i - 1 - totient[i];
    }

    for (int i=2; i<=n; ++i) {
        if (sieve[i] == i) continue;
        type2 += totient[i] + pcount[i] - non_composite_pfx[i];
    }
    for (int i=2; i<=n; ++i) {
        if (sieve[i] != i) continue;

        // all the numbers which have smallest prime <= floor(n/i)
        type2 += smallest_prime_pfx[n/i];

        for (int j=i; j<=n; j+=i) {
            if (sieve[j] <= n/i) {
                --type2;
            }
        }
    }
    int j = primes.size()-1;
    for (int i=0; i<primes.size() && i<=j; ++i) {
        while (j>=0 && ((ll) primes[i]*primes[j] > n || primes[j] > n/2)) {
            --j;
        }
        if (j < 0 || i>j) break;
        type2 -= j-i;
    }

    ll badcount = bad*(n-bad) + bad*(bad-1)/2;

    ll type3 = (ll) n*(n-1)/2 - type1 - type2 - badcount;

    cout << type1 + 2*type2 + 3*type3 << "\n";

    return 0;
}