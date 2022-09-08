#include <bits/stdc++.h>

using namespace std;

int x;
int a[11];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x;
    for (int i = 0; i < 6; ++i) {
        a[i] = x % 2;
        x /= 2;
    }
    swap(a[0], a[4]);
    swap(a[2], a[3]);
    int ans = 0;
    for (int i = 5; i >= 0; --i) {
        ans = ans * 2 + a[i];
    }
    cout << ans << endl;
    return 0;
}