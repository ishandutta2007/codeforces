#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);


int main() {
    ios_base::sync_with_stdio(false);
    long long x, y, l, r;
    double xx, yy;
    long long xz, yz;
    cin >> x >> y >> l >> r;

    vector<long long> X;
    xx = xz = 1;
    for (int i = 0; i <= 60; ++i) {
        yy = yz = 1;
        for (int j = 0; j <= 60; ++j) {
            if (xx + yy > r + 1) break;
            long long temp = xz + yz;
            if (l <= temp && temp <= r) X.push_back(temp);
            yy = yy * y;
            if (yy > r + 1) break;
            yz = yz * y;
        }
        xx = xx * x;
        if (xx > r + 1) break;
        xz = xz * x;
    }
    X.push_back(l - 1);
    X.push_back(r + 1);
    sort(X.begin(), X.end());
    long long ans = 0;
    for (int i = 0; i + 1 < X.size(); ++i) ans = max(X[i + 1] - X[i] - 1, ans);
    cout << ans << endl;
    return 0;
}