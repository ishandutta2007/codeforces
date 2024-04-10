#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#ifdef Doludu
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 200001, logN = 20, K = 450;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <vector <int>> v(n);
        vector <vector <int>> adj(n);
        vector <int> in(n, 0);
        for (int i = 0, sz; i < n; ++i) {
            cin >> sz;
            v[i].resize(sz);
            for (int &j : v[i])
                cin >> j, --j, adj[j].push_back(i), in[i]++;
            sort(v[i].begin(), v[i].end());
        }
        set <int> s;
        for (int i = 0; i < n; ++i) if (in[i] == 0)
            s.insert(i);
        int ans = 0, cnt = 0, now = -1;
        while (!s.empty()) {
            if (*--s.end() < now) {
                now = -1;
                ans++;
            }
            int v = *s.lower_bound(now); s.erase(v);
            cnt++;
            now = v;
            for (int u : adj[v]) {
                in[u]--;
                if (in[u] == 0) s.insert(u);
            }
        }
        if (cnt != n) {
            cout << -1 << endl;
        } else {
            cout << ans + 1 << endl;
        }
    }
}