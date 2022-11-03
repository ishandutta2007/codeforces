#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_int = (1LL << 31) - 1;

//#define LOCAL

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

const int max_n = 5e2 + 10;

int sv[max_n][max_n];
int sh[max_n][max_n];
int sp[max_n][max_n][3];
int a[max_n][max_n];
int n, m;

int sumh(int i, int j, int len) {
    int result = sh[i][j + len - 1];
    if (j)
        result -= sh[i][j - 1];
    return result;
}

int sumv(int i, int j, int len) {
    int result = sv[j][i + len - 1];
    if (i)
        result -= sv[j][i - 1];
    return result;
}

int main() { 
    ios_base::sync_with_stdio(false);  
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; ++i) {
        sh[i][0] = a[i][0];
        for (int j = 1; j < m; ++j)
            sh[i][j] = sh[i][j - 1] + a[i][j];
    }
    for (int j = 0; j < m; ++j) {
        sv[j][0] = a[0][j];
        for (int i = 1; i < n; ++i)
            sv[j][i] = sv[j][i - 1] + a[i][j];
    }
    int ans = -max_int;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            sp[i][j][1] = a[i][j];
            if (3 + i <= n && 3 + j <= m) {
                sp[i][j][2] = sumh(i, j, 3);
                sp[i][j][2] += sumv(i + 1, j + 2, 2);
                sp[i][j][2] += sumh(i + 2, j, 2);
                ans = max(ans, sp[i][j][2]);
            }
        }
    for (int k = 2; 2 * k + 1 <= n && 2 * k + 1 <= m; ++k) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                sp[i][j][0] = sp[i][j][1];
                sp[i][j][1] = sp[i][j][2];
            }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (2 * k + 1 + i <= n && 2 * k + 1 + j <= m) {
                    sp[i][j][2] = sumh(i, j, 2 * k + 1);
                    sp[i][j][2] += sumv(i + 1, j + 2 * k, 2 * k);
                    sp[i][j][2] += sumh(i + 2 * k, j, 2 * k);
                    sp[i][j][2] += sumv(i + 2, j, 2 * (k - 1));
                    sp[i][j][2] += a[i + 2][j + 1];
                    sp[i][j][2] += sp[i + 2][j + 2][0]; 
                    ans = max(ans, sp[i][j][2]);
                }
    }
    cout << ans << endl;
    return 0;
}