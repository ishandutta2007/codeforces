#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const ld EPS = 1e-10;

struct pt {
    ld x, y;
    pt() {}
    pt(ld a, ld b) : x(a), y(b) {}
    pt operator+ (const pt& o) const { return pt(x+o.x, y+o.y); }
    pt operator- (const pt& o) const { return pt(x-o.x, y-o.y); }
    pt operator* (const ld& o) const { return pt(x*o, y*o); }
    pt operator/ (const ld& o) const { return pt(x/o, y/o); }
    bool operator== (const pt& o) const {
        return (abs(x-o.x) < EPS && abs(y-o.y) < EPS);
    }
};

inline ld dp(const pt& a, const pt& b) {
    return a.x*b.x + a.y*b.y;
}
inline ld cp(const pt& a, const pt& b) {
    return a.x*b.y - a.y*b.x;
}
inline int sgn(const ld& x) {
    return (abs(x) < EPS ? 0 : (x < 0 ? -1 : 1));
}

inline ld abs(const pt& a) {
    return sqrt(a.x*a.x + a.y*a.y);
}

inline pt line_inter(const pt &a, const pt &b, const pt &c, const pt &d) {
  return a + (b-a) * cp(c - a, d - c) / cp(b - a, d - c); }

const int NMAX = 1010;

int n;
pt pts[NMAX];
pt A, B;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;++i) {
        int a, b;
        cin >> a >> b;
        pts[i].x = a;
        pts[i].y = b;
    }
    pts[n+1] = pts[1];

    A = pts[1];
    B = pts[2];

    ld uv = abs(B-A);
    ld mn = 0, mx = uv;

    for(int i=2;i<=n;++i) {
        int sa = sgn(cp(pts[i+1]-pts[i], A-pts[i]));
        int sb = sgn(cp(pts[i+1]-pts[i], B-pts[i]));
        if(sa == sb) {
            if(sa == 1) {
                //cerr << " init fail " << endl;
                cout << 0 << endl;
                return 0;
            }
            continue;
        } else if(sa == -1) {
            if(sb == 0) {
                continue;
            }
            pt isec = line_inter(pts[i], pts[i+1], A, B);
            ld len = abs(isec-A);
            mx = min(mx, len);
        } else if(sb == -1) {
            if(sa == 0) {
                continue;
            }
            pt isec = line_inter(pts[i], pts[i+1], A, B);
            ld len = abs(isec-A);
            mn = max(mn, len);
        } else if(sa == 0) {
            mx = min(mx, (ld) 0);
        } else if(sb == 0) {
            mn = max(mn, uv);
        } else {
            assert(false);
        }
    }

    ll g = __gcd((int) (abs((A-B).x)+EPS), (int) (abs((A-B).y)+EPS));
    ld ulen = sqrt((A-B).x*(A-B).x+(A-B).y*(A-B).y)/g;
    ll num = g;
    if(sgn((A-B).x) == 0 || sgn((A-B).y) == 0) {
        num = max(abs((A-B).x)+EPS, abs((A-B).y)+EPS);
        ulen = 1;
    }

    //cerr << " ulen " << ulen << " vs " << uv << " vs " << mn << ", " << mx << endl;

    int top = int((mn-EPS+ulen)/ulen);
    int bot = num-int((mx+EPS)/ulen);

    cerr << " top cover " << top << " bot cover " << bot << " :: " << (num+1) << " :: " << num << " .. " << mx+EPS << " " << (mx+EPS)/ulen << endl;

    int ans = (num+1)-top-bot;

    ans = max(ans, 0);

/*
    pt h = A;
    pt dp(((int)(abs((A-B).x)+EPS))/g, ((int)(abs((A-B).y)+EPS))/g);
    int ans = 0;
    while(true) {
        ld vv = abs(h-A);
        if(mn < vv+EPS && mx > vv-EPS) {
            ++ ans;
        }
        if(h == B) {
            break;
        }
        h = h+dp;
    } */

    cout << ans << endl;
    
    return 0;
}