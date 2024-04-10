#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int N = 500 + 7;
int n, a[N], b[N];

bool solve() {
        if (n % 2 == 1 && a[n / 2 + 1] != b[n / 2 + 1])
                return 0;
        multiset<pair<int, int>> x, y;
        for (int i = 1; i <= n / 2; i++) {
                int mn = min(a[i], a[n + 1 - i]);
                int mx = max(a[i], a[n + 1 - i]);
                x.insert({mn, mx});
                mn = min(b[i], b[n + 1 - i]);
                mx = max(b[i], b[n + 1 - i]);
                y.insert({mn, mx});
        }
        return (x == y);
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int t;
        cin >> t;
        while (t--) {
                cin >> n;
                for (int i = 1; i <= n; i++)
                        cin >> a[i];
                for (int i = 1; i <= n; i++)
                        cin >> b[i];
                if (solve())
                        cout << "Yes\n";
                else
                        cout << "No\n";
        }
        return 0;
}