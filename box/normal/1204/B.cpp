#include <iostream>
using namespace std;

int main() {
    int n, l, r; cin >> n >> l >> r;
    // minima: 2^l - 1 + (n-l)
    // maxima: 2^r - 1 + (n-r)*2^(r-1)
    cout << ((1<<l)-1+n-l) << ' ' << ((1<<r)-1+(n-r)*(1<<(r-1))) << endl;
}