#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;

int n, a[max_n], cnt[max_n];

void ans(int x) {
    if (x == 1) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
    exit(0);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    for (int i = 0; i < max_n; ++i) {
        if (cnt[i] > n / 2) {
            ans(2);
        }
        if (cnt[i] > 0) {
            ans(1);
        }
    }
    return 0;
}