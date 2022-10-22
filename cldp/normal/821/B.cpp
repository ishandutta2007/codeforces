#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

long long cal(long long x, long long y) {
    return (y + 1) * (x + 1) * x / 2 + (x + 1) * (y + 1) * y / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    long long m, b;
    cin >> m >> b;
    long long ans = 0;
    for (int y = 0; y <= b; ++y) {
        long long x = (b - y) * m;
        ans = max(ans, cal(x, y));
    }
    cout << ans << endl;
    return 0;
}