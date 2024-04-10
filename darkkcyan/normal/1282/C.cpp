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
int n;
llong a, b;
llong total_time;
int prob_type[maxn];
int total_cnt[2];
map<llong, int[2]> cnt;

int cal_additional(llong time_left, int cnt1, int cnt2) {
    if (cnt1 * a >= time_left) return (int)(time_left / a);
    return cnt1 + min((int)((time_left - a * cnt1) / b), cnt2);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        cin >> n >> total_time >> a >> b;
        cnt.clear();
        total_cnt[0] = total_cnt[1] = 0;
        rep(i, n) {
            cin >> prob_type[i];
            ++total_cnt[prob_type[i]];
        }

        rep(i, n) {
            llong t; cin >> t;
            cnt[t][prob_type[i]]++;
        }
        cnt[0];
        cnt[total_time + 1];

        int ans = 0;
        int cur_cnt[2] = {0, 0};
        for (auto i = cnt.begin(); i != prev(cnt.end()); ++i) {
            auto [cur_time, c] = *i;
            auto next_time = next(i)->xx;
            cur_cnt[0] += c[0];
            cur_cnt[1] += c[1];
            llong time_left = next_time - 1 - cur_cnt[0] * a - cur_cnt[1] * b;
            // clog << cur_time << ' ' << cur_cnt[0] << ' ' << cur_cnt[1] << ' ' << time_left << endl;
            if (time_left >= 0) {
                ans = max(ans, cur_cnt[0] + cur_cnt[1] +
                        cal_additional(time_left, total_cnt[0] - cur_cnt[0], total_cnt[1] - cur_cnt[1])
                );
                // clog << "pick" << endl;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}