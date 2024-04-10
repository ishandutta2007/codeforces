#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

long long pw[11];
int a[N];
map<int, int> cnt[11];

int main() {
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    pw[0] = 1;
    for (int i = 1; i <= 10; i++) pw[i] = pw[i - 1] * 10;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[upper_bound(pw, pw + 11, a[i]) - pw][a[i] % m]++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int cur = a[i];
        int len = upper_bound(pw, pw + 11, a[i]) - pw;
        for (int j = 1; j <= 10; j++) {
            cur = 10LL * cur % m;
            ans += cnt[j][(m - cur) % m];
            if (len == j && (m - cur) % m == a[i] % m) ans--;
        }
    }
    cout << ans << endl;
    return 0;
}