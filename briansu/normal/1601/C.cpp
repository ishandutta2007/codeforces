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

const int MAXn = 1e6 + 5;

int a[MAXn], b[MAXn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= m; i++)
            cin >> b[i];
        sort(b + 1, b + 1 + m);

        // vector<int> tg(2 * n, 0), seg(2 * n, 0);
        // auto pull = [&](int x) {
        //     seg[x] = min(seg[x<<1], seg[x<<1|1]) + tg[x];   
        // };
        // auto upd = [&](int x) {
        //     for (x += n, seg[x] = tg[x]; x > 1; x >>= 1)
        //         pull(x>>1);
        // };
        // auto insert = [&](int l, int r, int k) {
        //     int li = l, ri = r;
        //     for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        //         if (l & 1) tg[l++] += k;
        //         if (r & 1) tg[--r] += k;
        //     }
        //     upd(l);
        //     upd(ri - 1);
        // };
        // auto query_all = [&]() {
        //     int res = 0;        
        //     for (int l = n, r = n + n; l < r; l >>= 1, r >>= 1) {
        //         if (l & 1) res = min(res, tg[l++]);
        //         if (r & 1) res = min(res, tg[--r]);
        //     }
        //     return res;
        // }
        // for (int i = 0; i < n; i++)
        //     insert(i, n, 1);

        set<int> st;
        for (int i = 1; i <= n; i++)
            st.insert(st.end(), i);
        ll cur = 0, ans = 0;

        auto dec = [&](int x) {
            auto it = st.upper_bound(x);
            if (it == st.begin())
                --cur;
            else
                st.erase(prev(it));
        };

        vector<int> dt(n);
        for (int i = 0; i < n; i++)
            dt[i] = i + 1;
        sort(ALL(dt), [](int x, int y) { return a[x] < a[y]; });
        int it1 = 0, it2 = 0;
        for (int i = 1; i <= m; i++) {
            while (it1 < SZ(dt) && a[dt[it1]] <= b[i])
                dec(dt[it1++]);
            while (it2 < SZ(dt) && a[dt[it2]] < b[i])
                dec(dt[it2++]);
            ans += it2 + cur;
        }

        vector<int> bit(n + 1), uni;

        auto ins = [&](int x, int k) {
            while (x <= n)
                bit[x] += k, x += x & -x;
        };
        auto qr = [&](int x) {
            int res = 0;
            while (x)
                res += bit[x], x -= x & -x;
            return res;
        };

        for (int i = 1; i <= n; i++)
            uni.pb(a[i]);
        sort(ALL(uni));
        uni.resize(unique(ALL(uni)) - uni.begin());
        for (int i = n; i >= 1; i--) {
            int t = lower_bound(ALL(uni), a[i]) - uni.begin();
            t++;
            ans += qr(t - 1);
            ins(t, 1);
        }
        cout << ans << endl;
    }

    
}