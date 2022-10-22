#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        for (int i = 0; i < K; ++i) cin >> x[i];
        sort(x, x + K);
        int ans = max(x[0] - 1, N - x[K - 1]);
        for (int i = 0; i + 1 < K; ++i) {
            ans = max(ans, (x[i + 1] - x[i]) / 2);
        }
        cout << ans + 1 << endl;
    }
    return 0;
}