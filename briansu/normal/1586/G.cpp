#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

constexpr int M = 1'000'000'007;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), issp(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    {
        int t;
        cin >> t;
        for (int i = 1, s; i <= t; i++) {
            cin >> s, issp[s] = 1;
        }
    }
    vector<int> dt(n);
    iota(ALL(dt), 1);
    sort(ALL(dt), [&](int x, int y) {
        return a[x] > a[y];  
    });

    int BITN = 2 * n + 1;
    vector<int> bit(BITN);
    auto add = [&](int x, int k) {
        while (x < BITN)
            bit[x] = (bit[x] + k) % M, x += x & -x; 
    };
    auto query = [&](int x) {
        long long res = 0; 
        while (x)
            res += bit[x], x -= x & -x;
        return res % M;
    };
    auto query_range = [&](int l, int r) { // [l, r]
        return (query(r) - query(l - 1) + M) % M; 
    };
    int mxsp = -1;
    ll ans = 0;
    for (int t : dt) {
        int x = query_range(a[t], b[t] - 1);  
        add(b[t], (x + 1) % M);
        if (issp[t]) {
            if (mxsp == -1 || b[mxsp] < b[t]) {
                if (mxsp != -1)
                    ans += query_range(a[t], b[mxsp] - 1);
                ans += 1;
                mxsp = t;
            }
        }
    }
    assert(mxsp != -1);
    ans += query_range(1, b[mxsp] - 1);
    cout << ans % M << endl; 
}