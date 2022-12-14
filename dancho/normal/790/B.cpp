#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n, k;

struct Sum {
    long long sum[8];
    int cnt[8];

    Sum() {
        for (int i = 0; i < k; ++i) {
            sum[i] = 0;
            cnt[i] = 0;
        }
    }

    Sum plus(const Sum &o) const {
        Sum r;
        for (int i = 0; i < k; ++i) {
            r.sum[i] = sum[i] + o.sum[i];
            r.cnt[i] = cnt[i] + o.cnt[i];
        }
        return r;
    }

    Sum plusOne() const {
        Sum r;
        for (int i = 0; i < k; ++i) {
            r.sum[i] = sum[(i - 1 + k) % k] + cnt[(i - 1 + k) % k];
            r.cnt[i] = cnt[(i - 1 + k) % k];
        }
        return r;
    }
};

bool us[200020];
vector<int> g[200020];
long long res = 0;
Sum c[200020];

void dfs(int v, Sum sofar) {
    if (us[v]) {
        return;
    }
    us[v] = 1;

    Sum cur;

    Sum above = sofar.plusOne();

    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (us[u] == 0) {
            dfs(u, above.plus(cur));
            cur = cur.plus(c[u].plusOne());
        }
    }

    cur.cnt[0] += 1;
    c[v] = cur;
    
    Sum ad = above.plus(cur);
    for (int i = 0; i < k; ++i) {
        res += (ad.sum[i] - ad.cnt[i] * i) / k;
        if (i > 0) {
            res += ad.cnt[i];
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(us, 0, sizeof(us));
    dfs(1, Sum());

    printf("%I64d\n", res);
    return 0;
}