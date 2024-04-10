#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 76;
const int INF = 1000000007;

int N, V, K, X;
string P;
int f[MAXN][MAXN][MAXN][2];

void count(int &a, int &b, int &c, int n, char t) {
    a = b = c = 0;
    for (int i = 0; i < N; ++i) {
        switch (P[i]) {
            case 'V' : ++a; if (t == 'V' && a == n) return; break;
            case 'K' : ++b; if (t == 'K' && b == n) return; break;
            default  : ++c; if (t == 'X' && c == n) return; break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    V = K = X = 0;
    cin >> N >> P;
    for (int i = 0; i < N; ++i) {
        if (P[i] != 'V' && P[i] != 'K') P[i] = 'X';
    }
    for (int i = 0; i < N; ++i) {
        switch (P[i]) {
            case 'V' : ++V; break;
            case 'K' : ++K; break;
            default  : ++X; break;
        }
    }
    for (int v = 0; v <= V; ++v) {
        for (int k = 0; k <= K; ++k) {
            for (int x = 0; x <= X; ++x) {
                f[v][k][x][0] = f[v][k][x][1] = INF;
            }
        }
    }
    f[0][0][0][0] = f[0][0][0][1] = 0;
    for (int v = 0; v <= V; ++v) {
        for (int k = 0; k <= K; ++k) {
            for (int x = 0; x <= X; ++x) {
                int a, b, c;
                if (v < V) {
                    count(a, b, c, v + 1, 'V');
                    f[v + 1][k][x][1] = min(f[v + 1][k][x][1], 
                                            min(f[v][k][x][0], f[v][k][x][1]) + max(0, b - k) + max(0, c - x));
                }
                if (x < X) {
                    count(a, b, c, x + 1, 'X');
                    f[v][k][x + 1][0] = min(f[v][k][x + 1][0],
                                            min(f[v][k][x][0], f[v][k][x][1]) + max(0, a - v) + max(0, b - k));
                }
                if (k < K) {
                    count(a, b, c, k + 1, 'K');
                    f[v][k + 1][x][0] = min(f[v][k + 1][x][0], f[v][k][x][0] + max(0, a - v) + max(0, c - x));
                }
            }
        }
    }
    cout << min(f[V][K][X][0], f[V][K][X][1]) << endl;
    return 0;
}