#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int MAXB = 18;
const int INF = 1000000007;
const double PI = acos(-1.0);

struct matrix {
    int N;
    int x[MAXB][MAXB];

    matrix() {}

    void clear(int _N) {
        N = _N;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) x[i][j] = 0;
        }
    }

    matrix(int _N) {
        N = _N + 1;
        memset(x, 0, sizeof(x));
        for (int i = 0; i <= N; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i + j < 0 || i + j > N) continue;
                x[i][i + j] = 1;
            }
        }
    }
};

void mul(matrix &A, const matrix &B, const matrix &C) {
    A.clear(B.N);

    for (int k = 0; k < A.N; ++k) {
        for (int i = 0; i < A.N; ++i) {
            for (int j = 0; j < A.N; ++j) {
                A.x[i][j] = (A.x[i][j] + 1LL * B.x[i][k] * C.x[k][j]) % INF;
            }
        }
    }
}

void powm(matrix &D, const matrix &A, long long K) {
    if (K == 0) {
        D.clear(A.N);
        for (int i = 0; i < A.N; ++i) D.x[i][i] = 1;
        return ;
    }
    if (K == 1) {
        D = A;
        return ;
    }
    matrix B, C;
    mul(B, A, A);
    powm(C, B, K / 2);
    D = C;
    if (K % 2 == 0) return ;
    mul(D, C, A);
}

long long A[MAXN], B[MAXN];
int C[MAXN];

void print(matrix& A) {
    for (int a = 0; a < A.N; ++a) {
        for (int b = 0; b < A.N; ++b) {
            cout << A.x[a][b] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    long long K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> A[i] >> B[i] >> C[i];
    B[N - 1] = K;

    int ans[MAXB];
    memset(ans, 0, sizeof(ans));
    ans[0] = 1;

    for (int i = 0; i < N; ++i) {
        matrix B1(C[i]);
        matrix B2;
        powm(B2, B1, B[i] - A[i]);
        int temp[MAXB];
        memset(temp, 0, sizeof(temp));
        for (int a = 0; a <= C[i]; ++a) {
            for (int b = 0; b <= C[i]; ++b) {
                temp[a] = (temp[a] + 1LL * B2.x[a][b] * ans[b]) % INF;
            }
        }
        memset(ans, 0, sizeof(ans));
        for (int j = 0; j <= C[i]; ++j) ans[j] = temp[j];
    }

    cout << ans[0] << endl;

    return 0;
}