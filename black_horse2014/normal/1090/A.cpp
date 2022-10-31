#include <bits/stdc++.h>
using namespace std;

const int N = 550000;
int m[N], ma[N], tma;
int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m[i];
        for (int j = 1; j <= m[i]; j++) {
            int x; cin >> x;
            ma[i] = max(ma[i], x);
        }
        tma = max(tma, ma[i]);
    }
    long long dap = 0;
    for (int i = 1; i <= n; i++) dap += m[i] * 1LL * (tma - ma[i]);
    printf("%lld\n", dap);
    return 0;
}