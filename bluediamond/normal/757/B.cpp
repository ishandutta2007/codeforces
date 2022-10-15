#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;
int n;
int f[N];
int cnt[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    /// 4 -> 1 2 4

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        f[x]++;
    }

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            cnt[i] += f[j];
        }
    }

    int ans = 1;
    for (int i = 2; i < N; i++) {
        ans = max(ans, cnt[i]);
    }
    cout << ans << "\n";

    return 0;
}