#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

const int MAX_LOG = 60;
const int INF = 1e9;

inline int GetBit(long long mask, int num) {
    return (mask >> num) & 1;
}

int n;
long long k;

vector<vector<long long>> sum;
vector<vector<int>> mn;
vector<vector<int>> nxt;

vector<int> g;
vector<int> gw;

int main() {
    scanf("%d" LLD_SPEC, &n, &k);

    g.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &g[i]);
    }
    gw.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &gw[i]);
    }

    sum.assign(n, vector<long long>(MAX_LOG, 0));
    mn.assign(n, vector<int>(MAX_LOG, INF));
    nxt.resize(n, vector<int>(MAX_LOG));

    for (int i = 0; i < n; ++i) {
        nxt[i][0] = g[i];
        sum[i][0] = gw[i];
        mn[i][0] = gw[i];
    }

    for (int j = 1; j < MAX_LOG; ++j) {
        for (int i = 0; i < n; ++i) {
            int mid = nxt[i][j - 1];
            nxt[i][j] = nxt[mid][j - 1];
            sum[i][j] = sum[i][j - 1] + sum[mid][j - 1];
            mn[i][j] = min(mn[i][j - 1], mn[mid][j - 1]);
        }
    }

    for (int i = 0; i < n; ++i) {
        long long s = 0;
        int m = INF;
        int v = i;
        long long ck = k;
        for (int i = MAX_LOG - 1; i >= 0; --i) {
            if (ck >= (1LL << i)) {
                s += sum[v][i];
                m = min(m, mn[v][i]);
                v = nxt[v][i];
                ck -= (1LL << i);
            }
        }
        printf(LLD_SPEC " %d\n", s, m);
    }

    return 0;
}