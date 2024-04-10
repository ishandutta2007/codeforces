#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int qpow(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a % INF;
    int ans = qpow(1LL * a * a % INF, b / 2);
    if (b % 2 == 0) return ans;
    return 1LL * a * ans % INF;
}

int main() {
    ios_base::sync_with_stdio(false);
    int x, y;
    cin >> x >> y;
    if (y % x != 0) {
        cout << 0 << endl;
        return 0;
    }
    y /= x;
    int temp = y;
    vector<int> X;
    for (int i = 2; i * i <= y; ++i) {
        if (temp % i == 0) {
            X.push_back(i);
            while (temp % i == 0) temp /= i;
        }
    }
    if (temp > 1) X.push_back(temp);
    int K = X.size();
    int ans = qpow(2, y - 1);
    for (int i = 1; i < (1 << K); ++i) {
        temp = y;
        for (int j = 0; j < K; ++j) {
            if (i & (1 << j)) temp /= X[j];
        }
        int add = qpow(2, temp - 1);
        int t = __builtin_popcount(i);
        if (t % 2 == 0) {
            ans = (ans + add) % INF;
        } else {
            ans = (ans - add + INF) % INF;
        }
    }
    cout << ans << endl;
    return 0;
}