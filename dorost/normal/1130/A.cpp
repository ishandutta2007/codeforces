#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
int main() {
    int n, x = 0, y = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        x += (a[i] > 0);
        y += (a[i] < 0);
    }
    if (x >= (n + 1) / 2) {
        cout << 1;
    }else if (y >= (n + 1) / 2) {
        cout << -1;
    }else {
        cout << 0;
    }
}
// coding in mobile :/