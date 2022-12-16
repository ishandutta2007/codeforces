#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

ll ax, ay, bx, by;

struct pt {
    ll x, y;
    pt() {}
    pt(ll a, ll b) :x(a), y(b) {}
    bool can_nxt() {
        return ((ld) ax*x+bx < 1e17 && (ld) ay*y+by < 1e17);
    }
    pt nxt() const {
        return pt(ax*x+bx, ay*y+by);
    }
    ll dist(const pt& o) const {
        return abs(x-o.x) + abs(o.y-y);
    }
};

vector<pt> pts;
pt s;
ll t;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    pts.push_back(pt(0, 0));
    cin >> pts.back().x >> pts.back().y;
    cin >> ax >> ay >> bx >> by;
    cin >> s.x >> s.y >> t;

    while (pts.back().can_nxt()) {
        pts.push_back(pts.back().nxt());
    }

    //cerr << pts[3].x << "," << pts[3].y << " :: " << pts[4].x << " " << pts[4].y << endl;

    int ans = 0;
    for (int i=0; i<pts.size(); ++i) {
        ll di = 0;
        int cnt = 0;
        pt cur = s;
        for (int j=i; j<pts.size(); ++j) {
            di += cur.dist(pts[j]);
            //cerr << "  " << j << " : " << di << endl;
            if (di > t) break;
            cnt ++;
            cur = pts[j];
        }
        ans = max(ans, cnt);

        di = 0;
        cnt = 0;
        cur = s;
        for (int j=i; j>=0; --j) {
            di += cur.dist(pts[j]);
            //cerr << "  " << j << " : " << di << endl;
            if (di > t) break;
            cnt ++;
            cur = pts[j];
        }

        //cerr << "DI " << di << " : " << i << " : " << cnt << endl;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}