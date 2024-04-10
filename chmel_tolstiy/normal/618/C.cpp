#include <cstdio>
#include <iostream>

using namespace std;

long long x[1 << 17];
long long y[1 << 17];

long long D(int i, int j) {
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

long long S(int i, int j, int k) {
    long long x1 = x[j] - x[i];
    long long x2 = x[k] - x[i];
    long long y1 = y[j] - y[i];
    long long y2 = y[k] - y[i];
    
    return x1 * y2 == x2 * y1;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> x[i] >> y[i];
    
    long long M = D(0, 1);
    
    int a = 0;
    int b = 1;
    int c = 2;
    for (int j = 1; j < N; ++j) if (D(a, j) < M) {
        M = D(a, j);
        b = j;
    }

    for (int j = 1; j < N; ++j) M = max(M, D(a, j));
    ++M;
    
    for (int j = 1; j < N; ++j) if (j != b && D(a, j) < M && S(a, b, j) == false) {
        c = j;
        M = D(a, j);
    }
    
    cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
    
    return 0;
}