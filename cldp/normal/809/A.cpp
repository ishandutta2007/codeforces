#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 3000010;
const int INF = 1000000007;
const double PI = acos(-1.0);


long long x[MAXN];
long long p[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> x[i];
    p[0] = 1;
    for (int i = 1; i < N; ++i) {
        p[i] = (p[i - 1] * 2) % INF;
    }
    sort(x, x + N);
    long long ans = 0;
    for (int i = 1; i < N; ++i) {
        ans = (ans + x[i] * (p[i] - 1)) % INF;
    }
    for (int i = 0; i < N - 1; ++i) {
        ans = (ans - x[i] * (p[N - 1 - i] - 1)) % INF;
    }
    ans = (ans % INF + INF) % INF;
    cout << ans << endl;
    return 0;
}