#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <cassert>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define re  return
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
using namespace std;

const int ma = 131072 * 8;
int n, m, segtr[2 * ma], ans[ma], dp1[ma], dp2[ma], pos[ma];
vector<int> a;
vector<pii> c, b, q[600000];
string s;

int mx(int l, int r) {
    if (l > r) re 0;
    if (l % 2) re max(segtr[l], mx(l + 1, r));
    if (r % 2 == 0) re max(segtr[r], mx(l, r - 1));
    re mx(l / 2, r / 2);
}

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qq.in", "r",  stdin));
    cin >> n >> m;
    a.resize(n);
    forn (i, n) {
        cin >> a[i];
        c.push_back(mp(a[i], i));
    }
    b.resize(m);
    forn (i, m) {
        cin >> b[i].fi >> b[i].se;
        b[i].fi--;
        c.push_back(mp(b[i].se, i + n));
    }
    sort(c.begin(), c.end());
    int k = 1;
    forn(i, sz(c)) {
        if (i && c[i].fi > c[i - 1].fi) k++;
        //cout << c[i].fi << " " << c[i].se << " " << k << endl;
        if (c[i].se < n) a[c[i].se] = k;
        else b[c[i].se - n].se = k;
    }
    /*forn (i, n) {
        cout << a[i] << " ";
    }
    cout << endl;*/
    forn (i, m) {
        //cout << b[i].se << endl;
        q[b[i].fi].push_back(mp(b[i].se, i));
    }
    //cout << endl;
    int lis = 0;
    forn (i, n) {
        for (auto v : q[i]) {
            ans[v.se] += 1 + mx(ma, ma + v.fi - 1);
        }
        dp1[i] = mx(ma, ma + a[i] - 1) + 1;
        lis = max(lis, dp1[i]);
        int nu = a[i] + ma;
        segtr[nu] = max(segtr[nu], dp1[i]);
        while (nu / 2) {
            nu /= 2;
            segtr[nu] = max(segtr[2 * nu], segtr[2 * nu + 1]);
        }
    }
    forn (i, 2 * ma)
        segtr[i] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (auto v : q[i]) {
            ans[v.se] += mx(ma + v.fi + 1, 2 * ma - 1);
        }
        dp2[i] = mx(ma + a[i] + 1, 2 * ma - 1) + 1;
        int nu = a[i] + ma;
        segtr[nu] = max(segtr[nu], dp2[i]);
        while (nu / 2) {
            nu /= 2;
            segtr[nu] = max(segtr[2 * nu], segtr[2 * nu + 1]);
        }
    }
    forn (i, n) {
        if (dp1[i] + dp2[i] - 1 == lis) {
            pos[dp1[i]]++;
        }
    }
    /*forn (i, m) {
        cout << ans[i] << endl;
    }*/
    forn (i, n) {
        int k = lis;
        if (dp1[i] + dp2[i] - 1 == lis && pos[dp1[i]] == 1) k--;
        for (auto v : q[i])
            ans[v.se] = max(ans[v.se], k);
    }
    forn (i, m) {
        cout << ans[i] << endl;
    }
    return 0;
}