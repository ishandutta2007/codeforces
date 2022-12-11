#include<bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef pair<int, ll> pi;

const int N = 105;

ll D[N][N][N];
pi T[N][N][2];
int C[N];
ll P[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    for (int g = 0; g <= k; ++g) {
        for (int q = 0; q <= n; ++q) {
            T[g][q][0] = T[g][q][1] = pi(-1,-1);
            for (int c = 0; c <= m; ++c) {
                D[g][q][c] = -1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) cin >> C[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> P[i][j];
            if (C[i] == j) P[i][j] = 0;
        }
    }
    T[0][0][0] = pi(0,0);
    
    for (int g = 1; g <= k; ++g) {
        for (int q = 1; q <= n; ++q) {
            for (int c = 1; c <= m; ++c) {
                if (C[q] != 0 and C[q] != c) continue;
                if (D[g][q-1][c] != -1) D[g][q][c] = D[g][q-1][c] + P[q][c];
                if (T[g - 1][q -1][0].first != c and T[g - 1][q -1][0].first != -1)  {
                    ll kk = T[g - 1][q -1][0].second + P[q][c];
                    if (D[g][q][c] == -1 or D[g][q][c] > kk) D[g][q][c] = kk;
                }
                else if (T[g - 1][q -1][1].first != -1)  {
                    ll kk = T[g - 1][q -1][1].second + P[q][c];
                    if (D[g][q][c] == -1 or D[g][q][c] > kk) D[g][q][c] = kk;
                }
                if (D[g][q][c] == -1) continue;
                if (T[g][q][0].second == -1 or T[g][q][0].second > D[g][q][c]) {
                    T[g][q][1] = T[g][q][0];
                    T[g][q][0] = pi(c, D[g][q][c]);
                }
                else if (T[g][q][1].second == -1 or T[g][q][1].second > D[g][q][c]) T[g][q][1] = pi(c, D[g][q][c]);
            }
        }
    }
    ll res = -1;
    for (int i = 1; i <= m; ++i) {
        if (D[k][n][i] != -1) {
            if (res == -1 or D[k][n][i] < res) res = D[k][n][i];
        }
    }
    cout << res << endl;
}