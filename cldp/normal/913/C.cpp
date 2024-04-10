#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

long long x[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    long long L;
    cin >> N >> L;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        if (i > 0 && x[i] > x[i - 1] * 2) x[i] = x[i - 1] * 2;
    }
    for (int i = N; i <= 30; ++i) x[i] = x[i - 1] * 2;
    long long ans = -1;
    while (L <= (1 << 30)) {
        long long temp = 0;
        for (int i = 0; i <= 30; ++i) {
            if (L & (1 << i)) temp += x[i];
        }
        if (ans == -1 || temp < ans) ans = temp;
        L += (L & (-L));
    }
    cout << ans << endl;
    return 0;
}