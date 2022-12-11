#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

typedef long long ll;

const ll INFt = 1e17;

ll T[2][2][2][N];
ll X[N];
ll A[N];
ll B[N];
ll C[N];
ll D[N];

ll dd(int i) {
    return D[i] + B[i]; 
}

ll de(int i) {
    return C[i] + B[i];
}

ll ed(int i) {
    return D[i] + A[i];
}

ll ee(int i) {
    return C[i] + A[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s, e;
    cin >> n >> s >> e;
    for (int i = 1; i <= n; ++i) cin >> X[i];
    for (int i = 1; i <= n; ++i) cin >> A[i];
    for (int i = 1; i <= n; ++i) cin >> B[i];
    for (int i = 1; i <= n; ++i) cin >> C[i];
    for (int i = 1; i <= n; ++i) cin >> D[i];
    X[n + 1] = X[n];
    
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= n + 1; ++j)
            for (int s1 = 0; s1 <= 1; ++s1)
                for (int s2 = 0; s2 <= 1; ++s2)
                    T[s1][s2][i][j] = INFt;
    }
    
    T[0][0][0][0] = 0;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int s1 = 0; s1 <= 1; ++s1) {
                for (int s2 = 0; s2 <= 1 - s1; ++s2) {
                    T[s1][s2][i%2][j] = INFt;
                    if (i == s) {
                        if (s1 + s2 == 0) {
                            if (i == n or j) T[s1][s2][i%2][j] = min(T[s1][s2][i%2][j], C[i] + T[s1][s2 + 1][(i - 1)%2][j]);
                            if (j) T[s1][s2][i%2][j] = min(T[s1][s2][i%2][j], D[i] + T[s1][s2 + 1][(i - 1)%2][j - 1]);
                        }
                        else if (s1) {
                            if (j or i == 1) T[s1][s2][i%2][j] = min(T[s1][s2][i%2][j], D[i] + T[s1 - 1][s2][(i - 1)%2][j]);
                            T[s1][s2][i%2][j] = min(T[s1][s2][i%2][j], C[i] + T[s1 - 1][s2][(i - 1)%2][j + 1]);
                        }
                    }
                    else if (i == e) {
                        if (s1 + s2 == 0) {
                            if (i == n or j) T[s1][s2][i%2][j] = min(T[s1][s2][i%2][j], A[i] + T[s1 + 1][s2][(i - 1)%2][j]);
                            if (j) T[s1][s2][i%2][j] = min(T[s1][s2][i%2][j], B[i] + T[s1 + 1][s2][(i - 1)%2][j - 1]);
                        }
                        else if (s2) {
                            if (j or i == 1) T[s1][s2][i%2][j] = min(T[s1][s2][i%2][j], B[i] + T[s1][s2 - 1][(i - 1)%2][j]);
                            T[s1][s2][i%2][j] = min(T[s1][s2][i%2][j], A[i] + T[s1][s2 - 1][(i - 1)%2][j + 1]);
                        }
                    }
                    else {
                        if (j > 1 or (j and (i == 1 or s1 or s2))) T[s1][s2][i%2][j] = min(T[s1][s2][i%2][j], dd(i) + T[s1][s2][(i - 1)%2][j - 1]);
                        if (i == n or j or s1 or s2) T[s1][s2][i%2][j] = min(T[s1][s2][i%2][j], ee(i) + T[s1][s2][(i - 1)%2][j + 1]);
                        if (j or s1) T[s1][s2][i%2][j] = min(T[s1][s2][i%2][j], ed(i) + T[s1][s2][(i - 1)%2][j]);
                        if (j or s2) T[s1][s2][i%2][j] = min(T[s1][s2][i%2][j], de(i) + T[s1][s2][(i - 1)%2][j]);
                    }
                    T[s1][s2][i%2][j] += ((ll)(2*j))*(X[i + 1] - X[i]);
                    if (s1 or s2) T[s1][s2][i%2][j] += (X[i + 1] - X[i]);
                    T[s1][s2][i%2][j] = min(T[s1][s2][i%2][j], INFt);
                }
            }
        }
    }
    cout << T[0][0][n%2][0] << '\n';
}