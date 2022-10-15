#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
int n, a[N], b[N], t[N], f[N];

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
       /// freopen ("input", "r", stdin);
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) a[i]--, b[i]--;
        for (int i = 0; i < n; i++) t[a[i]] = i;
        for (int i = 0; i < n; i++) a[i] = t[b[i]];
        for (int i = 0; i < n; i++) {
                int d = a[i] - i;
                d %= n;
                if (d < 0) d += n;
                f[d]++;
        }
        int sol = 0;
        for (int i = 0; i < n; i++) sol = max(sol, f[i]);
        cout << sol << "\n";
        return 0;
}