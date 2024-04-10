#include <bits/stdc++.h>
using namespace std;
const int MN = 3e5 + 5, MOD = 1e9 + 7;
void solve () {
    int n,m; scanf ("%d %d",&n,&m);
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
    int k; scanf ("%d",&k);
    vector<int> b(k+1);
    for (int i = 1; i <= k; i++) scanf ("%d",&b[i]);
    vector<pair<long long, long long>> baseA;
    for (int i = 1; i <= n; i++) {
        long long cnt = 1;
        while (a[i] % m == 0) {
            a[i] /= m;
            cnt *= m;
        }
        if (!baseA.empty() && baseA.back().first == a[i]) {
            baseA.back().second += cnt;
        } else {
            baseA.push_back({a[i],cnt});
        }
    }
    vector<pair<long long, long long>> baseB;
    for (int i = 1; i <= k; i++) {
        long long cnt = 1;
        while (b[i] % m == 0) {
            b[i] /= m;
            cnt *= m;
        }
        if (!baseB.empty() && baseB.back().first == b[i]) {
            baseB.back().second += cnt;
        } else {
            baseB.push_back({b[i],cnt});
        }
    }
    if (baseA == baseB) printf ("Yes\n");
    else printf ("No\n");
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}