#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000;

int t[maxn], ans[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 1; i <= n; ++i) cin >> t[i];
    vector<int> v;
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        if (x == 1) {
            if (v.size() == k) {
                if (t[v.back()] < t[y]) {
                    ans[v.back()] = 0;
                    v.back() = y;
                    ans[y] = 1;
                }
            } else {
                v.push_back(y);
                ans[y] = 1;
            }
            for (int j = v.size() - 1; j > 0 && t[v[j]] > t[v[j - 1]]; --j) swap(v[j], v[j - 1]);
        } else {
            if (ans[y]) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}