#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000007;
const double PI = acos(-1.0);

struct BIT {
    int cnt[MAXN];

    void add(int x) {
        for (int i = x; i < MAXN; i += (i & (-i))) ++cnt[i];
    }

    int query(int r) {
        int ans = 0;
        for (int i = r; i > 0; i -= (i & (-i))) ans += cnt[i];
        return ans;
    }
};

BIT A, B;

int x[MAXN], y[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> x[i];
        y[i] = A.query(N) - A.query(x[i]);
        A.add(x[i]);
    }

    int ans1 = 0, ans2 = -2;
    for (int i = N; i >= 1; --i) {
        int t = B.query(x[i]);
        if (y[i] == 0) --t;
        if (t > ans2 || (t == ans2 && x[i] < ans1)) {
            ans1 = x[i];
            ans2 = t;
        }
        if (y[i] == 1) B.add(x[i]);
    }
    cout << ans1 << endl;
    return 0;
}