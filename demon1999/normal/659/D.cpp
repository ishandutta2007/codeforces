#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define sz(a) a.size()
#define re  return
#define fi first
#define se second

typedef std::pair<int, int> pii;

using namespace std;

void my_assert(bool q) {
    if (!q) while(true);
}

int n, m, x, y, ans, xmin[40001], xmax[40001], ymin[40001], ymax[40001];
vector<pii> qq;

int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    //freopen("point.in", "r", stdin);
    //freopen("point.out", "w", stdout);
    cin >> n;
    forn(i, n + 1) {
        cin >> x >> y;
        x += 10000;
        y += 10000;
        x *= 2;
        y *= 2;
        qq.push_back(mp(x, y));
    }
    forn (i, 40001) {
        xmin[i] = 1000000;
        xmax[i] = -100000;
        ymin[i] = 1000000;
        ymax[i] = -100000;
    }
    vector<int> x, y;
    forn (i, n + 1) {
        x.push_back(qq[i].fi);
        y.push_back(qq[i].se);
    }

    forn (i, n - 1) {
        if (y[i] < y[i + 1] && x[i + 1] > x[i + 2]) ans++;
        if (y[i] > y[i + 1] && x[i + 1] < x[i + 2]) ans++;
        if (x[i] < x[i + 1] && y[i + 1] < y[i + 2]) ans++;
        if (x[i] > x[i + 1] && y[i + 1] > y[i + 2]) ans++;
    }
    cout << ans;
    return 0;
}