#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int n, x[max_n], y[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        x[i] -= x[0];
        y[i] -= y[0];
    }
    while (true) {
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (x[i] % 2 || y[i] % 2) {
                ok = true;
                break;
            }
        }
        if (ok) {
            break;
        }
        for (int i = 0; i < n; ++i) {
            x[i] /= 2;
            y[i] /= 2;
        }
    }
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        //cout << x[i] << " " << y[i] << endl;
    }
    for (int i = 0; i < n; ++i) {
        if (abs(x[i] % 2) == abs(y[i] % 2)) {
            v.push_back(i);
        }
    }
    if (v.size() == n) {
        v.clear();
        for (int i = 0; i < n; ++i) {
            if (x[i] % 2 == 0) {
                v.push_back(i);
            }
        }
    }
    printf("%d\n", v.size());
    for (int i : v) {
        printf("%d ", i + 1);
    }
    puts("");
    return 0;
}