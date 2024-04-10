/**
 *  created: 25/12/2020, 14:23:16
**/

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

const int max_n = 200222, inf = 1000111222;

struct dsu {
    int p_or_sz[max_n];

    void init(int n) {
        for (int i = 0; i < n; ++i) {
            p_or_sz[i] = -1;
        }
    }

    int find_set(int v) {
        if (p_or_sz[v] < 0) {
            return v;
        }
        return p_or_sz[v] = find_set(p_or_sz[v]);
    }

    bool union_set(int v1, int v2) {
        v1 = find_set(v1);
        v2 = find_set(v2);
        if (v1 == v2) {
            return false;
        }
        if (-p_or_sz[v1] > -p_or_sz[v2]) {
            swap(v1, v2);
        }
        p_or_sz[v2] += p_or_sz[v1];
        p_or_sz[v1] = v2;
        return true;
    }
};

struct edge {
    int u, v, c;

    bool operator < (const edge &e) {
        return c < e.c;
    }
};

int t, n, m, k;
dsu d;
edge e[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &m, &k);
        int ans = inf;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].c);
            --e[i].u;
            --e[i].v;
            ans = min(ans, abs(e[i].c - k));
            e[i].c = max(0, e[i].c - k);
        }
        sort(e, e + m);
        d.init(n);
        long long res = 0;
        for (int i = 0; i < m; ++i) {
            if (d.union_set(e[i].u, e[i].v)) {
                res += e[i].c;
            }
        }
        if (res == 0) {
            res = ans;
        }
        cout << res << "\n";
    }
    return 0;
}