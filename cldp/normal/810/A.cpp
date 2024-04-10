#include <iostream>
using namespace std;

const int MAXN = 200010;

int x[MAXN], s[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        sum += a;
    }
    int ans = 0;
    while (sum * 2 < (K + K - 1) * (ans + N)) {
        sum += K;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}