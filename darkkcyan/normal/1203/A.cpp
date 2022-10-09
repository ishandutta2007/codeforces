#include<iostream>
#include<cmath>

using namespace std;

int a[222];
int main() {
    int ntest; cin >> ntest;
    while (ntest--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
        }
        if (n == 1) {
            cout << "YES\n";
            continue;
        }
        int d = (a[1] - a[0] + n) % n;
        if (d != 1 and d != n - 1) {
            cout << "NO\n";
            continue;
        }
        bool ok = true;
        for (int i = 2; i < n; ++i) {
            if ((a[i - 1] + d) % n != a[i]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}