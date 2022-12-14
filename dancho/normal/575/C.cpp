#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int INF = 1000000000;

long long hung(const vector< vector<int> > &A) {
    // Convert A -> a
    int n = A.size();
    int m = A[0].size();
    vector<vector<long long> > a(n + 1);
    a[0] = vector<long long>(m + 1);
    for (int i = 0; i < n; ++i) {
        a[i + 1].push_back(INF);
        for (int j = 0; j < m; ++j) {
            a[i + 1].push_back(A[i][j]);
        }
    }
    vector<long long> u(n+1), v(m+1);
    vector<int> p(m+1), way(m+1);
    for (int i=1; i<=n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<long long> minv (m+1, INF);
        vector<char> used (m+1, false);
        do {
            used[j0] = true;
            int i0 = p[j0], j1;
            long long delta = INF;
            for (int j=1; j<=m; ++j)
                if (!used[j]) {
                    long long cur = a[i0][j]-u[i0]-v[j];
                    if (cur < minv[j])
                        minv[j] = cur,  way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j],  j1 = j;
                }
            for (int j=0; j<=m; ++j)
                if (used[j])
                    u[p[j]] += delta,  v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    vector<int> rv(n + 1);
    for (int j = 1; j <= m; ++j) {
        rv[p[j]] = j;
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += a[i][rv[i]];
    }
    return ans;
}

int n;
int co[2][32][32];

int ones = 0;
int zeros = 0;
int fixed[32];

int bsol = 0;

int get_sol() {
    vector< vector<int> > a(n);
    for (int i = 0; i < n; ++i) {
        a[i].resize(n);
        for (int j = 0; j < n; ++j) {
            if (fixed[j] == -1) {
                a[i][j] = -max(co[0][i][j], co[1][i][j]);
            } else {
                a[i][j] = -co[fixed[j]][i][j];
            }
        }
    }
    return -hung(a);
}

void go(int p) {
    if (clock() > 1.7 * CLOCKS_PER_SEC) {
        return;
    }
    if (p >= n) {
        bsol = max(bsol, get_sol());
        return;
    }
    if (ones < n / 2) {
        fixed[p] = 1;
        ++ones;
        if (get_sol() > bsol) {
            go(p + 1);
        }
        --ones;
        fixed[p] = -1;
    }
    if (zeros < n / 2) {
        fixed[p] = 0;
        zeros++;
        if (get_sol() > bsol) {
            go(p + 1);
        }
        fixed[p] = -1;
        --zeros;
    }
}

int main() {
    scanf("%d", &n);
    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &co[k][i][j]);
            }
        }
    }

    srand(42);
    memset(fixed, 0, sizeof(fixed));
    for (int i = 0; i < n / 2; ++i) {
        fixed[i] = 1;
    }

    for (int i = 0; i < 1000; ++i) {
        random_shuffle(fixed, fixed + n);
        bsol = max(bsol, get_sol());
    }

    memset(fixed, -1, sizeof(fixed));
    go(0);
    printf("%d\n", bsol);
    return 0;
}