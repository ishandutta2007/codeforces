#include<bits/stdc++.h>

using namespace std;

void f(int n) {
    if (n == 3) {
        cout << "3 1 2 3" << '\n';
        cout << "3 1 2 3" << '\n';
        return;
    }
    if (n == 4) {
        cout << "3 1 2 3" << '\n';
        cout << "3 1 2 4" << '\n';
        cout << "3 1 3 4" << '\n';
        cout << "3 4 2 3" << '\n';
        return;
    }
    f(n - 2);
    for (int i = 0; i < (n - 3)/2; ++i) {
        cout << 4 << ' ' << 2*i + 1 << ' ' << n - 1 << ' ' << 2*i + 2 << ' ' << n << '\n';
        cout << 4 << ' ' << 2*i + 1 << ' ' << n - 1 << ' ' << 2*i + 2 << ' ' << n << '\n';
    }
    if (n%2) {
        cout << 3 << ' ' << n - 2 << ' ' << n - 1 << ' ' << n  << '\n';
        cout << 3 << ' ' << n - 2 << ' ' << n - 1 << ' ' << n  << '\n';
    }
    else {
        cout << 3 << ' ' << n - 2 << ' ' << n - 1 << ' ' << n  << '\n';
        cout << 3 << ' ' << n - 3 << ' ' << n - 1 << ' ' << n  << '\n';
        cout << 4 << ' ' << n << ' ' << n-2 << ' ' << n - 1 << ' ' << n-3 << '\n';
    }
}

int g(int n) {
    if (n == 3) {
        return 2;
    }
    if (n == 4) {
        return 4;
    }
    int res = g(n - 2);
    for (int i = 0; i < (n - 3)/2; ++i) {
        res += 2;
    }
    if (n%2) {
        res += 2;
    }
    else {
        res += 3;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cout << g(n) << '\n';
    f(n);
}