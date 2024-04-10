#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 101000;
const int MAXD = 1000010;
const long long INF = 1LL * 100000000 * 100000000;
const double PI = acos(-1.0);

struct node {
    long long d, f, t, c;
    bool operator < (const node &B) const {
        return d < B.d;
    }
};

node x[MAXN];
long long s[MAXN];
long long f[MAXD], g[MAXD];


int main() {
    ios_base::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; ++i) cin >> x[i].d >> x[i].f >> x[i].t >> x[i].c;
    sort(x, x + M);
    
    for (int i = 1; i <= N; ++i) s[i] = INF;
    for (int i = 0; i < MAXD; ++i) f[i] = g[i] = INF;

    int cnt = 0;
    long long total = 0;
    for (int i = 0; i < M; ++i) {
        int a = x[i].f, b = x[i].t;
        if (b == 0) {
            if (s[a] == INF) {
                ++cnt;
                s[a] = x[i].c;
                total += s[a];
            } else 
            if (s[a] > x[i].c) {
                total -= s[a];
                s[a] = x[i].c;
                total += s[a];
            }
            if (cnt == N) f[x[i].d] = total;
         //  cout << i << " " << x[i].d << " " << cnt << " " << total << endl;
        }
    }
    for (int i = 1; i < MAXD; ++i) f[i] = min(f[i - 1], f[i]);

    for (int i = 1; i <= N; ++i) s[i] = INF;

    cnt = 0, total = 0;
    for (int i = M - 1; i >= 0; --i) {
        int a = x[i].f, b = x[i].t;
        if (a == 0) {
            if (s[b] == INF) {
                ++cnt;
                s[b] = x[i].c;
                total += s[b];
            } else 
            if (s[b] > x[i].c) {
                total -= s[b];
                s[b] = x[i].c;
                total += s[b];
            }
            if (cnt == N) g[x[i].d] = total;
         //   cout << i << " " << x[i].d << " " << cnt << " " << total << endl;
        }
    }
    for (int i = MAXD - 2; i >= 0; --i) g[i] = min(g[i + 1], g[i]);

    long long ans = INF;
    for (int i = 0; i + K + 1 < MAXD; ++i) ans = min(ans, f[i] + g[i + K + 1]);
    if (ans == INF) ans = -1;
    cout << ans << endl;


    return 0;
}