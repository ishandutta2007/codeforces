#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
using namespace std;


long long phi(long long N) {
    long long M = N, ans = N;
    for (long long i = 2; i * i <= N; ++i) {
        if (M % i != 0) continue;
        int cnt = 0;
        while (M % i == 0) {
            ++cnt;
            M /= i;
        }
        ans = ans / i * (i - 1); 
    }
    if (M > 1) ans = ans / M * (M - 1);
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    long long N, K;
    cin >> N >> K;
    while (K > 0) {
        K -= 2;
        N = phi(N);
        if (N == 1) break;
    }
    cout << N % 1000000007 << endl;
    return 0;
}