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

#define maxn 1010
int n, m;
int mark[maxn];
vector<pair<int, int>> not_sorted;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    memset(mark, 0, sizeof mark);
    rep(i, m) {
        int t, l, r; cin >> t >> l >> r;
        if (t == 1) {
            mark[l + 1] ++;
            mark[r + 1] --;
        } else not_sorted.emplace_back(l, r);
    }

    rep(i, n) mark[i + 1] += mark[i];
    rep1(i, n) mark[i] = !!mark[i];
    rep(i, n) mark[i + 1] += mark[i];

    for (auto i: not_sorted) {
        int l = i.xx, r = i.yy;
        if (mark[r] - mark[l] == r - l) {
            cout << "NO";
            exit(0);
        }
    }

    cout << "YES\n";
    int x = n + 3;
    rep1(i, n) {
        if (mark[i] - mark[i - 1] == 0)  --x;
        cout << x << ' ';
    }

    return 0;
}