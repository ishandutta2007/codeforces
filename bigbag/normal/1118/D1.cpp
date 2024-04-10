#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, m, a[max_n];

bool check(int cnt) {
    long long sum = 0;
    int last = 1;
    for (int i = 0; i < n; ++i) {
        if (i % cnt == 0) {
            --last;
        }
        if (a[i] + last > 0) {
            sum += a[i] + last;
        }
    }
    return sum >= m;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    reverse(a, a + n);
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r > n) {
        puts("-1");
    } else {
        printf("%d\n", r);
    }
    return 0;
}