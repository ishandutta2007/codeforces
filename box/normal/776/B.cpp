#include <iostream>
#include <bitset>
using namespace std;

bitset<100005> sieve;
void gsieve(int x) {
    sieve[0] = 1; sieve[1] = 1;
    for(int i=1; i<=x; i++) {
        if(sieve[i]) continue;
        if(i*i > x) break;
        for(int j=i*i; j<=x; j += i) sieve[j] = 1;
    }
}

int main() {
    int n; cin >> n;
    gsieve(n+1);
    if(n > 2) cout << 2 << endl;
    else cout << 1 << endl;
    for(int i=2; i<=n+1; i++) {
        if(i != 2) cout << ' ';
        cout << (int)(sieve[i])+1;
    }
    cout << endl;
}