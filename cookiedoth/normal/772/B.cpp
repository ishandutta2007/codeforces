#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

using pii = pair<int, int>;

pii operator-(const pii& left, const pii& right) {
    return pii(left.first - right.first, left.second - right.second);
}

long long vmul(pii l, pii r) {
    return 1LL * l.first * r.second - 1LL * l.second * r.first;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<pii> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    double res = 1e9;
    for (int i = 0; i < n; ++i) {
        pii v1 = v[i];
        pii v2 = v[(i + 1) % n];
        pii v3 = v[(i + 2) % n];
        pii v13 = v3 - v1;
        long long vm = vmul(v13, v2 - v1);
        double h = vm / hypot(v13.first, v13.second);
        res = min(res, h / 2);
    }
    cout << setprecision(12) << fixed << res << endl;
    return 0;
}