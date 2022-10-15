#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int t;
        cin >> t;
        while (t--) {
                int n;
                cin >> n;
                vector<int> a(n), b(n);
                for (int i = 0; i < n; i++)
                        cin >> a[i];
                for (int i = 0; i < n; i++)
                        cin >> b[i];
                bool same = 1;
                for (int i = 1; i < n; i++)
                        if (b[i] != b[i - 1])
                                same = 0;
                if (same) {
                        vector<int> c = a;
                        sort(c.begin(), c.end());
                        if (c != a) {
                                cout << "No\n";
                                continue;
                        }
                }
                cout << "Yes\n";
        }
        return 0;
}