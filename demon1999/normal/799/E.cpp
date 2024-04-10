#include <iostream>
#include <bits/stdc++.h>
 
 
using namespace std;
 
#define re return
#define mp make_pair
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) int(a.size())
#define fi first
#define se second
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int ma = 256 * 1024;

ll n, m, k, c[300000], aa[300000], nc[300000];
ll seg1[2 * ma], seg2[2 * ma];
vector<pair<ll, ll> > cc;

vector<ll> p[4];

int get_int() {
    char c = getchar();
    int ans = 0 ;
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        ans = 10 * ans + c - '0';
        c = getchar();
    }
    re ans;
}

void insert_(int ps) {
    int nuk = ps + ma;
    while (nuk) {
        seg1[nuk]++;
        seg2[nuk] += nc[ps];
        nuk /= 2;
    }
}

ll get_sum(int nu, int l, int r, ll k) {
    if (l + 1 == r) {
        re nc[nu - ma] * k;
    }
    int mid = (l + r) / 2;
    //ll ans = 0;
    if (seg1[2 * nu] >= k) {
        re get_sum(2 * nu, l, mid, k);
    } else
        re get_sum(2 * nu + 1, mid, r, k - seg1[2 * nu]) + seg2[2 * nu];
}
int main() {
    //iostream::sync_with_stdio(0), cin.tie(0);
    n = get_int(); m = get_int();
    k = get_int();
    forn (i, n) {
        c[i] = get_int();
        cc.push_back(mp(c[i], i));
    }
    sort(cc.begin(), cc.end());
    int kp = -1;
    forn (i, sz(cc)) {
        if (i == 0 || cc[i].fi > cc[i - 1].fi) {
            kp++;
            nc[kp] = cc[i].fi;
        }
        c[cc[i].se] = kp;
    }
    int ap = get_int();
    forn (i, ap) {
        int q = get_int();
        q--;
        aa[q] += 1;
    }
    ap = get_int();
    forn (i, ap) {
        int q = get_int();
        q--;
        aa[q] += 2;
    }
    forn (i, n) {
        p[aa[i]].push_back(c[i]);
    }
    forn (i, 4)
        sort(p[i].begin(), p[i].end());
    ll ans = ll(1e9) * ll(300000);
    forn (i, sz(p[0])) {
        insert_(p[0][i]);
    }

    ll summ = 0, sum1 = 0, sum2 = 0, uk1 = sz(p[1]), uk2 = sz(p[2]);
    forn (i, sz(p[1])) {
        sum1 += nc[p[1][i]];
    }
    forn (i, sz(p[2])) {
        sum2 += nc[p[2][i]];
    }
    for (int kk = 0; kk <= sz(p[3]); kk++) {
        //cout << summ << " " << uk1 << " " << uk2 << "\n";
        while (uk1 > k - kk && uk1 > 0) {
            uk1--;
            sum1 -= nc[p[1][uk1]];
            insert_(p[1][uk1]);
        }
        while (uk2 > k - kk && uk2 > 0) {
            uk2--;
            sum2 -= nc[p[2][uk2]];
            insert_(p[2][uk2]);
        }
        if (uk1 >= k - kk && uk2 >= k - kk && seg1[1] >= m - uk1 - uk2 - kk && m >= uk1 + uk2 + kk) {
            ans = min(ans, summ + sum1 + sum2 + get_sum(1, ma, 2 * ma, m - uk1 - uk2 - kk));
        }
        if (kk < sz(p[3]))
            summ += nc[p[3][kk]];
    }

    if (ans > ll(1e9) * n) {
        cout << -1;
    } else
        cout << ans;
    re 0;
}