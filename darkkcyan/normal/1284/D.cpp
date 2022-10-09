#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define clog if (0) cerr

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
#define rand __rand
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    return (T)(rng() % range);
}

#define maxn 501010
typedef pair<llong, llong> hs;
int n;
hs id[maxn];
pair<llong, llong> a[maxn], b[maxn];

template<class T>
struct BIT {
    T data[maxn];
    T get(llong i) {
        clog << "get " << i << endl;
        T ans;
        for (++i; i > 0; i -= i & -i)
            ans = ans + data[i];
        return ans;
    }

    void add(llong i, const T& d) {
        clog << "UPD " << i << ' ' << d.xx << endl;
        for (++i; i < maxn; i += i & -i)
            data[i] = data[i] + d;
    }

    T rev_get(llong i) { return get(maxn - i - 10); }

    void rev_add(llong i, const T& d) { add (maxn - i - 10, d);  }
};

hs operator+ (const hs& lhs, const hs& rhs) {
    return {lhs.xx ^ rhs.xx, lhs.yy ^ rhs.yy};
}

BIT<hs> fin_a, beg_a, fin_b, beg_b;
template<class T>
void do_uniq(vector<T>& container) {
    sort(container.begin(), container.end());
    container.resize(unique(container.begin(), container.end()) - container.begin());
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    vector<llong> pos_a, pos_b;
    rep1(i, n) {
        // id[i] = {rand<llong>(), rand<llong>()}; 
        id[i] = {1 << i, 1 << i};
        cin >> a[i].xx >> a[i].yy >> b[i].xx >> b[i].yy;
        a[i].xx = a[i].xx * 2 + 1;
        b[i].xx = b[i].xx * 2 + 1;
        a[i].yy = (a[i].yy + 1) * 2;
        b[i].yy = (b[i].yy + 1) * 2;
        pos_a.push_back(a[i].xx); pos_a.push_back(a[i].yy);
        pos_b.push_back(b[i].xx); pos_b.push_back(b[i].yy);
    }

    do_uniq(pos_a); do_uniq(pos_b);
    rep1(i, n) {
        a[i].xx = lower_bound(all(pos_a), a[i].xx) - pos_a.begin();
        a[i].yy = lower_bound(all(pos_a), a[i].yy) - pos_a.begin();
        b[i].xx = lower_bound(all(pos_b), b[i].xx) - pos_b.begin();
        b[i].yy = lower_bound(all(pos_b), b[i].yy) - pos_b.begin();
        clog << i << ' ' << a[i].xx << ' ' << a[i].yy << ' ' << b[i].xx << ' ' << b[i].yy << endl;
    }

    rep1(i, n) {
        fin_a.add(a[i].yy, id[i]);
        fin_b.add(b[i].yy, id[i]);
        beg_a.rev_add(a[i].xx, id[i]);
        beg_b.rev_add(b[i].xx, id[i]);
    }

    rep1(i, n) {
        auto ha = fin_a.get(a[i].xx - 1) + beg_a.rev_get(a[i].yy + 1);
        auto hb = fin_b.get(b[i].xx - 1) + beg_b.rev_get(b[i].yy + 1);
        clog << ha.xx << ' ' << ha.yy << ' ' << hb.xx << ' ' << hb .yy << endl;
        if (ha != hb) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}