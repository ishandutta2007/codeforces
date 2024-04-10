#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200010;

int x[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        ans += min(a, b);
        int c = min(a + a, b);
        x[i] = c - min(a, b);
    }
    sort(x, x + N);
    for (int i = N - 1; i >= N - K; --i) ans += x[i];
    cout << ans << endl;
    return 0;
}