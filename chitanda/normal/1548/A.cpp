#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 1000000007;

int n, m, q;
int out[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        static int u, v;
        cin >> u >> v;
        if (u > v) swap(v, u);
        ++out[u];
        if (out[u] == 1) ++cnt;
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        static int op, u, v;
        cin >> op;

        if (op == 3)
            cout << n - cnt << "\n";
        else {
            cin >> u >> v;
            if (u > v) swap(v, u);
            if (op == 1) {
                ++out[u];
                if (out[u] == 1) ++cnt;
            } else {
                --out[u];
                if (out[u] == 0) --cnt;
            }
        }
    }
    return 0;
}