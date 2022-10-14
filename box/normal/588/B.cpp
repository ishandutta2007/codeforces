#include <iostream>
using namespace std;

int main() {
    long long ans = 1;
    long long n; cin >> n;
    for(long long v = 2; v*v <= n; v++) {
        if(n % v == 0) {
            ans *= v;
            while(n % v == 0) n /= v;
        }
    }
    cout << ans*n << endl;
}