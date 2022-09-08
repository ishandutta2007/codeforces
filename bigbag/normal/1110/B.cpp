#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, m, k, ans, a[max_n];
vector<int> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (i) {
            v.push_back(a[i] - a[i - 1]);
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ans = a[n - 1] - a[0] + 1;
    for (int i = 0; i + 1 < k; ++i) {
        ans -= v[i];
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}