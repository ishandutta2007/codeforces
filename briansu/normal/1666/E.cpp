#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back


int a[112345];
int L, n;

int find_max() {
    int l = 0, r = L; // (l, r]
    while (l != r - 1) {
        int h = (l + r) / 2; 
        int cur = 0, ok = 1;
        for (int i = 0; i < n; i++) {
            cur = min(a[i + 1], cur + h);
            if (cur < a[i]) {
                ok = 0;
                break;
            }
        }
        if (cur < L || !ok)
            l = h;
        else
            r = h;
    }
    return r;
}

struct tag {
    int l, r, mn, lft;  
};

pair<bool, vector<int>> cal(int mn, int mx) {
    assert(mx >= mn);
    vector<int> res(n + 1);
    vector<tag> stk;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        // try as much as possible
        int poss = min(a[i + 1] - cur, mx);
        if (cur + poss < a[i])
            return {false, {}};
        if (poss >= mn)
            res[i] = poss, cur += poss, stk.pb({i, i, cur - a[i], min(cur - a[i], poss - mn)});
        else {
            int x = mn - poss;  // need to shrink x in total
            tag p = {i, i, a[i + 1] - a[i], 0};
            while (x > 0 && SZ(stk)) {
                auto &pp = stk.back();
                if (pp.lft > 0) {
                    int k = min(pp.lft, x);
                    pp.lft -= k; pp.mn -= k;
                    assert(pp.l == pp.r);
                    res[pp.l] -= k;
                    x -= k;
                }
                if (x == 0)
                    break;
                if (pp.mn < x)
                    return {false, {}};
                p.mn = min(p.mn, pp.mn - x);
                p.l = pp.l;
                stk.pop_back();
            }
            if (x > 0)
                return {false, {}};
            stk.pb(p);
            res[i] = mn;
            cur = a[i + 1];
        }
    }
    if (cur != L)
        return {false, {}};
    return {true, res};
}

int find_min(int mx) {
    int l = 1, r = mx + 1; // [l, r)
    while (l != r - 1) {
        int h = (l + r) / 2;
        auto p = cal(h, mx);
        if (p.X)
            l = h;
        else
            r = h;
    }
    return l;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> L >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[n] = L;

    int mx = find_max();
    int mn = find_min(mx);
    auto p = cal(mn, mx);
    int cur = 0;
    for (int i = 0; i < n; i++)
        cout << cur << " " << cur + p.Y[i] << "\n", cur += p.Y[i];
}