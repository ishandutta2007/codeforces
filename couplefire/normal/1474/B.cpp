#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

int lp[MAXN+1];
vector<int> primes;

void genPrimes(){
    for(int i=2; i<=MAXN; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back (i);
        }
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=MAXN; ++j)
            lp[i * primes[j]] = primes[j];
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    genPrimes();
    int t; cin >> t;
    while(t--){
        int d; cin >> d;
        int p1 = *lower_bound(primes.begin(), primes.end(), d+1);
        int p2 = *lower_bound(primes.begin(), primes.end(), d+p1);
        cout << 1ll*p1*p2 << endl;
    }
}