#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> point;

ll vp(point a, point b) {
    return a.first * b.second - b.first * a.second;
}

ll sc(point a, point b) {
    return a.first * b.first + a.second * b.second;
}

point operator-(point a, point b) {
    return point(a.first - b.first, a.second - b.second);
}

void solve() {
    int n;
    cin >> n;
    vector<point> v(n);
    double d;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    d = sqrt(sc(v[0] - v[1], v[0] - v[1]));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            d = min(d, sqrt(sc(v[i] - v[j], v[i] - v[j])));
        }
    }
//    cout <<d << endl;
    v.push_back(v[0]);
    v.push_back(v[1]);
    for (int i = 0; i < n; ++i) {
        point a = v[i + 1] - v[i];
        point b = v[i + 2] - v[i];
        double ar = ((double) abs(vp(a, b)));
        ar /= sqrt(sc(b, b));
        d = min(d, ar / 2);
    }
    cout << d << endl;
}

int main() {
    iostream::sync_with_stdio(false);
    cout.precision(20);
    solve();
}