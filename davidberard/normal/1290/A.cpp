#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int N = 4000;
int a[N];
int b[N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        int n, m, k;
        cin >> n >> m >> k;
        k = min(k, m-1);
        for (int i=1; i<=n; ++i) {
            cin >> a[i];
        }
        for (int i=1; i<=m; ++i) {
            b[i] = max(a[n-m+i], a[i]);
        }
        int ans = 0;
        for (int i=1; i<=k+1; ++i) {
            int mn = 1e9;
            //cerr << "! " << i << " TO " << i+m-k-1 << endl;
            for (int j=i; j<i+m-k; ++j) {
                mn = min(mn, b[j]);
            }
            ans = max(mn, ans);
        }
        cout << ans << "\n";
    }
    return 0;
}