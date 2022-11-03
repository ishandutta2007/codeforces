#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int GetGcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a >= b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}

const int LIM = 1e3;

bool IsPrime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> primes;
    for (int i = 2; i < LIM; ++i) {
        if (IsPrime(i)) {
            primes.push_back(i);
        }
    }

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b;
    for (int i = 0; i + 1 < n; ++i) {
        b.push_back(a[i]);
        if (GetGcd(a[i], a[i + 1]) > 1) {
            for (int p : primes) {
                if (a[i] % p != 0 && a[i + 1] % p != 0) {
                    b.push_back(p);
                    break;
                }
            }
        }
    }
    b.push_back(a.back());

    cout << b.size() - a.size() << endl;
    for (int x : b) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}