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

#define maxn 101010
#define maxm 1010100
int n;
bool is_asc[maxn];
int max_a[maxn], min_a[maxn];

int cnt_max[maxm];
int cnt_min[maxm];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    llong ans = 0;
    int cnt_asc = 0;
    rep(i, n) {
        is_asc[i] = false;
        max_a[i] = INT_MIN;
        min_a[i] = INT_MAX;

        int l; cin >> l;
        rep(_, l) {
            int c; cin >> c;
            if (c > min_a[i]) is_asc[i] = true;
            max_a[i] = max(max_a[i], c);
            min_a[i] = min(min_a[i], c);
        }

        cnt_asc += is_asc[i];
    }
    // clog << cnt_asc << endl; 

    ans += 2ll * cnt_asc * (n - cnt_asc) + 1ll * cnt_asc * cnt_asc;

    memset(cnt_max, 0, sizeof(cnt_max));
    memset(cnt_min, 0, sizeof(cnt_min));
    rep(i, n) {
        if (is_asc[i]) continue; 
        cnt_max[max_a[i]]++;
        cnt_min[min_a[i]]++;
    }

    rep(i, maxm - 1) cnt_min[i + 1] += cnt_min[i];
    for (int i = maxm; i-- > 1; ) cnt_max[i - 1] += cnt_max[i];

    rep(i, n) {
        if (is_asc[i]) continue; 
        ans += 1ll * cnt_min[max_a[i] - 1];
    }
    cout << ans;

    return 0;
}