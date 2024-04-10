#include <bits/stdc++.h>
using namespace std;

int main() {
    //cout << __gcd(5, 0) << endl;
    int a[2], n;
    cin >> a[0] >> a[1] >> n;
    int turn = 0;
    while(true) {
        int require = __gcd(a[turn], n);
        if(n < require) break;
        n -= require;
        turn = 1 - turn;
    }
    cout << 1 - turn << endl;
    return 0;
}