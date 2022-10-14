#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int A; cin >> A;
    int tot = 0;
    for(int base=2; base<A; base++) {
        int x = A;
        while(x) {
            tot += x%base;
            x /= base;
        }
    }
    cout << (tot/gcd(tot,A-2)) << "/" << ((A-2)/gcd(tot,A-2)) << endl;
}