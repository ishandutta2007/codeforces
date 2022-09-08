#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, x, a[max_n];
long long ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int mid = n / 2;
    for (int i = 0; i < mid; ++i) {
        if (a[i] > x) {
            ans += a[i] - x;
        }
    }
    ans += abs(a[mid] - x);
    for (int i = mid + 1; i < n; ++i) {
        if (a[i] < x) {
            ans += x - a[i];
        }
    }
    cout << ans << "\n";
    return 0;
}