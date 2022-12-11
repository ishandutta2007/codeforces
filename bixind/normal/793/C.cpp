#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> point;

void solve() {
    int n;
    point p1, p2;
    cin >> n;
    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    double e0 = 0, l0 = 1e9;
    for (int i = 0; i < n; ++i) {
        point r, v;
        cin >> r.first >> r.second;
        cin >> v.first >> v.second;
        if (r.first >=  p2.first && v.first >= 0) {
            cout << -1 << endl;
            return;
        }if (r.first <=  p1.first && v.first <= 0) {
            cout << -1 << endl;
            return;
        }
        if (r.second >= p2.second && v.second >= 0) {
            cout << -1 << endl;
            return;
        }
        if (r.second <= p1.second && v.second <= 0) {
            cout << -1 << endl;
            return;
        }
        double e1, e2, l1, l2;
        e1 = (p1.first - r.first) / (double) v.first;
        l1 = (p2.first - r.first) / (double) v.first;
        if (l1 < e1)
            swap(e1, l1);
        if (e1 < 0)
            e1 = 0;
        e2 = (p1.second - r.second) / (double) v.second;
        l2 = (p2.second - r.second) / (double) v.second;
        if (l2 < e2)
            swap(e2, l2);
        if (e2 < 0)
            e2 = 0;
        e0 = max(e0, max(e1, e2));
        l0 = min(l0, min(l1, l2));
    }
    if (l0 <= e0)
        cout << -1 << endl;
    else
        cout << e0 << endl;
}

int main() {
    iostream::sync_with_stdio(false);
    cout.precision(20);
    solve();
}