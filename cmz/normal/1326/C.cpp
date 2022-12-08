#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 998244353;
int n, k;
int p[200005];
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> k;
    long long tot = 0;
    int ans = 1, last = 0, flg = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        if (p[i] >= n - k + 1) {
            tot += p[i];
            if (flg) ans = 1ll * ans * (last + 1) % mod;
            flg = 1;
            last = 0;
        }
        else ++last;
    }
    cout << tot << ' ' << ans << endl;
 
    return 0;
}