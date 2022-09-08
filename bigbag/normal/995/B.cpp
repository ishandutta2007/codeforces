#include <bits/stdc++.h>

using namespace std;

const int max_n = 211, inf = 1000111222;

int n, ans, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    n *= 2;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i += 2) {
        int pos;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] == a[i]) {
                pos = j;
                break;
            }
        }
        for (int j = pos; j > i; --j) {
            a[j] = a[j - 1];
        }
        a[i + 1] = a[i];
        ans += pos - i - 1;
    }
    cout << ans << endl;
    return 0;
}