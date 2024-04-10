#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef pair<ld, ld> pdd;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;

pdd p[2], mid, vec;
vector<pdd> bad;
int n;
ld ans = 1e18, rad;

pdd operator-(const pdd& l, const pdd& r) { // (a+bi)*(c+di)
    return {l.f-r.f,l.s-r.s};
}

pdd operator+(const pdd& l, const pdd& r) {
    return {l.f+r.f,l.s+r.s};
}

pdd operator*(const pdd& l, const ld& r) { // (a+bi)*(c+di)
    return {l.f*r,l.s*r};
}

pdd operator*(const pdd& l, const pdd& r) { // (a+bi)*(c+di)
    return {l.f*r.f-l.s*r.s,l.f*r.s+l.s*r.f};
}

pdd operator/(const pdd& l, const ld& r) {
    return {l.f/r,l.s/r};
}

ld cross(pdd a, pdd b, pdd c) {
    b = b-a, c = c-a;
    return b.s*c.f-b.f*c.s;
}

int sgn(ld x) {
    if (x < 0) return -1;
    if (x > 0) return 1;
    return 0;
}

ld sq(pdd a, pdd b) {
    return (a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s);
}

ld dist(pdd a, pdd b) {
    return sqrt(sq(a,b));
}

ld getlo(int x, int y, int r, int sg) { // fix
    ld lo = -1e12, hi = 1e12;
    F0R(i,80) {
        ld mi = sg*(lo+hi)/2;
        pdd pos = mid+vec*mi;
        //cout << mi << " " << pos.f << " " << pos.s << "\n";
        if (sqrt(rad*rad+mi*mi)+r <= dist(pos,mp(x,y))) lo = (lo+hi)/2;
        else hi = (lo+hi)/2;
    }
    return sg*(lo+hi)/2;
}

ld gethi(int x, int y, int r, int sg) { // fix
    ld lo = -1e12, hi = 1e12;
    F0R(i,80) {
        ld mi = sg*(lo+hi)/2;
        pdd pos = mid+vec*mi;
        if (dist(pos,mp(x,y))+r <= sqrt(rad*rad+mi*mi)) hi = (lo+hi)/2;
        else lo = (lo+hi)/2;
    }
    return sg*(lo+hi)/2;
}

void process(int x, int y, int r) {
    int sg = sgn(cross(p[0],p[1],mp(x,y)));
    pdd z = {getlo(x,y,r,sg),gethi(x,y,r,sg)};
    // cout << x << " " << y << " " << r << " " << sg << " OH " << z.f << " " << z.s << "\n";
    if (z.f > z.s) swap(z.f,z.s);
    bad.pb(z);
}

void solve() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> p[0].f >> p[0].s >> p[1].f >> p[1].s;
	mid = (p[0]+p[1])/2;
	rad = dist(mid,p[1]);
	vec = (p[1]-p[0])*mp(0,-1);
	vec = vec/rad/2;
	cin >> n;
}

void finish() {
	bad.pb({-1e18,-1e18});
	bad.pb({1e18,1e18});
	sort(bad.begin(),bad.end());
	
	ld mx = -1e18;
	for (auto a: bad) {
	    if (mx < a.f) {
	        if (sgn(mx) == sgn(a.f)) {
	            ans = min(ans,sqrt(rad*rad+pow(min(abs(mx),abs(a.f)),2)));
	        }
	        else ans = min(ans,dist(p[0],p[1])/2);
	    }
	    mx = max(mx,a.s);
	}
	cout << fixed << setprecision(10) << ans;
}

int main() {
    solve();
	F0R(i,n) {
	    int x,y,r; cin >> x >> y >> r;
	    process(x,y,r);
	}
	finish();
}

// read!
// ll vs. int!