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

const int maxn = 100005, maxm = 200010;

struct BIT {
    int lt[maxm], tms;
    pair<int, int> val[maxm];
    void inline add(int a, pair<int, int> x) {
        while (a < maxm) {
            if (lt[a] != tms) lt[a] = tms, val[a] = x;
            else val[a] = max(val[a], x);
            a += a & -a;
        }
    }
    pair<int, int> inline get(int a) {
        pair<int, int> ans = mak(-Inf, -1);
        while (a) {
            if (lt[a] == tms) ans = max(ans, val[a]);
            a -= a & -a;
        }
        return ans;
    }
} b1, b2;

int n, m;
int a[maxn], b[maxn];
int fs[maxn], lc[maxn], rc[maxn];
int dp[maxn], pre[maxn];

bool chmax(int &a, int b) {
    if (a < b) return a = b, 1;
    else return 0;
}

void fendge(int l, int r) {
    if (l == r) return;
    int m = (l + r) >> 1;
    fendge(l, m);
    ++b1.tms; ++b2.tms;
    vector<pair<int, int> > ss;
    circ(i, l, r) if (~a[i]) ss.emb(a[i], i);
    sort(all(ss));
    parse(it, ss) {
        int i = it.second;
        if (i <= m) {
            b1.add(maxn - (lc[i] - fs[i]), mak(dp[i] - lc[i], i));
            b2.add(maxn + (lc[i] - fs[i]), mak(dp[i] - fs[i], i));
        }
        else {
            pair<int, int> res = b1.get(maxn - (rc[i] - fs[i]));
            if (chmax(dp[i], res.first + rc[i] + 1)) pre[i] = res.second;
            res = b2.get(maxn + (rc[i] - fs[i]));
            if (chmax(dp[i], res.first + fs[i] + 1)) pre[i] = res.second;
        }
    }
    fendge(m + 1, r);
}

multiset<int> rem;

void trace(int l, int r) {
    int val = a[l];
    circ(i, l, r) if (!~a[i]) {
        auto it = rem.upper_bound(val);
        if (it == rem.end() || *it >= a[r]) break;
        a[i] = val = *it;
        rem.erase(it);
    }
}

int main() {
    scanf("%d", &n);
    a[n + 1] = Inf;
    cont(i, n) scanf("%d", a + i);
    scanf("%d", &m);
    cont(i, m) scanf("%d", b + i), rem.insert(b[i]);
    sort(b + 1, b + m + 1);
    m = unique(b + 1, b + m + 1) - b - 1;
    loop(i, n + 2) {
        fs[i] = (i ? fs[i - 1] : 0) + (!~a[i]);
        if (~a[i]) {
            lc[i] = upper_bound(b + 1, b + m + 1, a[i]) - b;
            rc[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
        }
    }
    dp[0] = 1; fendge(0, n + 1);
    int now = n + 1;
    while (now) {
        trace(pre[now], now);
        now = pre[now];
    }
    cont(i, n) if (!~a[i]) a[i] = *rem.begin(), rem.erase(rem.begin());
    cont(i, n) printf("%d%c", a[i], " \n"[i == n]);
    return 0;
}