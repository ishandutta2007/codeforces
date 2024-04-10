/**
 *  created: 21/12/2020, 12:03:14
**/

#include <bits/stdc++.h>

using namespace std;

int t;
long long n;

bool ok(long long x) {
    long long cur = x;
    while (cur) {
        if (cur % 10 && x % (cur % 10)) {
            return false;
        }
        cur /= 10;
    }
    return true;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        while (!ok(n)) {
            ++n;
        }
        cout << n << "\n";
    }
    return 0;
}