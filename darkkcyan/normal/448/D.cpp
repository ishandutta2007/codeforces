#include <bits/stdc++.h>

using namespace std;

#define long long long 

long n, m, k;

long findcloset(long x) {
    long ans = -1;
    for (int i = 1; i <= min(x, m); ++i) 
        ans = max(ans, (x / i) * i);
    return ans;
}

long countsml(long x) {
    long ans = 0;
    for (int i = 1; i <= min(x, m); ++i) {
        ans += min(x / i, n);
    }
    return ans;
}

int main() {
    cin >> n >> m >> k;
    if (n > m) swap(n, m);
    long l = 1, r = n * m;
    while (l < r) {
        long mid = l + (r - l) / 2;
        long c = countsml(findcloset(mid));
        if (c < k) l = mid + 1;
        else r = mid;
    }
    cout << l;
    return 0;
}