#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);


int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    double ans = 1e100;
    for (int i = 0; i < N; ++i) {
        double a, b;
        cin >> a >> b;
        ans = min(ans, 1.0 * a / b * M);
    }
    cout << fixed << setprecision(8) << ans << endl;
    return 0;
}