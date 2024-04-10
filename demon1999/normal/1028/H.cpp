#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;
const int CMAX = int(5e6) + int(1e5);
int n, q, best[15], ans[1100000], a[200000], lst[CMAX][8], rc[CMAX], pk[CMAX];
short cnt[CMAX];
vector<pair<int, int> > qr[200000];
vector<int> p;

void pr(int j, int k, int a, int i) {
    if (j == sz(p)) {
        //cout << i << " " << k << " " << cnt[a / k] << "\n";
        forn (q, 8) {
            best[q + cnt[a / k]] = max(best[q + cnt[a / k]], lst[k][q]);
        }
        lst[k][cnt[a / k]] = i;
        return;
    }
    pr(j + 1, k, a, i);
    pr(j + 1, k * p[j], a, i);
}

void relax(int a, int i) {
    p.resize(0);
    a = pk[a];
    //cout << a << " ";
    int na = a;
    while (a >1) {
        p.push_back(rc[a]);
        a /= rc[a];
    }
    pr(0, 1, na, i);
}

int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 2; i < CMAX; i++) {
        if (rc[i] == 0) {
            for (int j = i; j < CMAX; j += i)
                rc[j] = i;
        }
        cnt[i] = 0;
        pk[i] = 1;
        int k = i;
        while (k > 1) {
            int q = rc[k];
            cnt[i]++;
            int ct = 0;
            while (k % q == 0) {
                k /= q;
                ct ^= 1;
            }
            if (ct) pk[i] *= q;
        }
    }
    forn (i, n) cin >> a[i];
    forn (i, q) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        qr[r].push_back(mp(l, i));
    }
    forn (i, 15) best[i] = -1;
    forn (i, CMAX) {
        forn (j, 8) lst[i][j] = -1;
    }
    forn (i, n) {
        relax(a[i], i);
        sort(qr[i].begin(), qr[i].end());
        int an = 0;
        for (auto v : qr[i]) {
            while (an < 14 && best[an] < v.fi)
                an++;
            ans[v.se] = an;
        }
    }
    forn (i, q) {
        cout << ans[i] << "\n";
    }
    return 0;
}