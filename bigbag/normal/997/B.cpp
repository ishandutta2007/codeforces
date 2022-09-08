#include <bits/stdc++.h>

using namespace std;

const int max_n = 10011, inf = 1000111222;

long long n;
bitset<max_n> b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    if (n <= 100) {
        b[0] = 1;
        for (int i = 0; i < n; ++i) {
            b = (b << 1) | (b << 5) | (b << 10) | (b << 50);
        }
        cout << b.count() << endl;
    } else {
        cout << n * 49LL - 247 << endl;
    }
    return 0;
}