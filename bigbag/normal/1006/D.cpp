#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, ans;
char a[max_n], b[max_n];

bool okk(int i) {
    bool ok = false;
    for (int q = 0; q < 2; ++q) {
        for (int w = 0; w < 2; ++w) {
            for (int e = 0; e < 2; ++e) {
                for (int r = 0; r < 2; ++r) {
                    if (a[i] == b[i] && a[n - i - 1] == b[n - i - 1]) {
                        ok = true;
                    }
                    swap(a[n - i - 1], b[n - i - 1]);
                }
                swap(a[i], b[i]);
            }
            swap(a[i], a[n - i - 1]);
        }
        swap(b[i], b[n - i - 1]);
    }
    for (int q = 0; q < 2; ++q) {
        for (int w = 0; w < 2; ++w) {
            for (int e = 0; e < 2; ++e) {
                for (int r = 0; r < 2; ++r) {
                    if (a[i] == b[i] && a[n - i - 1] == b[n - i - 1]) {
                        ok = true;
                    }
                    swap(b[i], b[n - i - 1]);
                }
                swap(a[i], a[n - i - 1]);
            }
            swap(a[i], b[i]);
        }
        swap(a[n - i - 1], b[n - i - 1]);
    }
    return ok;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%s%s", &n, a, b);
    for (int i = 0; i < n - i - 1; ++i) {
        char c[4];
        c[0] = a[i];
        c[1] = b[i];
        c[2] = a[n - i - 1];
        c[3] = b[n - i - 1];
        char c1 = a[i], c2 = a[n - i - 1];
        int res = 2;
        for (int q = 0; q < 4; ++q) {
            for (int w = 0; w < 4; ++w) {
                a[i] = c[q];
                a[n - i - 1] = c[w];
                if (okk(i)) {
                    res = min(res, (a[i] != c1) + (a[n - i - 1] != c2));
                }
            }
        }
        ans += res;
    }
    if (n % 2 && a[n / 2] != b[n / 2]) {
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}