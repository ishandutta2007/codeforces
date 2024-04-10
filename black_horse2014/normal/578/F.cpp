#include <bits/stdc++.h>
using namespace std;

const int N = 440;

char s[N][N];
int f[N * N];

int find_set(int u) {
    return f[u] == u ? u : f[u] = find_set(f[u]);
}

int a[N * N], b[N * N];
int A[N][N], B[N][N];

int main() {
    int n, m, P; cin >> n >> m >> P;
    for (int i = 0; i < (n + 1) * (m + 1); i++) f[i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
            if (s[i][j] == '\\') {
                int u = find_set(i * (m + 1) + j);
                int v = find_set((i + 1) * (m + 1) + j + 1);
                if (u == v) return puts("0"), 0;
                f[u] = v;
            }
            if (s[i][j] == '/') {
                int u = find_set(i * (m + 1) + j + 1);
                int v = find_set((i + 1) * (m + 1) + j);
                if (u == v) return puts("0"), 0;
                f[u] = v;
            }
        }
    }
    int an = 0, bn = 0;
    for (int i = 0; i < (n + 1) * (m + 1); i++) {
        if (f[i] == i) {
            int x = i / (m + 1), y = i % (m + 1);
            if (x + y + 1 & 1) {
                a[i] = an++;
            } else {
                b[i] = bn++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '*') {
                {
                    int u = find_set(i * (m + 1) + j);
                    int v = find_set((i + 1) * (m + 1) + j + 1);
                    if (i + j + 1 & 1) {
                        u = a[u];
                        v = a[v];
                        A[u][v]--, A[u][u]++;
                        A[v][u]--, A[v][v]++;
                    } else {
                        u = b[u];
                        v = b[v];
                        B[u][v]--, B[u][u]++;
                        B[v][u]--, B[v][v]++;
                    }
                }
                {
                    int u = find_set(i * (m + 1) + j + 1);
                    int v = find_set((i + 1) * (m + 1) + j);
                    if (i + j & 1) {
                        u = a[u];
                        v = a[v];
                        A[u][v]--, A[u][u]++;
                        A[v][u]--, A[v][v]++;
                    } else {
                        u = b[u];
                        v = b[v];
                        B[u][v]--, B[u][u]++;
                        B[v][u]--, B[v][v]++;
                    }
                }
            }
        }
    }
    auto modExp = [&](int a, int n, int p) {
        int ret = 1;
        for (; n; n >>= 1, a = 1LL * a * a % p) if (n & 1) ret = 1LL * ret * a % p;
        return ret;
    };
    function<int(int[][N], int)> det = [&](int a[][N], int n) {
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			a[i][j] = (a[i][j] % P + P) % P;
    		}
    	}
        int ret = 1;
        for (int i = 1; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (a[j][i]) {
                    if (j != i) {
                        for (int k = i; k < n; k++) swap(a[i][k], a[j][k]);
                        ret = (P - ret) % P;
                    }
                    break;
                }
            }
            ret = 1LL * ret * a[i][i] % P;
            int R = modExp(a[i][i], P - 2, P);
            for (int j = i + 1; j < n; j++) {
                if (a[j][i]) {
                    int cur = 1LL * a[j][i] * (P - R) % P;
                    for (int k = i; k < n; k++) a[j][k] = (a[j][k] + 1LL * cur * a[i][k]) % P;
                }
            }
        }
        return ret;
    };
    cout << (det(A, an) + det(B, bn)) % P << endl;
    return 0;
}