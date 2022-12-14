#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

long long qpow(long long v, long long st, long long mod) {
    long long r = 1;
    while (st) {
        if (st & 1) {
            r *= v;
            if (r >= mod) {
                r %= mod;
            }
        }
        v = v * v;
        if (v >= mod) {
            v %= mod;
        }
        st /= 2;
    }
    return r;
}

int n, m, p;
vector<int> g[620];
int din[620];
int dou[620];
vector<int> so, si;

long long cnt[620][620];
vector< vector<long long> > a;

long long det(vector < vector<long long> > a) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;
 
    vector<int> where (m, -1);
    long long r = 1;
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (a[i][col] > 0)
                sel = i;
        if (sel != row) {
            r = p - r;
        }
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;
 
        for (int i=0; i<n; ++i)
            if (i != row) {
                long long c = a[i][col] * qpow(a[row][col], p - 2, p);
                if (c >= p) {
                    c %= p;
                }
                for (int j=col; j<=m; ++j) {
                    long long k = a[row][j] * c;
                    if (k >= p) {
                        k %= p;
                    }
                    a[i][j] = a[i][j] + p - k;
                    while (a[i][j] >= p) {
                        a[i][j] -= p;
                    }
                }
            }
        ++row;
    }
 
    for (int i = 0; i < n; ++i) {
        r = r * a[i][i];
        if (r >= p) {
            r %= p;
        }
    }
    return r;
}

void go(int v) {
    if (cnt[v][0] != -1) {
        return;
    }
    memset(cnt[v], 0, sizeof(cnt[v]));
    cnt[v][v] = 1;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        go(u);
        for (int j = 0; j <= n; ++j) {
            cnt[v][j] += cnt[u][j];
            if (cnt[v][j] >= p) {
                cnt[v][j] %= p;
            }
        }
    }
}

int main() {
    memset(din, 0, sizeof(din));
    memset(dou, 0, sizeof(dou));
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        ++din[b];
        ++dou[a];
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i) {
        if (din[i] == 0) {
            so.push_back(i);
        }
        if (dou[i] == 0) {
            si.push_back(i);
        }
    }

    memset(cnt, -1, sizeof(cnt));
    a.assign(so.size(), vector<long long>(so.size()));
    for (int i = 0; i < (int) so.size(); ++i) {
        go(so[i]);
        for (int j = 0; j < (int) si.size(); ++j) {
            a[i][j] = cnt[so[i]][si[j]];
            // printf("OP %d %d :: %lld\n", so[i], si[i], a[i][j]);
        }
    }
    printf("%lld\n", det(a));

    return 0;
}