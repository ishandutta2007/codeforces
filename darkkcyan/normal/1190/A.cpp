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

#define maxm 101010
llong n, m, k;
llong pos[maxm];

llong find_page(llong cur_pos, llong deleted) {
    assert(cur_pos >= deleted);
    llong real_pos = cur_pos - deleted;
    return real_pos / k;
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    rep(i, m) cin >> pos[i], --pos[i];

    llong deleted = 0;
    int i = 0;
    llong ans = 0;
    while (i < m) {
        llong cur_page = find_page(pos[i], deleted);
        llong cnt_deleting = 0;
        for (; i < m and find_page(pos[i], deleted) == cur_page; ++i) ++cnt_deleting;
        deleted += cnt_deleting;
        ++ans;
    }
    cout << ans;

    return 0;
}