#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
int n;
int a[N];
pair<int, int> t[4 * N];
ll sol[N];

void build(int v, int tl, int tr) {
        if (tl == tr) {
                t[v] = {a[tl], tl};
        } else {
                int tm = (tl + tr) / 2;
                build(2 * v, tl, tm);
                build(2 * v + 1, tm + 1, tr);
                t[v] = max(t[2 * v], t[2 * v + 1]);
        }
}

pair<int, int> get(int v, int tl, int tr, int l, int r) {
        if (tr < l || r < tl) {
                return {0, 0};
        }
        if (l <= tl && tr <= r) {
                return t[v];
        } else {
                int tm = (tl + tr) / 2;
                return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
        }
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;
        for (int i = 1; i < n; i++) {
                cin >> a[i];
        }
        build(1, 1, n);
        ll ans = 0;
        for (int i = n - 1; i >= 1; i--) {
                int j = get(1, 1, n, i + 1, a[i]).second;
                sol[i] = sol[j] + n - i - (a[i] - j);
                ans += sol[i];
        }
        cout << ans << "\n";
}