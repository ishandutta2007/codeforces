#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const long double EPS = 1e-6;
const int INF = 1000000000;

int gauss(vector < vector<long double> > a, vector<long double> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;
 
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;
 
        for (int i=0; i<n; ++i)
            if (i != row) {
                long double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }
 
    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        long double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }
 
    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

int n, m;
int deg[1 << 20];

int main() {
    scanf("%d %d", &n, &m);
    memset(deg, 0, sizeof(deg));
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a; --b;
        ++deg[a];
        ++deg[b];
    }

    vector< vector<long double> > a(4);
    vector<long double> ans;
    a[0] = vector<long double>(5);
    a[0][0] = a[0][1] = a[0][2] = a[0][3] = 1;
    a[0][4] = (long double) n * (n - 1) * (n - 2) / 6;

    a[1] = vector<long double>(5);
    a[1][0] = 0;
    a[1][1] = 1;
    a[1][2] = 2;
    a[1][3] = 3;
    a[1][4] = (long double) m * (n - 2);

    a[2] = vector<long double>(5);
    a[2][0] = 3;
    a[2][1] = 2;
    a[2][2] = 1;
    a[2][3] = 0;
    a[2][4] = (long double) (n - 2) * ((long double) n * (n - 1) / 2 - m);

    long double sm = 0;
    for (int i = 0; i < n; ++i) {
        sm += (long double) deg[i] * (deg[i] - 1) / 2;
    }

    a[3] = vector<long double>(5);
    a[3][0] = a[3][1] = 0;
    a[3][2] = 1;
    a[3][3] = 3;
    a[3][4] = sm;

//    for (int i = 0; i < 4; ++i) {
//        for (int j = 0; j < 5; ++j) {
//            printf("%.0lf ", a[i][j]);
//        }
//        printf("\n");
//    }

    int k = gauss(a, ans);
//     printf("#SL %d\n", k);
//     for (int i = 0; i < (int) ans.size(); ++i) {
//         printf("%lf ", ans[i]);
//     }
//     printf("\n");
    if (k != 1) {
        // meh
    }
    long long tot = (long long) n * (long long) (n - 1) * (long long) (n - 2) / 6;
    long long sl = (long long) (ans[1] + ans[2] + ans[3] + 1e-6);
    sl = tot - sl;

    printf("%lld\n", sl);
    return 0;
}