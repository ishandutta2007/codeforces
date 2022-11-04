#include <bits/stdc++.h>

using namespace std;

int n, a;

int main() {
    cin >> n >> a;
    if (a % 2 == 0) {
        cout << (n - a) / 2 + 1 << "\n";
    } else {
        cout << (a - 1) / 2 + 1 << "\n";
    }
}