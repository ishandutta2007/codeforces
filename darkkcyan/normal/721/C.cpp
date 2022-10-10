#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define log(msg) clog << __LINE__ << ": " << msg
#else
#define log(msg)
#endif

#define _ << ' ' <<
#define lim numeric_limits
#define long long long
#define ve vector
#define vi ve<int>
#define sz(v) ((int) v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()

int n, m;
long t;
ve<ve<ii > > gr;
void read() {
    cin >> n >> m >> t;
    gr.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        --a, --b;
        gr[a].push_back(ii(t, b));
    }
}

vi tp;
ve<bool> vst;
void tpsort(int v) {
    vst[v] = true;
    for (int i = 0; i < sz(gr[v]); ++i) {
        int u = gr[v][i].yy;
        if (vst[u]) continue;
        tpsort(u);
    }
    tp.push_back(v);
}

ve<vi> dp, tr;
void process() {
    dp.resize(n, vi(n + 1, lim<int>::max()));
    tr.resize(n, vi(n + 1, -1));
    dp[0][1] = 0;
    for (int i = n - 1; i >= 0; --i) {
        int u = tp[i];
        if (u == n - 1) break;
        for (int c = 0; c < n; ++c) {
            if (dp[u][c] >= lim<int>::max()) continue;
            for (int f = 0; f < sz(gr[u]); ++f) {
                int v = gr[u][f].yy;
                long nt = (long) dp[u][c] + (long) gr[u][f].xx;
                if (nt >= dp[v][c + 1]) continue;
                dp[v][c + 1] = nt;
                tr[v][c + 1] = u;
            }
        }
    }
}

int findans() {
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (dp[n - 1][i] <= t) ans = i;
    }
    return ans;
}

void printtrace(int u, int d) {
    if (d == 0) return;
    printtrace(tr[u][d], d - 1);
    printf("%d ", u + 1);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    read();
    vst.resize(n);
    tpsort(0);
    process();
    int ans = findans();
    cout << ans << '\n';
    printtrace(n - 1, ans);

    return 0;
}