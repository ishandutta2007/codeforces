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

#define inf ((int)1e7)
#define maxn 201010
int n, m;
int a[maxn];
pair<int, int> b[maxn];
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        cin >> n;
        rep(i, n) cin >> a[i];
        cin >> m;
        rep(i, m) cin >> b[i].xx >> b[i].yy;
        sort(b, b + m);

        int cur = 0;
        rep(i, m) {
            while (cur > 0 and b[cur - 1].yy <= b[i].yy) --cur;
            b[cur++] = b[i];
        }

        m = cur;
        int ans = 0;
        int cur_max = 0;
        int prev = -inf;
        
        rep(i, n) {
            cur_max = max(cur_max, a[i]);
            auto cur_hero = lower_bound(b, b + m, make_pair(cur_max, 0), [](const pair<int, int>& u, const pair<int, int>& v) {
                return u.xx < v.xx;
            });
            if (cur_hero == b + m) {
                ans = -1;
                break;
            }

            if (cur_hero->yy < i - prev + 1) {
                ++ans;
                prev = i;
                cur_max = a[i];
            }
        }
        cout <<ans << '\n';
    }

    return 0;
}