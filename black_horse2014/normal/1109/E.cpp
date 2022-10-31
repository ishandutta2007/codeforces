#include <bits/stdc++.h>
using namespace std;

const int N = 1<<18;

int pw[10][40];
int pro[10];

pair<int, int> dp[10][N];
pair<int, int> add[10][N];
int a[N];

vector<pair<int, int> > factor(int mod) {
    vector<pair<int, int> > ret;
    for (int i = 2; i * i <= mod; i++) if (mod % i == 0) {
        int j = 0;
        while (mod % i == 0) mod /= i, j++;
        ret.emplace_back(i, j);
    }
    if (mod > 1) ret.emplace_back(mod, 1);
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j <= ret[i].second; j++) pw[i][j] = j == 0 ? 1 : pw[i][j-1] * ret[i].first;
        pro[i] = pw[i][ret[i].second];
    }
    return ret;
}

int modExp(int a, int n, int p) {
    int ret = 1;
    for (; n; n >>= 1, a = 1LL * a * a % p) if (n & 1) ret = 1LL * ret * a % p;
    return ret;
}

int extEuclid(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int g = extEuclid(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
}

int rev(int m1, int m2) {
    int x, y;
    extEuclid(m1, m2, x, y);
    x = (x % m2 + m2) % m2;
    assert(x < m2 && x >= 0);
    return x;
}

int CRT(int a1, int m1, int a2, int m2) {
    assert(m1 && m2);
    return (1LL * a1 * rev(m2, m1) % m1 * m2 + 1LL * a2 * rev(m1, m2) % m2 * m1) % (m1 * m2);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, mod; cin >> n >> mod;
    vector<pair<int, int> > P = factor(mod);
    for (int i = 1; i <= n; i++) cin >> a[i];
    auto change = [&](int u, int i, pair<int, int> p) {
        int x = p.first, y = p.second;
        dp[i][u].first += x;
        dp[i][u].second = dp[i][u].second * 1LL * y % pro[i];
        add[i][u].first += x;
        add[i][u].second = add[i][u].second * 1LL * y % pro[i];
    };
    auto push_down = [&](int u) {
        for (int i = 0; i < P.size(); i++) {
            if (add[i][u].first || add[i][u].second != 1) {
                change(u + u, i, add[i][u]);
                change(u + u + 1, i, add[i][u]);
                add[i][u] = {0, 1};
            }
        }
	};
    auto merge = [&](pair<int, int> a, pair<int, int> b, int i) {
        int x1 = a.first, y1 = a.second;
        int x2 = b.first, y2 = b.second;
        assert(y1 % P[i].first != 0);
        assert(y2 % P[i].first != 0);
        assert(i < P.size());
        if (x1 > x2) swap(x1, x2), swap(y1, y2);
        pair<int, int> ret;
        if (x1 == x2) {
            ret.second = (y1 + y2) % pro[i];
            ret.first = x1;
            if (!ret.second) {
                ret.first = P[i].second;
                ret.second = 1;
            } else {
                while (ret.second % P[i].first == 0) ret.second /= P[i].first, ret.first++;
            }
        } else {
            ret.second = (y1 + y2 * 1LL * pw[i][min(x2 - x1, P[i].second)]) % pro[i];
            ret.first = x1;
        }
        return ret;
    };
	auto push_up = [&](int u) {
	    for (int i = 0; i < P.size(); i++) {
            dp[i][u] = merge(dp[i][u + u], dp[i][u + u + 1], i);
	    }
	};
	function<void(int, int, int)> build = [&](int u, int l, int r) {
	    for (int i = 0; i < P.size(); i++) add[i][u] = {0, 1};
		if (l == r) {
            for (int i = 0; i < P.size(); i++) {
                int x = a[l];
                while (x % P[i].first == 0) x /= P[i].first, dp[i][u].first++;
                dp[i][u].second = x % pro[i];
            }
		    return;
		}
		int mid = l + r >> 1;
		build(u + u, l, mid);
		build(u + u + 1, mid + 1, r);
		push_up(u);
	};
    vector<pair<int, int> > v(P.size());
	function<void(int, int, int, int, int)> modify = [&](int u, int l, int r, int ll, int rr) {
		if (ll <= l && r <= rr) {
            for (int i = 0; i < v.size(); i++) {
                auto t = v[i];
                if (t.first || t.second != 1) change(u, i, t);
            }
            return;
		}
		int mid = l + r >> 1;
		push_down(u);
		if (ll <= mid) modify(u + u, l, mid, ll, rr);
		if (mid < rr) modify(u + u + 1, mid + 1, r, ll, rr);
		push_up(u);
	};
    function<void(int, int, int, int)> update = [&](int u, int l, int r, int pos) {
        if (l == r) {
            assert(v.size() == P.size());
            for (int i = 0; i < v.size(); i++) {
                dp[i][u].first += v[i].first;
                dp[i][u].second = 1LL * dp[i][u].second * v[i].second % pro[i];
            }
            return;
        }
        int mid = l + r >> 1;
        push_down(u);
        if (pos <= mid) update(u + u, l, mid, pos);
        else update(u + u + 1, mid + 1, r, pos);
        push_up(u);
    };
    vector<pair<int, int> > ans(P.size());
	function<void(int, int, int, int, int)> query = [&](int u, int l, int r, int ll, int rr) {
		if (ll <= l && r <= rr) {
            for (int i = 0; i < P.size(); i++) ans[i] = merge(ans[i], dp[i][u], i);
            return;
		}
		int mid = l + r >> 1;
		push_down(u);
		if (ll <= mid) query(u + u, l, mid, ll, rr);
		if (mid < rr) query(u + u + 1, mid + 1, r, ll, rr);
	};
    build(1, 1, n);
    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, x; cin >> l >> r >> x;
            for (int i = 0; i < P.size(); i++) {
                int y = x, j = 0;
                while (y % P[i].first == 0) y /= P[i].first, j++;
                v[i] = {j, y % pro[i]};
            }
            modify(1, 1, n, l, r);
        } else if (op == 2) {
            int pos, x; cin >> pos >> x;
            for (int i = 0; i < P.size(); i++) {
                int y = x, j = 0;
                while (y % P[i].first == 0) y /= P[i].first, j++;
                v[i] = {-j, modExp(y, pro[i] - pro[i] / P[i].first - 1, pro[i])};
            }
            update(1, 1, n, pos);
        } else {
            int l, r; cin >> l >> r;
            for (int i = 0; i < P.size(); i++) ans[i] = {P[i].second, 1};
            query(1, 1, n, l, r);
            int ret = 0, mod = 1;
            for (int i = 0; i < ans.size(); i++) {
                int cur = ans[i].second * 1LL * pw[i][min(P[i].second, ans[i].first)] % pro[i];
                ret = CRT(ret, mod, cur, pro[i]);
                mod *= pro[i];
            }
            printf("%d\n", ret);
        }
    }
    return 0;
}