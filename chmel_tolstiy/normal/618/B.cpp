#include <cstdio>
#include <iostream>

using namespace std;

int a[64][64];
int p[64];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) cin >> a[i][j];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) p[i] = max(p[i], a[i][j]);
    }
    for (int i = 0; i < N; ++i) if (p[i] == N - 1) {
        p[i] = N;
        break;
    }
    for (int i = 0; i < N; ++i) cout << p[i] << ' ';
    cout << endl;
    return 0;
}