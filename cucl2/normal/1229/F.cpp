#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

const int maxn = 35005;
int n;
int a[maxn], l[maxn], r[maxn];

ll check(ll s0) {
    multiset<ll, greater<ll> > ls;
    multiset<ll> rs;
    ll tl = 0, tr = 0, sm = 0;
    loop(i, n + 1) ls.insert(s0), rs.insert(s0);
    cont(i, n) {
        tl -= r[i] - a[i];
        tr += a[i] - l[i];
        if (*ls.begin() + tl <= 0 && *rs.begin() + tr >= 0) {
            ls.insert(-tl);
            rs.insert(-tr);
        }
        else if (*ls.begin() + tl > 0) {
            sm += *ls.begin() + tl;
            ls.insert(-tl);
            ls.insert(-tl);
            rs.insert(*ls.begin() + tl - tr);
            ls.erase(ls.begin());
        }
        else {
            sm += abs(*rs.begin() + tr);
            rs.insert(-tr);
            rs.insert(-tr);
            ls.insert(*rs.begin() + tr - tl);
            rs.erase(rs.begin());
        }
    }
    if (s0 < *ls.begin() + tl) {
        parse(val, ls) {
            if (val + tl < s0) break;
            sm += val + tl - s0;
        }
    }
    else {
        parse(val, rs) {
            if (val + tr > s0) break;
            sm += s0 - val - tr;
        }
    }
    return sm;
}

int main() {
    scanf("%d", &n);
    cont(i, n) scanf("%d%d%d", a + i, l + i, r + i);
    ll sm = accumulate(a, a + n + 1, 0ll);
    ll l = -sm - 1, r = sm;
    while (r - l > 1) {
        ll m = (l + r) >> 1;
        if (check(m) < check(m + 1)) r = m;
        else l = m;
    }
    printf("%lld\n", check(r));
    return 0;
}