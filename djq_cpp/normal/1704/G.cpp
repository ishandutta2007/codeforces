#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
__int128 a[200005], b[200005];
vector<__int128> as, bs;
vector<int> occa[200005], occb[200005];
void getvec(__int128 arr[], int l, vector<__int128>& ret, vector<int> occ[])
{
    ret.clear();
    rep(i, l) ret.push_back(arr[i]);
    sort(ret.begin(), ret.end());
    ret.resize(unique(ret.begin(), ret.end()) - ret.begin());
    rep(i, ret.size()) occ[i].clear();
    rep(i, l) occ[lower_bound(ret.begin(), ret.end(), arr[i]) - ret.begin()].push_back(i);
}

bitset<200005> A, B;
void addb(__int128 x)
{
    int pos = lower_bound(as.begin(), as.end(), x) - as.begin();
    if(pos == as.size() || as[pos] != x) return;
    rep(i, occa[pos].size()) B[occa[pos][i]] = !B[occa[pos][i]];
}

/*
0 1
1 -2
-2 3
3 -4
...
*/

vector<int> ans;
void gen(int mx, int cnt, LL cs, vector<int>& ret)
{
    for(int i = mx - 1; i >= 0; i --)
    if(i == cnt - 1 || cs > 1LL * cnt * (2 * i - cnt - 1)) {
        cs -= i * 2; ret.push_back(i); cnt --;
    }
}
bool check(int pos)
{
    __int128 u = b[0] - a[pos], v = b[1] - a[pos + 1];
    if(u + v < -n || u + v > n || u > 1LL * n * n || u < -1LL * n * n) return false;
    LL x = u, y = v;
    pos += 2;
    int pe = (pos + 1) >> 1, po = pos >> 1;
    for(int i = 0; i <= pe; i ++) {
        LL j = i - x - y;
        if(j < 0 || j > po) continue;
        LL cx = x - j;
        if(cx & 1) continue;
        LL mne = 1LL * i * (i - 1), mxe = 1LL * i * (2 * pe - i - 1);
        LL mno = 1LL * j * (j - 1), mxo = 1LL * j * (2 * po - j - 1);
        LL cur = max(mne, mno - cx);
        if(cur <= min(mxe, mxo - cx)) {
            vector<int> ae, ao;
            gen(pe, i, cur, ae);
            gen(po, j, cx + cur, ao);
            rep(k, ae.size()) ans.push_back(pos - 1 - 2 * ae[k]);
            rep(k, ao.size()) ans.push_back(pos - 2 - 2 * ao[k]);
            return true;
        }
    }
    return false;
}
void solve()
{
    scanf("%d", &n);
    rep(i, n) {
        LL x; scanf("%lld", &x); a[i] = x;
    }
    scanf("%d", &m);
    rep(i, m) {
        LL x; scanf("%lld", &x); b[i] = x;
    }
    for(int i = n - 2; i >= 0; i --) a[i + 1] += a[i];
    for(int i = n - 2; i >= 0; i --) a[i + 1] += a[i];
    for(int i = m - 2; i >= 0; i --) b[i + 1] += b[i];
    for(int i = m - 2; i >= 0; i --) b[i + 1] += b[i];

    getvec(a, n, as, occa);
    getvec(b + 2, m - 2, bs, occb);

    rep(i, n) A[i] = i <= n - m;
    rep(i, bs.size()) {
        addb(bs[i]); addb(bs[i] - 1);
        rep(j, occb[i].size()) A &= B >> (occb[i][j] + 2);
        addb(bs[i]); addb(bs[i] - 1);
    }

    rep(i, n - 1) a[i + 1] -= a[i];
    rep(i, n - 1) a[i + 1] -= a[i];
    rep(i, m - 1) b[i + 1] -= b[i];
    rep(i, m - 1) b[i + 1] -= b[i];

    ans.clear();
    int ret = -1;
    rep(i, n) if(A[i] && check(i)) {
        ret = i; break;
    }
    if(ret == -1) printf("-1\n");
    else {
        for(int i = n - 2; i >= 0; i --) a[i + 1] += a[i];
        for(int i = n - 2; i >= 0; i --) a[i + 1] += a[i];
        for(int i = m - 2; i >= 0; i --) b[i + 1] += b[i];
        for(int i = m - 2; i >= 0; i --) b[i + 1] += b[i];

        for(int i = 2; i < m; i ++) if(a[i + ret] < b[i]) ans.push_back(i + ret);
        printf("%d\n", (int)ans.size());
        rep(i, ans.size()) printf("%d ", ans[i] + 1); printf("\n");
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}