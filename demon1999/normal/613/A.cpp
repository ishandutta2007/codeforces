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
#define re  return
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
using namespace std;
const long double pi = 3.141592653589;
const int ma = 1048576;
ll a, b, n;
ld x, y, xx, yy;
ld Rmin = 1e12 + 1, Rmax = -1;
vector<pair<ld, ld> > qq;
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r",  stdin);
    cin >> n >> x >> y;
    forn (i, n) {
        cin >> xx >> yy;
        qq.push_back(mp(xx, yy));
        ld R = (x - xx) * (x - xx) + (y - yy) * (y - yy);
        Rmin = min(Rmin, R);
        Rmax = max(Rmax, R);
    }
    forn (i, n) {
        ld a = qq[i].se - qq[(i + 1) % n].se, b = qq[(i + 1) % n].fi - qq[i].fi;
        ld c = -a * qq[i].fi - b * qq[i].se;
        ld R = abs(a * x + b * y + c) / sqrt(a * a + b * b);
        R = R * R;
        if ((x - qq[i].fi) * (qq[(i + 1) % n].fi - qq[i].fi) + (y - qq[i].se) * (qq[(i + 1) % n].se - qq[i].se) > -(1e-9) &&
            (x - qq[(i + 1) % n].fi) * ( - qq[(i + 1) % n].fi + qq[i].fi) + (y - qq[(i + 1) % n].se) * (-qq[(i + 1) % n].se + qq[i].se) > -(1e-9))
            Rmin = min(Rmin, R);

    }
    ld ans = (Rmax - Rmin) * pi;
    cout.precision(30);
    cout << ans << endl;
    return 0;
}