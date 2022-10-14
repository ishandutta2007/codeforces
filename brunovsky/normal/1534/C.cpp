#include <bits/stdc++.h>
using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    constexpr int MOD = 1'000'000'007;
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N), b(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> b[i];
        }
        vector<int> Ai(N + 1), Bi(N + 1);
        for (int i = 0; i < N; i++) {
            Ai[a[i]] = i;
            Bi[b[i]] = i;
        }
        vector<bool> vis(N + 1);
        int ans = 1;
        for (int i = 0; i < N; i++) {
            assert(vis[a[i]] == vis[b[i]]);
            if (vis[a[i]])
                continue;

            vector<int> path = {a[i], b[i]};
            do {
                int j = Ai[path.back()];
                path.push_back(b[j]);
            } while (path.back() != a[i]);

            for (int n : path)
                vis[n] = true;

            ans = ans * 2 % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}