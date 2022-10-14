#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll

using db=double;

db p[100005], q[100005];
int cx, cy;

db f(int n, db x, db y) {
    cx = cy = 0;
    db r = 0;
    rep(i, n) {
        db nn = 0;
        db yn = p[i] - x;
        db ny = q[i] - y;
        db yy = p[i] + q[i] - p[i] * q[i] - x - y;
        db mx = max(max(nn, yn), max(ny, yy)) - 1e-7;
        if(yy >= mx) cx++, cy++, r += yy;
        else if(yn >= mx) cx++, r += yn;
        else if(ny >= mx) cy++, r += ny;
    }
    return r;
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, a, b; cin >> n >> a >> b;
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];
    double x = 0, y = 0;
    for(double s = 0.5; s >= 1e-9; s /= 2) {
        double tx = x + s;
        double yp = 0;
        for(double S = 0.5; S >= 1e-9; S /= 2) {
            double ty = yp + S;
            double r = f(n, tx, ty);
            if(cy >= b) yp = ty;
        }
        f(n, tx, yp);
        if(cx >= a) x = tx, y = yp;
    }
    cout << fixed << setprecision(10) << f(n, x, y) + x * a + y * b << endl;
}