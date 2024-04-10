/**
 *  created: 30/10/2021, 18:05:09
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, mod = 998244353;

void inc(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int t, n, a[max_n];
int used[max_n], val[max_n], curt;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        if (0) {
            n = 100000;
            mt19937 gen;
            for (int i = 0; i < n; ++i) {
                a[i] = gen() % n + 1;
            }
        } else {
            cin >> n;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
        }
        int ans = 0;
        /*for (int r = n - 1; r >= 0; --r) {
            int last = a[r];
            for (int i = r; i >= 0; --i) {
                int k = (a[i] + last - 1) / last;
                last = a[i] / k;
                inc(ans, mul(k - 1, i + 1));
            }
        }*/
        vector<pair<int, int>> v, nv;
        for (int i = n - 1; i >= 0; --i) {
            v.push_back({a[i], 1});
            nv.clear();
            ++curt;
            //cout << i << endl;
            for (auto [last, cnt] : v) {
                //cout << last << " " << cnt << endl;
                int k = (a[i] + last - 1) / last;
                inc(ans, mul(cnt, mul(k - 1, i + 1)));
                int nlast = a[i] / k;
                if (used[nlast] != curt) {
                    used[nlast] = curt;
                    val[nlast] = 0;
                }
                val[nlast] += cnt;
            }
            ++curt;
            for (auto [last, cnt] : v) {
                int k = (a[i] + last - 1) / last;
                int nlast = a[i] / k;
                if (used[nlast] != curt) {
                    used[nlast] = curt;
                    nv.push_back({nlast, val[nlast]});
                }
            }
            v.swap(nv);
        }
        cout << ans << "\n";
    }
    return 0;
}