#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int n;
const ld EPS = 1e-9;

struct pt {
    ld x, y;
    int ind;
    pt() {}
    pt(ld a, ld b) : x(a), y(b) {}
    pt(ld a, ld b, int i) : x(a), y(b), ind(i) {}
    pt operator+ (const pt& o) const { return pt(x+o.x, y+o.y); }
    pt operator- (const pt& o) const { return pt(x-o.x, y-o.y); }
    pt operator* (const ld& o) const { return pt(x*o, y*o); }
    bool operator < (const pt& o) {
        if(x == o.x) return y < o.y;
        return x < o.x;
    }
};

ld dp(const pt& a, const pt& b) {
    return a.x*b.x+a.y*b.y;
}
ld cp(const pt& a, const pt& b) {
    return a.x*b.y-a.y*b.x;
}
ld norm(const pt& a) {
    return sqrt(dp(a, a));
}


vector<pt> v;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; ++i) {
        int x, y;
        cin >> x >> y;
        pt p(x, y, i);
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    pt fi = v[0], se;
    for(int i=1; i<n; ++i) {
        if(fi.x == v[i].x) continue;
        se = v[i]; break;
    }
    cout << fi.ind << " " << se.ind << " ";
    ld dist = 3e9;
    int choice = 0;
    for(int i=1; i<n; ++i) {
        if(se.ind == v[i].ind) continue;
        ld val = norm(v[i]-fi-(se-fi)*(dp(v[i]-fi, se-fi)/dp(se-fi, se-fi)));
        if(val < dist && val > EPS) {
            dist = val;
            choice = v[i].ind;
        }
    }
    cout << choice << "\n";
    return 0;
}