#include <bits/stdc++.h>
using namespace std;

const int N = 11000;
const int P = 1e9 + 7;

map<int, int> A[N];
int a[N][10];

int modExp(int a, int n, int p) {
    int ret = 1;
    for (; n; n >>= 1, a = 1LL * a * a % p) if (n & 1) ret = 1LL * ret * a % p;
    return ret;
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            A[i][j] = (i == j ? m - 1 : P - 1);
        }
    }
    for (int i = m+1; i <= n; i++) {
        A[i][i] = m;
        for (int j = 1; j <= m; j++) {
            int x; cin >> x; a[i][j] = x;
            A[i][x] = A[x][i] = P - 1;
            A[x][x]++;
        }
    }
    int ret = 1;
    for (int i = n; i > 1; i--) {
        ret = 1LL * ret * A[i][i] % P;
        if (!ret) return puts("0"), 0;
        int R = modExp(A[i][i], P - 2, P);
        if (i > m) {
            for (int j = 1; j <= m; j++) {
                int x = a[i][j];
                int z = (P - A[x][i]) * 1LL * R % P;
                for (int k = 1; k <= m; k++) {
                    int y = a[i][k];
                    A[x][y] = (A[x][y] + A[i][y] * 1LL * z) % P;
               }
                A[x][i] = 0;
            }
        } else {
            for (int j = 1; j < i; j++) {
                int z = (P - A[j][i]) * 1LL * R % P;
                for (int k = 1; k <= i; k++) {
                    A[j][k] = (A[j][k] + A[i][k] * 1LL * z) % P;
                }
            }
        }
    }
    cout << ret << endl;
    return 0;
}