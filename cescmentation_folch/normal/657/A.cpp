#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, h, d;
    cin >> n >> d >> h;
    if (n > 2 and d == 1) {
        cout << -1 << endl;
        return 0;
    }
    if (n - 1 < d) {
        cout << -1 << endl;
        return 0;
    }
    if (h > d or d > 2*h) {
        cout << -1 << endl;
        return 0;
    }
    int k = 2;
    int ant = 1;
    for (int i = 0; i < h; ++i) {
        cout << ant << ' ' << k << endl;
        ant = k;
        ++k;
    }
    ant = 1;
    for (int i = 0; i < d - h; ++i) {
        cout << ant << ' ' << k << endl;
        ant = k;
        ++k;
    }
    int mid = max(1, min(k - 1, h - d/2 + 1));
    for (int i = k; i <= n; ++i) {
        cout << mid << ' ' << i << endl;
    }
}