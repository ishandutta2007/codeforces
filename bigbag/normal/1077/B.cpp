#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n, a[max_n], ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i + 1 < n; ++i) {
        if (a[i - 1] == 1 && a[i + 1] == 1 && a[i] == 0) {
            ++ans;
            a[i + 1] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}