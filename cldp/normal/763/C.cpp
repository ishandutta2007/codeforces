#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_set>
#include <algorithm>
using namespace std;

const int MAXN = 200010;

long long D[MAXN];
unordered_set<long long> C;
long long M, N;

long long extended_euclidean(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long res = extended_euclidean(b, a % b, y, x);
    y -= a / b * x;
    return res;
}

long long mod(long long x) {
    if (x < 0) x += abs(x / M) * M + M;
    return x % M;
}

long long modular_inverse(long long a, long long m) {
    long long x, y;
    extended_euclidean(a, m, x, y);
    return mod(x);
}

bool check(long long a, long long b) {
    unordered_set<long long> S;
    for (int i = 0; i < N; ++i) {
        if (C.find(a) == C.end()) return false;
        if (S.find(a) != S.end()) return false;
        S.insert(a);
        a = (a + b) % M;
    }
    return true;
}

int cc() {
    int N = 100000, M = 1000000007;
    int A = 679476774, B = 34990296;
    cout << M << " " << N << endl;
    for (int i = 0; i < N; ++i) {
        cout << A << " ";
        A = (A + B) % M;
    }
    cout << endl;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
   // cc();
   // return 0;
    cin >> M >> N;
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
        C.insert(D[i]);
    }
    if (N == 1) {
        cout << D[0] << " 0" << endl;
        return 0;
    }
    if (N == M) {
        cout << D[0] << " 1" << endl;
        return 0;
    }
    long long S1 = 0, S2 = 0;
    for (int i = 0; i < N; ++i) {
        S1 = mod(S1 + D[i]);
        S2 = mod(S2 + D[i] * D[i]);
    }
    long long X = 0, Y = 0;
    for (int i = 1; i < N; ++i) {
        X = (X + i) % M;
        Y = (Y + 1LL * i * i) % M;
    }
    long long Z = X * modular_inverse(N, M) % M;
    S1 = S1 * modular_inverse(N, M) % M;

    long long A = mod(mod(mod(N * Z) * Z)  - 2 * mod(X * Z) + Y);
    long long B = mod(2 * mod(X * S1) - 2 * mod(mod(N * S1) * Z));
    long long C = mod(mod(mod(N * S1) * S1) - S2);

    for (int i = 1; i < N; ++i) {
        long long b = mod(D[i] - D[0]);
        if (mod(mod(mod(A * b) * b) + mod(B * b) + C) == 0) {
            long long a = mod(S1 - Z * b);
            if (check(a, b)) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
        b = M - b;
        if (mod(mod(mod(A * b) * b) + mod(B * b) + C) == 0) {
            long long a = mod(S1 - Z * b);
            if (check(a, b)) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}