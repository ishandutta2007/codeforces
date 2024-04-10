#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 1100;
const int INF = 1000000000;


int main() {
    int N, K;
    cin >> N >> K;
    if (N == 1) {
        if (K == 0) cout << 1 << endl; else cout << -1 << endl;
        return 0;
    }
    if (N / 2 > K) {
        cout << -1 << endl;
        return 0;
    }
    int A = N / 2, B = K - A;
    if (A == K) {
        for (int i = 1; i <= N; ++i) printf("%d ", i);
        return 0;
    }
    
    ++B;
    printf("%d %d ", B, B + B);
    for (int i = B + B + 1; i <= B + B + N - 2; ++i) printf("%d ", i);

    return 0;
}