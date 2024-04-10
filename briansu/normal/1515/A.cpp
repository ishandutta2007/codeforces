#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> d(n), ans(n);
        for (int i = 0; i < n; i++)
            cin >> d[i];
        sort(ALL(d));
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += d[i];
            if (total == x && i != n - 1)
                ans[i] = d[i + 1], ans[i + 1] = d[i], ++i, total += d[i];
            else
                ans[i] = d[i];
        }
        if (total == x)
            cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
                cout << ans[i] << " \n"[i == n - 1];
        }

    }
}