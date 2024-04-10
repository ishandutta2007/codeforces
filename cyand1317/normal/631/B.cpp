#include <cstdio>
#include <set>
static const int MAXN = 5005;
static const int MAXK = 1e5 + 4;

int n, m, k;
int c[MAXN][MAXN] = {{ 0 }};
int op[MAXK], arg1[MAXK], arg2[MAXK];
std::set<int> rows, cols;

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) scanf("%d%d%d", &op[i], &arg1[i], &arg2[i]), --arg1[i];

    for (int i = 0; i < n; ++i) rows.insert(i);
    for (int j = 0; j < m; ++j) cols.insert(j);
    std::set<int>::iterator itr;
    for (int i = k - 1; i >= 0; --i) {
        if (op[i] == 1) {   // Row
            if ((itr = rows.find(arg1[i])) == rows.end()) continue;
            for (int p : cols) c[arg1[i]][p] = arg2[i];
            rows.erase(itr);
        } else {            // Column
            if ((itr = cols.find(arg1[i])) == cols.end()) continue;
            for (int p : rows) c[p][arg1[i]] = arg2[i];
            cols.erase(itr);
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) printf("%d%c", c[i][j], j == m - 1 ? '\n' : ' ');
    return 0;
}