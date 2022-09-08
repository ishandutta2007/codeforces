#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 10111, inf = 1000111222;
const int max_m = 100111;

int n, m, p[max_n];
int from[max_m], to[max_m], c[max_m];
vector<int> g[max_n], allc;

bool used[max_n], ok[max_n];

bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = 1;
    for (int to : g[v]) {
        if (p[to] == -1) {
            p[to] = v;
            return true;
        }
    }
    for (int to : g[v]) {
        if (dfs(p[to])) {
            p[to] = v;
            return true;
        }
    }
    return false;
}

bool check(int x) {
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
    for (int i = 0; i < m; ++i) {
        if (c[i] <= x) {
            g[from[i]].push_back(to[i]);
        }
    }
    memset(ok, 0, sizeof(ok));
    memset(p, -1, sizeof(p));
    for (int run = 1; run; ) {
        run = 0;
        memset(used, 0, sizeof(used));
        for (int i = 0; i < n; ++i) {
            if (!ok[i]) {
                ok[i] = dfs(i);
                run |= ok[i];
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += ok[i];
    }
    return cnt == n;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &from[i], &to[i], &c[i]);
        --from[i];
        --to[i];
        allc.push_back(c[i]);
    }
    sort(allc.begin(), allc.end());
    allc.erase(unique(allc.begin(), allc.end()), allc.end());
    int l = -1, r = allc.size();
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(allc[mid])) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r == allc.size()) {
        puts("-1");
    } else {
        printf("%d\n", allc[r]);
    }
    return 0;
}