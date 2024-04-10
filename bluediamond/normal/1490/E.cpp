#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = (int) 2e5 + 7;
int n, v[N];
bool ok[N];
pair<int, int> a[N];

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

       /// freopen ("input", "r", stdin);

        int t;
        cin >> t;
        while (t--) {
                cin >> n;
                for (int i = 1; i <= n; i++) {
                        cin >> a[i].first;
                        a[i].second = i;
                        ok[i] = 0;
                }
                sort(a + 1, a + n + 1);
                for (int i = 1; i <= n; i++)
                        v[i] = a[i].first;
                int l = 1, r = n, pre = 0;
                while (l <= r) {
                        int i = (l + r) / 2;
                        ok[i] = 1;
                        int now = v[i];
                        for (int j = 1; j <= n; j++)
                                if (i != j) {
                                        if (now < v[j]) {
                                                ok[i] = 0;
                                                break;
                                        }
                                        now += v[j];
                                }
                        if (!ok[i]) {
                                pre = i;
                                l = i + 1;
                        } else
                                r = i - 1;
                }
                for (int i = 1; i <= n; i++)
                        ok[i] = (i > pre);
                vector<int> ret;
                for (int i = 1; i <= n; i++)
                        if (ok[i])
                                ret.push_back(a[i].second);
                sort(ret.begin(), ret.end());
                cout << (int) ret.size() << "\n";
                for (auto &i : ret)
                        cout << i << " ";
                cout << "\n";
        }

}