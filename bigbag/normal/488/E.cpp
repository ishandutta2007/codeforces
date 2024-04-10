#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int n;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

long long power(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        return power((a * a) % n, b / 2);
    }
    return (a * power(a, b - 1)) % n;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    if (n == 1) {
        cout << "YES\n1\n";
        return 0;
    }
    if (n == 4) {
        cout << "YES\n1\n3\n2\n4\n";
        return 0;
    }
    if (!is_prime(n)) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << 1 << endl;
    for (int i = 2; i < n; ++i) {
        cout << (i * power(i - 1, n - 2)) % n << endl;
    }
    cout << n << endl;
    return 0;
}