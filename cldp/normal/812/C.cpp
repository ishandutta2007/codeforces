#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000007;
const double PI = acos(-1.0);

long long x[MAXN], y[MAXN];



int main() {
    ios_base::sync_with_stdio(false);
    int N, S;
    cin >> N >> S;
    for (int i = 0; i < N; ++i) cin >> x[i];

    int L = 0, R = N + 1, ans = 0;
    while (L + 1 < R) {
        int mid = (L + R) / 2;
        for (int i = 0; i < N; ++i) y[i] = x[i] + 1LL * mid * (i + 1);
        sort(y, y + N);
        long long sum = 0;
        for (int i = 0; i < mid; ++i) {
            sum += y[i];
            if (sum > S) break;
        }
        if (sum <= S) {
            L = mid;
            ans = sum;
        } else {
            R = mid;
        }
    }

    cout << L << " " << ans << endl;
    return 0;
}