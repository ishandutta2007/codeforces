#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

bitset<1005> sieve;
vector<int> primes;
void gprime() {
    sieve[0] = 1; sieve[1] = 1;
    for(int i=2; i<=1000; i++) {
        if(sieve[i]) continue;
        primes.push_back(i);
        if(i*i > 1000) continue;
        for(int j=i*i; j<=1000; j+=i) sieve[j] = 1;
    }
}

int main() {
    gprime();
    int n, k; cin >> n >> k;
    int tot = 0;
    for(int i:primes) {
        if(i > n) break;
        int test = i - 1;
        for(int j=0; j<primes.size()-1; j++) {
            if(primes[j] + primes[j+1] > test) break;
            if(primes[j] + primes[j+1] == test) {
                tot += 1;
                break;
            }
        }
        if(tot == k)
            break;
    }
    if(tot >= k) cout << "YES" << endl;
    else cout << "NO" << endl;
}