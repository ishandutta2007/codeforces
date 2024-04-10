#include<bits/stdc++.h>

using namespace std;

const int N = 102;

int K[N][N][N*N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    memset(K, -1, sizeof K);
    int A[n];
    int B[n];
    int a = 0;
    int b = 0;
    for (int i = 0; i < n; ++i) { 
        cin >> A[i];
        a += A[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
        b += B[i];
    }
    K[0][0][0] = 0;
    int kk = 0;
    int kk2 = b;
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            for (int j = 0; j <= b; ++j) {
                if (K[k][i][j] == -1) continue;
                int t = j + B[i];
                int p = K[k][i][j] + A[i];
                if (K[k + 1][i + 1][t] == -1 or K[k + 1][i + 1][t] > p) K[k + 1][i + 1][t] = p;
                if (K[k][i + 1][j] == -1 or K[k][i + 1][j] > K[k][i][j]) K[k][i + 1][j] = K[k][i][j];
            }
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int k = 0; k <= n; ++k) {
            for (int j = 0; j <= b - a; ++j) {
                if (K[k][i][j] == -1) continue;
                if (k > kk) {
                    kk = k;
                    kk2 = K[k][i][j];
                }
                else if (k == kk) kk2 = min(kk2, K[k][i][j]);
            }
        }
    }
    cout << n - kk << ' ' << kk2 << '\n';
}