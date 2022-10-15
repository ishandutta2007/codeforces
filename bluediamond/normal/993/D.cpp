#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct T {
        int a;
        int b;
};

bool operator < (T f, T s) {
        if (f.a != s.a) {
                return f.a < s.a;
        } else {
                return f.b < s.b;
        }
}

const int N = 50 + 1;
const ld INF = (ld) 1e18;
int n;
T v[N];
ld value[N];
ld mn[N][N];

bool check(ld rap) {
        for (int i = 1; i <= n; i++) {
                value[i] = (ld) v[i].a - rap * (ld) v[i].b;
        }
        for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                        mn[i][j] = INF;
                }
        }
        mn[0][0] = 0;
        int i = 1;
        while (i <= n) {
                int j = i;
                while (j + 1 <= n && v[j + 1].a == v[j].a) {
                        j++;
                }
                vector<ld> avicii;
                for (int k = i; k <= j; k++) {
                        avicii.push_back(value[k]);
                }
                sort(avicii.begin(), avicii.end());
                for (int ca = n; ca >= 0; ca--) {
                        for (int cb = n; cb >= 0; cb--) {
                                if (mn[ca][cb] != INF) {
                                        int free = i - 1 - ca - cb;
                                        ld sum = 0;
                                        for (int t = 0; t <= (int) avicii.size(); t++) {
                                                if (t) {
                                                        sum += avicii[t - 1];
                                                }
                                                int sp = cb + min(t, free);
                                                if (ca + t >= sp) {
                                                        mn[ca + t][sp] = min(mn[ca + t][sp], mn[ca][cb] + sum);
                                                }
                                        }
                                }
                        }
                }
                i = j + 1;
        }
        for (int i = 0; i <= n; i++) {
                if (mn[i][n - i] <= (ld) 1e-14) {
                        return 1;
                }
        }
        return 0;
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;
        for (int i = 1; i <= n; i++) {
                cin >> v[i].a;
        }
        for (int i = 1; i <= n; i++) {
                cin >> v[i].b;
        }
        sort(v + 1, v + n + 1);
        ll l = 0, r = (ll) 1e11, ans;
        while (l <= r) {
                ll mid = (l + r) / 2;
                if (check(mid * 0.001)) {
                        ans = mid;
                        r = mid - 1;
                } else {
                        l = mid + 1;
                }
        }
        cout << ans << "\n";
}