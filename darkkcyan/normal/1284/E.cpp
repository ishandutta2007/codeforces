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
#define sgn(x) ((x) < 0 ? -1 : (x) > 0)
// #define rand __rand
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

typedef pair<llong, llong> point;

llong cross(const point& u, const point& v) {
    return u.xx * v.yy - u.yy * v.xx;
}

llong dot(const point& u, const point& v) {
    return u.xx * v.xx + u.yy * v.yy;
}

point operator- (const point& u, const point& v) {
    return {u.xx - v.xx, u.yy - v.yy};
}

llong comb(llong n, int k) {
    llong ans = 1;
    rep1(i, k) {
        ans *= (n - i + 1);
        ans /= i;
    }
    return ans;
}

#define maxn 3030
int n;
point a[maxn];
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) cin >> a[i].xx >> a[i].yy;

    llong ans = 5 * comb(n, 5);
    // clog << ans << endl; 
    rep(i, n) {
        point cur = a[i];
        vector<point> rest;
        rep(f, n) if (f != i) rest.push_back(a[f]);
        sort(rest.begin(), rest.end(), [&](auto const& u, auto const& v) {
                auto uc = u - cur;
                auto vc = v - cur;
                if (uc.yy == 0 and uc.xx < 0) return true;
                if (vc.yy == 0 and vc.xx < 0) return false;
                if (sgn(uc.yy) != sgn(vc.yy)) return uc.yy < vc.yy;
                return cross(uc, vc) > 0;
        });

        llong cur_ans = 0;
        int r = 0;
        rep(l, len(rest)) {
            for (; r - l < len(rest) and cross(rest[r % len(rest)] - rest[l], cur - rest[l]) >= 0; ++r);
            int cnt = r - l - 1;
            cur_ans += comb(cnt, 3);
            // clog << rest[l].xx << ' ' << rest[l].yy << ' ' << cur.xx << ' ' << cur.yy << ' ' << cnt<< ' ' << comb(cnt, 3) << endl;   
        }
        ans -= cur_ans;
    }
    cout << ans;

    return 0;
}