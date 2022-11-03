#include <cstdio>
#include <cstring>

#include <iostream>
#include <fstream>
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

const int max_k = 1e2 + 10;

int n, k;
int sum[max_k][max_k][max_k];
int fre[max_k][max_k];
int xc, yc;

int main() {
    cin >> n >> k;
    xc = yc = (k + 1) / 2;
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= k; ++j) {
            sum[i][j][1] = abs(xc - i) + abs(yc - j);
            for (int t = 2; j + t - 1 <= k; ++t)
                sum[i][j][t] = sum[i][j][t - 1] + abs(xc - i) + abs(yc - (j + t - 1));
        }
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= k; ++j)
            fre[i][j] = 1;
    for (; n; --n) {
        int m;
        cin >> m;
        int xa = -1, ya, aa;
        for (int x = 1; x <= k; ++x) {
            int c = 0; 
            for (int i = 1; i < m; ++i)
                c += fre[x][i];
            for (int y = 0; y + m <= k; ++y) {
                c += fre[x][y + m];
                c -= fre[x][y];
                if (c == m && (xa == -1 || sum[x][y + 1][m] < aa)) {
                    aa = sum[x][y + 1][m];
                    xa = x;
                    ya = y + 1;
                }
            }
        }
        if (xa == -1) {
            cout << -1 << endl;
        } else {
            cout << xa << " " << ya << " " << ya + m - 1 << endl;
            for (int i = ya; i <= ya + m - 1; ++i)
                fre[xa][i] = 0;
        }
    }
    
    return 0;
}