#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int n, a[max_n];
long long x[max_n], b[max_n];
vector<int> ans;

bool ok(int k) {
    for (int i = 0; i < k; ++i) {
        x[i] = a[i + 1] - a[i];
    }
    for (int i = 1; i <= n; ++i) {
        b[i] = x[(i - 1) % k] + b[i - 1];
        if (b[i] != a[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int k = 1; k <= n; ++k) {
        if (ok(k)) {
            ans.push_back(k);
        }
    }
    printf("%d\n", ans.size());
    for (int x : ans) {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}