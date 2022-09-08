#include <bits/stdc++.h>

using namespace std;

const int max_n = 400222, inf = 1000111222;

int n, m, a[max_n], t[max_n];

void inc(int i) {
    i += max_n / 2;
    for (; i < max_n; i = (i | (i + 1))) {
        ++t[i];
    }
}

int get(int r) {
    r += max_n / 2;
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        res += t[r];
    }
    return res;
}

long long solve(int r) {
    memset(t, 0, sizeof(t));
    inc(0);
    int sum = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= r) {
            --sum;
        } else {
            ++sum;
        }
        ans += get(-sum);
        inc(-sum);
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    cout << solve(m) - solve(m - 1) << "\n";
    return 0;
}