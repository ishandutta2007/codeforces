#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t;
long long a, b;

bool is_prime(long long x) {
    if (x == 1) {
        return false; // never
    }
    for (long long i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a == b + 1 && is_prime(a + b)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}