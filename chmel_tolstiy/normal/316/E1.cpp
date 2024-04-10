#include <iostream>
#include <vector>
#include <cstdio>
#include <memory.h>

using namespace std;

typedef long long LL;

const LL MOD = 1000000000;

long long F[10000];

int main() {
    F[0] = F[1] = 1;
    for (int i = 2; i < 10000; ++i) {
        F[i] = F[i-1] + F[i-2];
        if (F[i] >= MOD) F[i] -= MOD;
    }
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, v;
            cin >> x >> v;
            a[x-1] = v;
        }
        if (t == 2) {
            int l, r;
            cin >> l >> r;
            --l; --r;
            LL ans = 0;
            for (int j = l; j <=r; ++j)
                ans = (ans + F[j-l] * a[j]) % MOD;
            cout << ans << endl;
        }
    }
    return 0;
}