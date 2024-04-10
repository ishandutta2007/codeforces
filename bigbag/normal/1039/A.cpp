#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, x[max_n];
long long a[max_n], ans[max_n];
long long t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%I64d", &n, &t);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
        if (x[i] <= i || (i && x[i] < x[i - 1])) {
            puts("No");
            return 0;
        }
    }
    long long last = -1;
    for (int i = 0; i < n; ++i) {
        int pos = i;
        while (i < n && x[i] == x[pos]) {
            ++i;
        }
        --i;
        if (x[i] != i + 1) {
            puts("No");
            return 0;
        }
        //cout << pos << ": " << a[pos] << " " << t << " " << last << endl;
        if (a[pos] + t <= last) {
            puts("No");
            return 0;
        }
        long long y = a[i] + t;
        if (i != pos) {
            ++y;
        }
        for (int j = i; j >= pos; --j) {
            ans[j] = y;
            --y;
        }
        last = ans[i];
    }
    puts("Yes");
    for (int i = 0; i < n; ++i) {
        printf("%I64d ", ans[i]);
    }
    printf("\n");
    return 0;
}