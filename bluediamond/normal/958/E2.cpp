#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll OO = (ll) 1e18;

struct T {
        int i;
        int x;
};

bool cmp_x(T a, T b) {
        return a.x < b.x;
}

bool cmp_i(T a, T b) {
        return a.i < b.i;
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int k, n;
        cin >> k >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
                cin >> v[i];
        }
        sort(v.begin(), v.end());
        vector<T> a(n - 1);
        for (int i = 0; i + 1 < n; i++) {
                a[i] = {i, v[i + 1] - v[i]};
        }
        sort(a.begin(), a.end(), cmp_x);
        while ((int) a.size() > 2 * k + 5) {
                a.pop_back();
        }
        n = (int) a.size();
        sort(a.begin(), a.end(), cmp_i);
        vector<vector<ll>> dp(3);
        for (int i = 0; i < 3; i++) {
                for (int j = 0; j <= k; j++) {
                        dp[i].push_back(OO);
                }
        }
        dp[2][0] = 0;
        for (int i = 0; i < n; i++) {
                int now = i % 3;
                int ant = (i + 2) % 3;
                int ant2 = (i + 1) % 3;
                for (int j = 0; j <= k; j++) {
                        dp[now][j] = OO;
                }
                for (int cnt = 0; cnt <= k; cnt++) {
                        dp[now][cnt] = dp[ant][cnt];
                        if (cnt >= 1) {
                                int p;
                                if (i == 0 || a[i].i != a[i - 1].i + 1) {
                                        p = ant;
                                } else {
                                        p = ant2;
                                }
                                dp[now][cnt] = min(dp[now][cnt], dp[p][cnt - 1] + a[i].x);
                        }
                }
        }
        cout << dp[(n - 1) % 3][k] << "\n";
}