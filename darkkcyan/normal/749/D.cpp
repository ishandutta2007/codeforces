#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define vi ve<int>
#define xx first
#define yy second
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define ii pair<int, int>
#define sz(v) ((int) v.size())

int n;
ve<ve<ii> > a;
vi b, last;
set<int> se;

bool cmpp(int u, int v) { return last[u] < last[v]; }

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    a.resize(n);
    last.resize(n, -1);
    for (int i = 0; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v); --u;
        a[u].push_back(ii(i, v));
        last[u] = i;
    }
    b.resize(n); for (int i = 0; i < n; ++i) b[i] = i;
    sort(b.begin(), b.end(), cmpp);

    int q; scanf("%d", &q);
    while (q--) {
        int k; scanf("%d", &k);
        se.clear();
        for (int i = 0; i < k; ++i) {
            int u; scanf("%d", &u); se.insert(--u);
        }
        int i = n - 1;
        for (;i >= 0 and se.count(b[i]); --i);
        if (i == -1 or last[b[i]] == -1) {
            puts("0 0");
            continue;
        }
        int f = i - 1;
        for (; f >= 0 and se.count(b[f]); --f);
        if (f == -1) {
            printf("%d %d\n", b[i] + 1, a[b[i]][0].yy);
            continue;
        }
        int t = upper_bound(a[b[i]].begin(), a[b[i]].end(), ii(last[b[f]], 0))->yy;
        printf("%d %d\n", b[i] + 1, t);
    }
    return 0;
}