#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <set>
#define fi first
#define se second
using namespace std;

template<typename A>
A abs(A x) {
    if(x < 0) return -x;
    return x;
}

template<typename A>
A gcd(A a, A b) {
    if(a < b) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a%b);
}

template<typename A>
pair<A, A> make_fraction(A a, A b) {
    if(b < 0) {
        a = -a;
        b = -b;
    }
    if(b == 0) {
        a = 1;
    }
    A cu = gcd(abs(a), abs(b));
    return make_pair(a/cu, b/cu);
}

typedef pair<int, int> pii;
typedef pair<int64_t, int64_t> puu;
map<pii, int> slos;
set<pair<pii, puu>> lines;
vector<pii> poles;

puu genericIntercept(const pii& a, const pii& slope) {
    if(slope.se == 0) {
        // get x-intercept instead
        return make_pair(a.fi, 0);
    }
    return make_fraction((int64_t)a.se * slope.se - slope.fi * a.fi, (int64_t) slope.se);
}

int main() {
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        poles.push_back(make_pair(x, y));
    }
    long long culine = 0;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++) {
            int run = poles[i].fi - poles[j].fi;
            int rise = poles[i].se - poles[j].se;
            auto slope = make_fraction(rise, run);
            auto intercept = genericIntercept(poles[i], slope);
            auto isl = make_pair(slope, intercept);
            //cout << i << ' ' << j << ' ';
            //cout << slope.fi << ' ' << slope.se << ' ' << intercept.fi << ' ' << intercept.se << endl;
            if(lines.find(isl) != lines.end()) continue;
            lines.insert(isl);
            slos[slope] += 1;
            culine += 1;
        }
    //cout << culine << endl;
    long long orig = (culine*(culine-1))/2;
    for(const auto& el:slos) {
        orig -= (el.second*(el.second-1))/2;
        //cout << el.second << endl;
    }
    cout << orig << endl;
}