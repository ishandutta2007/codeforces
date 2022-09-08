#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111;
const long long inf = 100011122200011LL;

int n, a[max_n];
long long ans = inf;

long long mul(long long x, long long y) {
    if (x > inf / y) {
        return inf;
    }
    return x * y;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int x = 1; x < 10001112; ++x) {
        long long cur = 1, sum = 0;
        for (int i = 0; i < n && sum < ans; ++i) {
            sum += llabs(cur - a[i]);
            cur = mul(cur, x);
        }
        ans = min(ans, sum);
    }
    cout << ans << "\n";
    return 0;
}