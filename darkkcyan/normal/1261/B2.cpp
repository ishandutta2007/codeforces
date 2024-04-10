#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

#define maxn 201010
#define maxlogn 18
int l2[maxn];
void cal_l2() {
    l2[1] = 0;
    for (int i = 2; i < maxn; ++i) l2[i] = l2[i / 2] + 1;
}

int n;
int a[maxn];

struct BIT {
    int sum[maxn];
    BIT() {
        memset(sum, 0, sizeof(sum));
    }

    void upd(int i, int val = 1) {
        for (++i; i < maxn; i += i & -i) sum[i] += val;
    }

    int get(int i, int ans = 0) {
        for (++i; i > 0; i -= i & -i) ans += sum[i];
        return ans;
    }

    int lower_bound(int val) {
        int cur = 0;
        int id = 0;
        for (int i = maxlogn; i--; ) {
            if (id + (1 << i) >= maxn) continue;
            if (cur + sum[id + (1 << i)] >= val) continue;
            id += 1 << i;
            cur += sum[id];
        }
        // clog << val << ' ' << cur << ' ' << id << endl;
        return id;
    }
} bit;

vector<pair<int, int*>> queries[maxn];
int ans[maxn];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) cin >> a[i];
    vector<pair<int, int>> max_a;
    rep(i, n) max_a.emplace_back(a[i], i);
    sort(max_a.begin(), max_a.end(), [](const pair<int, int>& u, const pair<int, int>& v) {
            llong d = u.xx - v.xx;
            if (d == 0) return u.yy < v.yy;
            return d > 0;
    });

    int m; cin >> m;
    rep(i, m) {
        int k, p; cin >> k >> p;
        queries[k].emplace_back(p, ans + i);
    }

    rep1(cur_len, n) {
        bit.upd(max_a[cur_len - 1].yy);
        for (auto [pos, p_ans]: queries[cur_len]) {
            // clog << p_ans - ans << endl;
            // clog << p_ans - ans << ' ' << bit.lower_bound(pos) << endl;
            *p_ans = a[bit.lower_bound(pos)];
        }
    }
    rep(i, m) cout << ans[i] << '\n';

    return 0;
}