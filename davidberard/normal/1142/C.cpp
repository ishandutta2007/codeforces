#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const ld EPS = 1e-10;
const ld INF = 1e20;

struct line {
    ld m, c, start;
    line() :start(-INF) {}
    line(ld a, ld b) : m(a), c(b), start(-INF) {}
    const ld eval(const ld& x) { return m * x + c; }
    const ld intersectX(const line& l) { return (c - l.c) / (l.m - m); }
    bool operator< (const line& o) {
        return m < o.m;
    }
};

struct hull {
    vector<line> lines;
    void insert(const line& l) {
        while(lines.size() >= 1) {
            if(abs(lines.back().m-l.m) < EPS) {
                if(lines.back().c < l.c) {
                    lines.pop_back();
                    continue;
                } else {
                    return;
                }
            }
            ld isec = lines.back().intersectX(l);
            if(lines.back().intersectX(l) < lines.back().start+EPS) {
                lines.pop_back();
                continue;
            }
            lines.push_back(l);
            lines.back().start = isec;
            break;
        }
        if(lines.size() == 0) {
            lines.push_back(l);
            lines.back().start = -INF;
        }
    }
    size_t size() const {
        return lines.size();
    }
};

int n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    vector<line> lines;
    for(int i=0;i<n;++i) {
        ll xx, yy;
        cin >> xx >> yy;
        ld x = xx, y = yy;
        lines.push_back(line(2*x, -x*x+y));
    }
    sort(lines.begin(), lines.end());
    hull h;
    for(auto& x : lines) {
        h.insert(x);
    }
    //cerr;for(auto& x : h.lines) {
        //cerr << " line " << x.m << "," << x.c << " starts at " << x.start << endl;
    //cerr;}
    cout << h.size()-1 << endl;
    return 0;
}