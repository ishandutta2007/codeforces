#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

        ///freopen ("input", "r", stdin);

        int t;
        cin >> t;
        while (t--) {
                int n;
                cin >> n;
                map<int, int> fr;
                for (int i = 1; i <= n; i++) {
                        int x;
                        cin >> x;
                        fr[x]++;
                }
                vector<int> f;
                for (auto &it : fr)
                        f.push_back(it.second);
                sort(f.begin(), f.end());
                int ret = n;
                for (int i = 0; i < (int) f.size(); i++) {
                        int cost = n - f[i] * ((int) f.size() - i);
                        ret = min(ret, cost);
                }
                cout << ret << "\n";
        }

}