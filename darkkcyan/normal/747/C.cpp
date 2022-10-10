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

int n, q;
set<int> a;
vi t, k, d;
ve<set<int> > s;

set<ii> task;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) a.insert(i + 1);
    k.resize(q); t = d = k;
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d", &t[i], &k[i], &d[i]);
        task.insert(ii(t[i], i));
    }

    s.resize(q);
    while (sz(task)) {
//        static int i = 0; ++i; clog << i << endl;
        int u = task.begin()->yy;
        task.erase(task.begin());
        if (u >= 0) {
            if (sz(a) < k[u]) {
                printf("-1\n");
                continue;
            }
            int sum = 0;
            for (int i = 0; i < k[u]; ++i) {
                sum += *a.begin();
                s[u].insert(*a.begin());
                a.erase(a.begin());
            }
            printf("%d\n", sum);
            task.insert(ii(t[u] + d[u], -u - 1));
        } else {
            u = -u - 1;
            a.insert(s[u].begin(), s[u].end());
            s[u].clear();
        }
    }

    return 0;
}