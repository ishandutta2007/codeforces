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
// mt19937 rand(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

#define maxn 201010
struct Bit {
    int data[maxn];
    Bit() {
        memset(data, 0, sizeof(data));
    }

    int get(int i) {
        int ans = 0;
        for (++i; i > 0; i -= i & -i) ans += data[i];
        return ans;
    }

    void upd(int i, int val) {
        for (++i; i < maxn; i += i & -i) data[i] += val;
    }
} bit;

int x[maxn], y[maxn];
int n;
map<int, vector<int>> y_group;
int cnt_x[maxn];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> xvals;
    rep(i, n) {
        cin >> x[i] >> y[i];
        xvals.push_back(x[i]);
    }


    sort(all(xvals));
    xvals.resize(unique(all(xvals)) - xvals.begin());
    memset(cnt_x, 0, sizeof(cnt_x));
    rep(i, n) {
        x[i] = (int)(lower_bound(all(xvals), x[i]) - xvals.begin());
        cnt_x[x[i]]++;
        y_group[y[i]].push_back(x[i]);
    }

    llong ans = 0;
    rep(i, len(xvals)) bit.upd(i, 1);

    for (auto& y_layer: y_group) {
        llong n_xvals = bit.get(len(xvals) + 1);
        // clog << n_xvals<< endl;

        auto& xs = y_layer.yy;
        sort(xs.begin(), xs.end());

        for (auto i: xs) bit.upd(i, -1);

        llong cur_ans = 1ll * n_xvals * (n_xvals + 1) / 2;
        int prev = 0;
        for (auto i: xs) {
            int cur = bit.get(i);
            llong cnt = cur - prev;
            // clog << i << ' ' << cnt << endl;
            cur_ans -= cnt * (cnt + 1) / 2;
            prev = cur;
        }
        llong cnt = bit.get(len(xvals) + 1) - prev;
        // clog << cnt << endl;
        cur_ans -= cnt * (cnt + 1) / 2;
        // clog << y_layer.xx << ' ' << cur_ans << endl << endl;

        for (auto i: xs) {
            if (--cnt_x[i] == 0) continue;
            bit.upd(i, 1);
        }
        ans += cur_ans;
    }
    cout << ans;

    return 0;
}