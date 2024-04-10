#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max() - 10)
#define vi ve<int>
#define ii pair<int, int>

#define NN 10101
ve<int> dst;
queue<int> qu;

int bfs(int n, int m) {
    dst.assign(NN, -1);
    dst[n] = 0;
    for (qu.push(n); qu.size(); qu.pop()) {
        int u = qu.front();
        if (u == m) return dst[u];
        int x = u * 2, y = u - 1;
        if (x < NN and dst[x] == -1) {
            dst[x] = dst[u] + 1;
            qu.push(x);
        }
        if (y > 0 and dst[y] == -1) {
            dst[y] = dst[u] + 1;
            qu.push(y);
        }
    }
    return -1;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    int n, m;
    cin >> n >> m;
    cout << bfs(n, m);


    return 0;
}