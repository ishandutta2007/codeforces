#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define V vector
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "LINE(" << __LINE__ << ") ->" << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

int nxt[N], n, s;

struct DS {
    ll add;
    map<int, ll> dp;
    multiset<ll> mn;
    DS() {
        add = 0;
    }
    void set_val(int x, ll y) {
        if(dp.count(x)) {
            assert(mn.find(dp[x]) != mn.end());
            mn.erase(mn.find(dp[x]));
        }
        dp[x] = y - add;
        mn.insert(y - add);
    }
    ll get_val(int x) {
        assert(dp.count(x));
        return dp[x] + add;
    }
    ll get_min() {
        return *mn.begin() + add;
    }
    void remove(int x) {
        assert(dp.count(x));
        mn.erase(mn.find(dp[x]));
        dp.erase(x);
    }
};
V<array<int, 3>> ops;

DS* solve(int l, int r, int k) {
    DS* ds = new DS();
    ds -> set_val(k, 0);

    for(int i = l; i < r; i++) {
        assert(ops[i][0] != 2);
        if(ops[i][0] == 0) { // set
            int y = ops[i][1], v = ops[i][2];
            if(y == s) {
                ds -> add += v;
            } else {
                ll mn = ds -> get_min();
                ds -> add += v;
                ds -> set_val(y, mn);
            }
        } else { // if
            int y = ops[i][1];
            if(ds -> dp.count(y)) {
                DS* ds2 = solve(i + 1, nxt[i], y);
                ds2 -> add += ds -> get_val(y);
                ds -> remove(y);
                if(ds2 -> dp.size() > ds -> dp.size()) swap(ds, ds2);
                for(auto p:ds2 -> dp) {
                    int x = p.F;
                    ll y = p.S + ds2 -> add;
                    if(ds -> dp.count(x) == 0 || ds -> get_val(x) > y)
                        ds -> set_val(x, y);
                }
            }
            i = nxt[i];
        }
    }
    return ds;
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> s;
    vi stk;
    for(int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if(op == "set") {
            int y, v;
            cin >> y >> v;
            ops.PB({0, y, v});
        } else if(op == "if") {
            int y;
            cin >> y;
            ops.PB({1, y, 0});
            stk.PB(i);
        } else {
            ops.PB({2, 0, 0});
            assert(stk.size());
            nxt[stk.back()] = i;
            stk.pop_back();
        }
    }
    DS* tt = solve(0, n, 0);
    cout << tt -> get_min() << '\n';

}